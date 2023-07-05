#pragma once

#include "Tulip.h"


class Sandbox2D : public Tulip::Layer
{
public:
    Sandbox2D();
    virtual ~Sandbox2D() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void OnUpdate(Tulip::Timestep ts) override;
    virtual void OnImGuiRender() override;
    void OnEvent(Tulip::Event& e) override;
private:
    Tulip::OrthographicCameraController m_CameraController;

    // Temp
    Tulip::Ref<Tulip::VertexArray> m_SquareVA;
    Tulip::Ref<Tulip::Shader> m_FlatColorShader;

    Tulip::Ref<Tulip::Texture2D> m_CheckerboardTexture;

    glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};