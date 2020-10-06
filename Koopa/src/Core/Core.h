#pragma once

#ifdef KP_PLATFORM_WINDOWS
	#ifdef KP_BUILD_DLL
		#define KOOPA_API __declspec(dllexport)
	#else
		#define KOOPA_API __declspec(dllimport)
	#endif
#else
	#error Koopa only supports Windows!
#endif

#ifdef KP_DEBUG
	#define KP_ENABLE_ASSERTS 
#endif

#ifdef KP_ENABLE_ASSERTS
	#define KP_ASSERT(x, ...) { if(!(x)) { KOOPA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define KP_CORE_ASSERT(x, ...) { if(!(x)) { KP_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define KP_ASSERT(x, ...)
	#define KP_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define KP_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)