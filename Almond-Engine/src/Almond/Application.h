#pragma once

#include "core.h"

namespace Almond {

	class ALMOND_API Application
	{

		public:

			Application();
			virtual ~Application();

			virtual void Update();

			void run();

	};
		
	Application* CreateApplication();
}