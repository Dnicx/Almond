
#include <Almond.h>

class ExampleLayer : public Almond::Layer
{

	public:

		ExampleLayer():
				Layer( "ExLayer" )
		{

		}

		void OnUpdate() override
		{
			ALMOND_CLIENT_TRACE("{0} update", m_DebugName);
		}

		void OnEvent( Almond::Event& event ) override
		{
			ALMOND_CLIENT_TRACE("{0} on event {1}", m_DebugName, event);
		}

};

class UniverseApp : public Almond::Application
{

	public:
		UniverseApp()
		{
			PushLayer( new ExampleLayer() );
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
