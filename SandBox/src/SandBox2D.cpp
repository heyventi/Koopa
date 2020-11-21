#include "Sandbox2D.h"

#include "imgui.h"
#include "ExampleLayer.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Platform/OpenGL/OpenGLShader.h"

Sandbox2D::Sandbox2D()
    : Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f), m_SquareColor({ 0.2f, 0.3f, 0.8f, 1.0f })
{
}

void Sandbox2D::OnAttach()
{
    m_CheckerboardTexture = kp::Texture2D::Create("assets/textures/Checkerboard.png");
    m_SpriteSheet = kp::Texture2D::Create("assets/game/textures/RPGpack_sheet_2X.png");

    m_TextureStairs = kp::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 7, 6 }, { 128,128 }); 
    m_TextureBarrel = kp::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 8, 2 }, { 128,128 }); 
    m_TextureTree = kp::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 2, 1 }, { 128,128 }, { 1, 2 });

    m_FlatColorShader = kp::Shader::Create("assets/shaders/FlatColor.glsl");

    m_CameraController.SetZoomLevel(5.0f);
}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(kp::Timestep ts)
{
    // Update
    KP_PROFILE_FUNCTION();
    {
        KP_PROFILE_SCOPE("CameraController::OnUpdate");
        m_CameraController.OnUpdate(ts);
    }

    kp::Renderer2D::ResetStats();

    // Render
    {
        KP_PROFILE_SCOPE("Renderer Prep");
        kp::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
        kp::RenderCommand::Clear();
    }

#if 0 
    {
        static float rotation = 0.0f;
        rotation += ts * 50.0f;

        KP_PROFILE_SCOPE("Renderer Draw");
        kp::Renderer2D::BeginScene(m_CameraController.GetCamera());
        kp::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
        kp::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
        kp::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_SquareColor);
        kp::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture, 10.0f);
        kp::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_CheckerboardTexture, 20.0f);
        kp::Renderer2D::EndScene();

        kp::Renderer2D::BeginScene(m_CameraController.GetCamera());
        for (float y = -5.0f; y < 5.0f; y += 0.5f)
        {
            for (float x = -5.0f; x < 5.0f; x += 0.5f)
            {
                glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
                kp::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
            }
        }
        kp::Renderer2D::EndScene();
    }
#endif
	kp::Renderer2D::BeginScene(m_CameraController.GetCamera());
    kp::Renderer2D::DrawQuad({ 0.0f, 0.0f, 0.5f }, { 1.0f, 1.0f }, m_TextureStairs);
    kp::Renderer2D::DrawQuad({ 1.0f, 0.0f, 0.5f }, { 1.0f, 1.0f }, m_TextureBarrel);
    kp::Renderer2D::DrawQuad({ -1.0f, 0.0f, 0.5f }, { 1.0f, 2.0f }, m_TextureTree);
    kp::Renderer2D::EndScene();
}

void Sandbox2D::OnImGuiRender()
{
    KP_PROFILE_FUNCTION();

    ImGui::Begin("Settings");

    auto stats = kp::Renderer2D::GetStats();
    ImGui::Text("Renderer2D Stats:");
    ImGui::Text("Draw Calls: %d", stats.DrawCalls);
    ImGui::Text("Quads: %d", stats.QuadCount);
    ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
    ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

    ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

    ImGui::End();
}

void Sandbox2D::OnEvent(kp::Event& e)
{
    m_CameraController.OnEvent(e);
}