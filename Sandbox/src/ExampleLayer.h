#pragma once

#include "Tulip.h"


class ExampleLayer : public Tulip::Layer
{
public:
    ExampleLayer();
    virtual ~ExampleLayer() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void OnUpdate(Tulip::Timestep ts) override;
    virtual void OnImGuiRender() override;
    void OnEvent(Tulip::Event& e) override;
   
private:
    Tulip::ShaderLibrary m_ShaderLibrary;
    Tulip::Ref<Tulip::Shader> m_Shader;
    Tulip::Ref<Tulip::VertexArray> m_VertexArray;

    Tulip::Ref<Tulip::Shader> m_FlatColorShader, m_TextureShader;
    Tulip::Ref<Tulip::VertexArray> m_SquareVA;

    Tulip::Ref<Tulip::Texture2D> m_Texture;

    Tulip::OrthographicCameraController m_CameraController;

    glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};