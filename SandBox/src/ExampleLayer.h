#pragma once

#include "Koopa.h"

class ExampleLayer : public kp::Layer
{
public:
    ExampleLayer();
    virtual ~ExampleLayer() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void OnUpdate(kp::Timestep ts) override;
    virtual void OnImGuiRender() override;
    void OnEvent(kp::Event& e) override;

private:
    kp::ShaderLibrary m_ShaderLibrary;
    kp::Ref<kp::Shader> m_Shader;
    kp::Ref<kp::VertexArray> m_VertexArray;

    kp::Ref<kp::Shader> m_FlatColorShader;
    kp::Ref<kp::VertexArray> m_SquareVA;

    kp::Ref<kp::Texture2D> m_Texture, m_KoopaLogoTexture;

    kp::OrthographicCameraController m_CameraController;
    glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};