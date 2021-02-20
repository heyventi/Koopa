#pragma once

#include <memory>

#include "Koopa/Core/PlatformDetection.h"

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

#define KP_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace kp {

    template<typename T>
    using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

    template<typename T>
    using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}