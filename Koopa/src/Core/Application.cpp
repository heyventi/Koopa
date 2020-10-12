#include "kppch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

#include <glad/glad.h>
#include "Core/Renderer/Renderer.h"

namespace kp {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
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
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

		m_VertexArray.reset(VertexArray::Create());

		float vertices[3*7] =
		{
            -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
             0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
             0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

        std::shared_ptr<VertexBuffer> vertexBuffer;
		vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

		{
			BufferLayout layout = {
				{ ShaderDataType::Float3, "a_Position"},
				{ ShaderDataType::Float4, "a_Color"}
			};

			vertexBuffer->SetLayout(layout);
		}
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		std::shared_ptr<IndexBuffer> indexBuffer;
		indexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		std::string vertexSrc = R"(
            #version 330 core
            
            layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

            out vec3 v_Position;
			out vec4 v_Color;

            void main()
            {
                v_Position = a_Position;
				v_Color = a_Color;
                gl_Position = vec4(a_Position, 1.0);    
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

		m_Shader.reset(new Shader(vertexSrc, fragmentSrc));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

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
            RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
            RenderCommand::Clear();

            Renderer::BeginScene();

			m_Shader->Bind();
			m_VertexArray->Bind();
			Renderer::Submit(m_VertexArray);

			Renderer::EndScene();

			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
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

}