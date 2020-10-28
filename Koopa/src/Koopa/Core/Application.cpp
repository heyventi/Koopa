#include "kppch.h"
#include "Application.h"

#include "Koopa/Events/ApplicationEvent.h"
#include "Log.h"

#include <glad/glad.h>
#include "Koopa/Renderer/Renderer.h"
#include <glfw/glfw3.h>

namespace kp {

	Application* Application::s_Instance = nullptr;
	
	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case kp::ShaderDataType::Float:    return GL_FLOAT;
		case kp::ShaderDataType::Float2:   return GL_FLOAT;
		case kp::ShaderDataType::Float3:   return GL_FLOAT;
		case kp::ShaderDataType::Float4:   return GL_FLOAT;
		case kp::ShaderDataType::Mat3:     return GL_FLOAT;
		case kp::ShaderDataType::Mat4:     return GL_FLOAT;
		case kp::ShaderDataType::Int:      return GL_INT;
		case kp::ShaderDataType::Int2:     return GL_INT;
		case kp::ShaderDataType::Int3:     return GL_INT;
		case kp::ShaderDataType::Int4:     return GL_INT;
		case kp::ShaderDataType::Bool:     return GL_BOOL;
		}

		KP_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	Application::Application()
	{
		KP_CORE_ASSERT(!s_Instance, "Application already exits!");

		s_Instance = this;
        m_Window = Window::Create();
        m_Window->SetEventCallback(KP_BIND_EVENT_FN(Application::OnEvent));

		Renderer::Init();

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

    Application::~Application()
    {
        Renderer::Shutdown();
    }

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(KP_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(KP_BIND_EVENT_FN(Application::OnWindowResize));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
			{
				break;
			}
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	void Application::Run()
	{
		while (m_Running)
		{
			float time = (float)glfwGetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			if (!m_Minimized)
			{
				for (Layer* layer : m_LayerStack)
					layer->OnUpdate(timestep);
			}

			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
			{
				layer->OnImGuiRender();
			}
			m_ImGuiLayer->End();

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;
		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		return false;
	}
}