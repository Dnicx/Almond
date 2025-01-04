#include "aepch.h"

#include "Application.h"
#include "CodeTimer.h"

// test
#include "Almond/Log.h"

#include <GLFW/glfw3.h>

namespace Almond {

#define	BIND_EVENT_FN( event_fn ) std::bind( &Application::event_fn, this, std::placeholders::_1 )

	Application::Application()
	{
		countTimeee();
		m_Window = std::unique_ptr< Window >( Window::Create());

		// bind all EventCallback to OnEvent
		m_Window->SetEventCallback( BIND_EVENT_FN( OnEvent ) );
	}

	Application::~Application()
	{

	}

	void Application::OnEvent( Event& event )
	{
		EventDispatcher dispatcher( event );

		// dispatch event to corresponding evnet handler
		// if event in dispatcher match "WindowCloseEvent", it will call Application::OnWindowClose
		dispatcher.Dispatch<WindowCloseEvent>( BIND_EVENT_FN( OnWindowClose ) );
		dispatcher.Dispatch<WindowResizeEvent>( BIND_EVENT_FN( OnWindowResize ) );

		ALMOND_CORE_INFO( "OnEvent::{0}", event );
	}

	bool Application::OnWindowClose( WindowCloseEvent& event )
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize( WindowResizeEvent& event )
	{
		ALMOND_CORE_INFO( "Handle Window resize!!");	
		return true;
	}

	void Application::Update()
	{
		std::cerr << "update not define" << std::endl;
	}

	void Application::Run() 
	{

		m_Running = true;

		WindowResizeEvent windowResize( 540, 270 );

		ALMOND_CORE_TRACE( "from main app");

		if ( windowResize.IsInCategory( EventCategoryApplication ))
			ALMOND_CORE_TRACE( windowResize );

		if ( windowResize.IsInCategory( EventCategoryInput ))
			ALMOND_CORE_TRACE( windowResize );

		glClearColor( 0.5, 0, 0.5, 1 );

		while ( m_Running )
		{
			
			m_Window->OnUpdate();
			glClear( GL_COLOR_BUFFER_BIT );

			// this->Update();

		}
	}

}