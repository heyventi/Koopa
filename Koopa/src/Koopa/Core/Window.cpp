#include "kppch.h"
#include "Koopa/Core/Window.h"

#ifdef KP_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace kp
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef KP_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		KP_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}