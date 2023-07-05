#include "Tulip.h"

#include "ExampleLayer.h"

#include <imgui/imgui.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


ExampleLayer::ExampleLayer()
        : Layer("ExampleLayer"), m_CameraController(1280.0f / 720.0f, true)
    {
        m_VertexArray = Tulip::VertexArray::Create();

        float vertices[3 * 3] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
        };

        Tulip::Ref<Tulip::VertexBuffer> vertexBuffer = Tulip::VertexBuffer::Create(vertices, sizeof(vertices));
        Tulip::BufferLayout layout = {
            { Tulip::ShaderDataType::Float3, "a_Position" },
            { Tulip::ShaderDataType::Float4, "a_Color" }
        };

        vertexBuffer->SetLayout(layout);
        m_VertexArray->AddVertexBuffer(vertexBuffer);

        uint32_t indices[3] = { 0, 1, 2 };
        Tulip::Ref<Tulip::IndexBuffer> indexBuffer = Tulip::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
        m_VertexArray->SetIndexBuffer(indexBuffer);

        m_SquareVA = Tulip::VertexArray::Create();

        float squareVertices[5 * 4] = {
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
            0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
            -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
        };

        Tulip::Ref<Tulip::VertexBuffer> squareVB = Tulip::VertexBuffer::Create(squareVertices, sizeof(squareVertices));
        squareVB->SetLayout({
            { Tulip::ShaderDataType::Float3, "a_Position" },
            { Tulip::ShaderDataType::Float2, "a_TexCoord" }
            });
        m_SquareVA->AddVertexBuffer(squareVB);

        uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
        Tulip::Ref<Tulip::IndexBuffer> squareIB = Tulip::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));
        m_SquareVA->SetIndexBuffer(squareIB);


        std::string vertexSrc = R"(
            #version 330 core
            
            layout(location = 0) in vec3 a_Position;
            layout(location = 1) in vec4 a_Color;

            uniform mat4 u_ViewProjection;
            uniform mat4 u_Transform;

            out vec3 v_Position;
            out vec4 v_Color;

            void main()
            {
                v_Position = a_Position;
                v_Color = a_Color;
                gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
            }
        )";

        std::string fragmentSrc = R"(
            #version 330 core
            
            layout(location = 0) out vec4 color;
            in vec3 v_Position;
            in vec4 v_Color;

            void main()
            {
                color = vec4(v_Position * 0.5 + 0.5, 1.0);
                color = v_Color;
            }
        )";

        m_Shader = Tulip::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);

        std::string flatColorShaderVertexSrc = R"(
            #version 330 core
            
            layout(location = 0) in vec3 a_Position;

            uniform mat4 u_ViewProjection;
            uniform mat4 u_Transform;

            out vec3 v_Position;

            void main()
            {
                v_Position = a_Position;
                gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
            }
        )";


        std::string flatColorShaderFragmentSrc = R"(
            #version 330 core
            
            layout(location = 0) out vec4 color;
            in vec3 v_Position;

            uniform vec3 u_Color;

            void main()
            {
                color = vec4(u_Color, 1.0);
            }
        )";

        m_FlatColorShader = Tulip::Shader::Create("FlatColor", flatColorShaderVertexSrc, flatColorShaderFragmentSrc);

        auto TextureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

        m_Texture = Tulip::Texture2D::Create("assets/textures/Checkerboard.png");

        TextureShader->Bind();
        TextureShader->SetInt("u_Texture", 0);
    }

    void ExampleLayer::OnAttach()
    {
    }

    void ExampleLayer::OnDetach()
    {
    }


    void ExampleLayer::OnUpdate(Tulip::Timestep ts)
    {
        TULIP_PROFILE_FUNCTION();
        // Update
        {
            TULIP_PROFILE_SCOPE("CameraController::OnUpdate");
            m_CameraController.OnUpdate(ts);
        }

        // Render
        Tulip::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
        Tulip::RenderCommand::Clear();

        Tulip::Renderer::BeginScene(m_CameraController.GetCamera());

        glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

        m_FlatColorShader->Bind();
        m_FlatColorShader->SetFloat3("u_Color", m_SquareColor);

        for (int y = 0; y < 20; y++)
        {
            for (int x = 0; x < 20; x++)
            {
                glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
                glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
                Tulip::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
            }
        }

        auto TextureShader = m_ShaderLibrary.Get("Texture");
        m_Texture->Bind();
        Tulip::Renderer::Submit(TextureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

        Tulip::Renderer::EndScene();
    }

    void ExampleLayer::OnImGuiRender()
    {
        TULIP_PROFILE_FUNCTION();
        ImGui::Begin("Settings");
        ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
        ImGui::End();
    }

    void ExampleLayer::OnEvent(Tulip::Event& e)
    {
        m_CameraController.OnEvent(e);
    }

