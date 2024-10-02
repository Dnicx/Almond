#include "aepch.h"

#include "Application.h"
#include "CodeTimer.h"

// test
#include "Almond/Events/ApplicationEvent.h"
#include "Almond/Log.h"

namespace Almond {

	Application::Application()
	{
		countTimeee();
	}

	Application::~Application()
	{

	}

	void Application::Update()
	{
		std::cerr << "update not define" << std::endl;
	}

	void Application::run() 
	{

		WindowResizeEvent windowResize( 540, 270 );

		ALMOND_CORE_TRACE( "from main app");

		if ( windowResize.IsInCategory( EventCategoryApplication ))
			ALMOND_CORE_TRACE( windowResize );

		if ( windowResize.IsInCategory( EventCategoryInput ))
			ALMOND_CORE_TRACE( windowResize );

		while (true)
		{
			
			
			// this->Update();

		}
	}

}