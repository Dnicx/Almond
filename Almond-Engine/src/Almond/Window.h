#pragma once

#include "aepch.h"

#include "Almond/Core.h"
#include "Almond/Events/Event.h"

namespace Almond
{

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps( const std::string title = "Almond engine",
						unsigned int width = 1280,
						unsigned int height = 720 )
			: Title( title ), Width( width ), Height( height ) {}
	};

	// Interface representing desktop system based on Window
	class ALMOND_API Window
	{
		public:
			using EventCallbackFunc = std::function< void ( Event& ) >;

			virtual ~Window() {}

			virtual void OnUpdate() = 0;

			virtual unsigned int GetWidth() const = 0;
			virtual unsigned int GetHeight() const = 0;

			// window attr
			virtual void SetEventCallback( const EventCallbackFunc& callback ) = 0;
			virtual void SetVSync( bool isEnable ) = 0;
			virtual bool IsVSync() const = 0;

			static Window* Create( const WindowProps& props = WindowProps() );
	};
}