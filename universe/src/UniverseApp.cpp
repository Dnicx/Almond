
#include <Almond.h>

class UniverseApp : public Almond::Application
{
	public:
		UniverseApp()
		{

		}

		~UniverseApp()
		{

		}

		void Update()
		{
			ALMOND_CLIENT_TRACE("hello from app ");
		}


};

Almond::Application* Almond::CreateApplication()
{
	return new UniverseApp();
}
