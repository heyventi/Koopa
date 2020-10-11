
#include "kppch.h"
#include <Koopa.h>

class ExampleLayer : public kp::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{}

	void OnUpdate() override
	{
		if (kp::Input::IsKeyPressed(KP_KEY_TAB))
			KOOPA_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(kp::Event& event) override
	{
		if (event.GetEventType() == kp::EventType::KeyPressed)
		{
			kp::KeyPressedEvent& e = (kp::KeyPressedEvent&)event;
			if (e.GetKeyCode() == KP_KEY_TAB)
				KOOPA_TRACE("Tab key is pressed (event)!");
			KOOPA_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public kp::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

kp::Application* kp::CreateApplication()
{
	return new Sandbox();
}