#pragma once

#include "core.h"

#include "Events/Event.h"

#include "Window.h"

#include "Events/ApplicationEvent.h"


namespace Almond {

	class ALMOND_API Application
	{

		public:

			Application();
			virtual ~Application();

			virtual void Update();

			void Run();

			void OnEvent( Event& event );

		private:

			bool OnWindowClose( WindowCloseEvent& event );
			bool OnWindowResize( WindowResizeEvent& event );

			std::unique_ptr< Window > m_Window;
			bool m_Running = false;

	};
		
	Application* CreateApplication();
}