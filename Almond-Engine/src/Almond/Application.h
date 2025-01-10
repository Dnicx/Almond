#pragma once

#include "core.h"

#include "Events/Event.h"

#include "Window.h"

#include "Events/ApplicationEvent.h"

#include "Layer.h"
#include "LayerStack.h"


namespace Almond {

	class ALMOND_API Application
	{

		public:

			Application();
			virtual ~Application();

			virtual void Update();

			void Run();

			void OnEvent( Event& event );

			void PushLayer( Layer* layer );
			void PushOverlay( Layer* layer );

		private:

			bool OnWindowClose( WindowCloseEvent& event );
			bool OnWindowResize( WindowResizeEvent& event );

			std::unique_ptr< Window > m_Window;
			bool m_Running = false;

			LayerStack m_LayerStack;

	};
		
	Application* CreateApplication();
}