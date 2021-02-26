#pragma once

#ifdef KP_PLATFORM_WINDOWS

extern class kp::Application* kp::CreateApplication();

int main(int argc, char** argv)
{
	kp::Log::Init();
    
    KP_PROFILE_BEGIN_SESSION("Startup", "KoopaProfile-Startup.json");
    auto app = kp::CreateApplication();
    KP_PROFILE_END_SESSION();

    KP_PROFILE_BEGIN_SESSION("Runtime", "KoopaProfile-Runtime.json");
    app->Run();
    KP_PROFILE_END_SESSION();

    KP_PROFILE_BEGIN_SESSION("Shutdown", "KoopaProfile-Shutdown.json");
    delete app;
    KP_PROFILE_END_SESSION();
}

#endif