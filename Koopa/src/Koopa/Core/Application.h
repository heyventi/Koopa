#pragma once

#include "Koopa/Core/Base.h"

#include "Koopa/Core/Window.h"
#include "Koopa/Events/Event.h"
#include "Koopa/Events/ApplicationEvent.h"

#include "Koopa/Core/LayerStack.h"
#include "Koopa/ImGui/ImGuiLayer.h"

#include "Koopa/Renderer/OrthographicCamera.h"

int main(int argc, char** argv);

namespace kp {

	class Application
	{
	public:
		Application(const std::string& name = "Koopa App");
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }
		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		static Application& Get() { return *s_Instance; }

	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer = nullptr;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;

	private:
		float m_LastFrameTime = 0.0f;

	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}