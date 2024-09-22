#pragma once

#ifdef ALMND_PLATFORM_WINDOWS

extern Almond::Application* Almond::CreateApplication();

int main(int argc, char** argv)
{

	int a = 10;
	Almond::Log::Init();
	ALMOND_CORE_WARN("Init core logger");
	ALMOND_CORE_INFO("Init client logger var={0}", a);

	auto app = Almond::CreateApplication();
	app->run();
	delete app;
}

#endif