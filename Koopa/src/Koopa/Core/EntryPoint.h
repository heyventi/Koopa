#pragma once

#ifdef KP_PLATFORM_WINDOWS

extern class kp::Application* kp::CreateApplication();

int main(int argc, char** argv)
{
	kp::Log::Init();
	KP_CORE_WARN("Initialized Log!");
	int a = 5;
	KOOPA_INFO("Hello! Var={0}", a);

	auto app = kp::CreateApplication();
	app->Run();
	delete app;
}

#endif