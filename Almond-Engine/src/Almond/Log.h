#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Almond
{
	class ALMOND_API Log
	{
		public:
			static void Init();

			inline static std::shared_ptr<spdlog::loggger>& GetCoreLogger() { return s_CoreLogger };
			inline static std::shared_ptr<spdlog::loggger>& GetCoreLogger() { return s_ClientLogger };


		private:

			std::shared_ptr<spdlog::logger> s_CoreLogger;
			std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}

