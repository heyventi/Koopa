#pragma once

#include "Koopa.h"

class Sandbox2D : public kp::Layer
{
public:
    Sandbox2D();
    virtual ~Sandbox2D() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void OnUpdate(kp::Timestep ts) override;
    virtual void OnImGuiRender() override;
    void OnEvent(kp::Event& e) override;

private:
    kp::OrthographicCameraController m_CameraController;

    // Temp
    kp::Ref<kp::VertexArray> m_SquareVA;
    kp::Ref<kp::Shader> m_FlatColorShader;
        
    kp::Ref<kp::Texture2D> m_CheckerboardTexture;

    struct ProfileResult
    {
        const char* Name;
        float Time;
    };

    std::vector<ProfileResult> m_ProfileResults;

    glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

};