#pragma once

#include "core.h"

namespace Almond {

	class ALMOND_API Application
	{

		public:

			Application();
			virtual ~Application();

			void run();

	};
		
	Application* CreateApplication();
}