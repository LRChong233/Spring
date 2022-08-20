#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Spring {

	class SPRING_API Log
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
#define SP_CORE_TRACE(...)    ::Spring::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SP_CORE_INFO(...)     ::Spring::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SP_CORE_WARN(...)     ::Spring::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SP_CORE_ERROR(...)    ::Spring::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SP_CORE_FATAL(...)    ::Spring::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define SP_TRACE(...)         ::Spring::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SP_INFO(...)          ::Spring::Log::GetClientLogger()->info(__VA_ARGS__)
#define SP_WARN(...)          ::Spring::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SP_ERROR(...)         ::Spring::Log::GetClientLogger()->error(__VA_ARGS__)
#define SP_FATAL(...)         ::Spring::Log::GetClientLogger()->fatal(__VA_ARGS__)

