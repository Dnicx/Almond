#pragma once

#include "core.h"

#include "Events/Event.h"

#include "Window.h"

namespace Almond {

	class ALMOND_API Application
	{

		public:

			Application();
			virtual ~Application();

			virtual void Update();

			void Run();

		private:

			std::unique_ptr< Window > m_Window;
			bool m_Running = false;

	};
		
	Application* CreateApplication();
}