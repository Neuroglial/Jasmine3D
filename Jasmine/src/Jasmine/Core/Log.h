#pragma once

#include "Jasmine/Core/Base.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

#include <glm/glm.hpp>

namespace Jasmine {

	class Log
	{
	public:
		static void Init();
		static void Shutdown();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

template<typename OStream>
OStream& operator<<(OStream& os, const glm::vec3& vec)
{
	return os << '(' << vec.x << ", " << vec.y << ", " << vec.z << ')';
}

template<typename OStream>
OStream& operator<<(OStream& os, const glm::vec4& vec)
{
	return os << '(' << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ')';
}

// Core Logging Macros
#define JM_CORE_TRACE(...)	Jasmine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define JM_CORE_INFO(...)	Jasmine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define JM_CORE_WARN(...)	Jasmine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define JM_CORE_ERROR(...)	Jasmine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define JM_CORE_FATAL(...)	Jasmine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Logging Macros
#define JM_TRACE(...)	Jasmine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define JM_INFO(...)	Jasmine::Log::GetClientLogger()->info(__VA_ARGS__)
#define JM_WARN(...)	Jasmine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JM_ERROR(...)	Jasmine::Log::GetClientLogger()->error(__VA_ARGS__)
#define JM_FATAL(...)	Jasmine::Log::GetClientLogger()->critical(__VA_ARGS__)