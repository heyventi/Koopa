#pragma once

#include "Koopa/Core/Base.h"
#include "Koopa/Core/Log.h"
#include <filesystem>

#ifdef KP_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define KP_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { KP##type##ERROR(msg, __VA_ARGS__); KP_DEBUGBREAK(); } }
#define KP_INTERNAL_ASSERT_WITH_MSG(type, check, ...) KP_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define KP_INTERNAL_ASSERT_NO_MSG(type, check) KP_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", KP_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define KP_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define KP_INTERNAL_ASSERT_GET_MACRO(...) KP_EXPAND_MACRO( KP_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, KP_INTERNAL_ASSERT_WITH_MSG, KP_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define KP_ASSERT(...) KP_EXPAND_MACRO( KP_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define KP_CORE_ASSERT(...) KP_EXPAND_MACRO( KP_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define KP_ASSERT(...)
#define KP_CORE_ASSERT(...)
#endif
