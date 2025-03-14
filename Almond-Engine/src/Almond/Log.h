#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Almond
{
	class ALMOND_API Log
	{
		public:
			static void Init();

			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger ; };


		private:

			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}

#define ALMOND_CORE_TRACE(...) 			::Almond::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ALMOND_CORE_INFO(...) 			::Almond::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ALMOND_CORE_WARN(...) 			::Almond::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ALMOND_CORE_ERROR(...) 			::Almond::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ALMOND_CORE_CRITICAL(...) 		::Almond::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define ALMOND_CLIENT_TRACE(...) 		::Almond::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ALMOND_CLIENT_INFO(...) 		::Almond::Log::GetClientLogger()->info(__VA_ARGS__)
#define ALMOND_CLIENT_WARN(...) 		::Almond::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ALMOND_CLIENT_ERROR(...) 		::Almond::Log::GetClientLogger()->error(__VA_ARGS__)
#define ALMOND_CLIENT_CRITICAL(...) 	::Almond::Log::GetClientLogger()->critical(__VA_ARGS__)

// #define ALMOND_CORE_TRACE
// #define ALMOND_CORE_WARN