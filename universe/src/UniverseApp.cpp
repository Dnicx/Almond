
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

};

Almond::Application* Almond::CreateApplication()
{
	return new UniverseApp();
}
