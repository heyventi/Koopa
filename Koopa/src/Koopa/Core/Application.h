#pragma once

#include "Koopa/Core/Core.h"

#include "Koopa/Core/Window.h"
#include "Koopa/Events/Event.h"
#include "Koopa/Events/ApplicationEvent.h"

#include "Koopa/Core/LayerStack.h"
#include "Koopa/ImGui/ImGuiLayer.h"

#include "Koopa/Renderer/OrthographicCamera.h"

namespace kp {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer = nullptr;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;

	private:
		float m_LastFrameTime = 0.0f;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}