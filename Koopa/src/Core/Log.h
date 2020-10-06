#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace kp {

	class KOOPA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define KP_CORE_TRACE(...)    ::kp::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KP_CORE_INFO(...)     ::kp::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KP_CORE_WARN(...)     ::kp::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KP_CORE_ERROR(...)    ::kp::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KP_CORE_FATAL(...)    ::kp::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define KOOPA_TRACE(...)	  ::kp::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KOOPA_INFO(...)	      ::kp::Log::GetClientLogger()->info(__VA_ARGS__)
#define KOOPA_WARN(...)	      ::kp::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KOOPA_ERROR(...)	  ::kp::Log::GetClientLogger()->error(__VA_ARGS__)
#define KOOPA_FATAL(...)	  ::kp::Log::GetClientLogger()->fatal(__VA_ARGS__)