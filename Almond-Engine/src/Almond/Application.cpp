#include "aepch.h"

#include "Application.h"
#include "CodeTimer.h"

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
		while (true)
		{

			this->Update();

		}
	}

}