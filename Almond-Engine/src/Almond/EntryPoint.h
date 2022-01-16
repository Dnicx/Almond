#pragma once

#ifdef ALMND_PLATFORM_WINDOWS

extern Almond::Application* Almond::CreateApplication();

void main(int argc, char** argv)
{
	std::cout << "hello" << std::endl;
	auto app = Almond::CreateApplication();
	app->run();
	delete app;
}

#endif