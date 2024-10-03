#include "aepch.h"

#include "Application.h"
#include "CodeTimer.h"

// test
#include "Almond/Events/ApplicationEvent.h"
#include "Almond/Log.h"

#include <GLFW/glfw3.h>

namespace Almond {

	Application::Application()
	{
		countTimeee();
		m_Window = std::unique_ptr< Window >( Window::Create());
	}

	Application::~Application()
	{

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