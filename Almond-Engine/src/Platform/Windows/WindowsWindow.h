#pragma once

#include "Almond/Window.h"

#include "GLFW/glfw3.h"

namespace Almond
{

	class WindowsWindow: public Window
	{
		public:

			WindowsWindow( const WindowProps& windowProps );
			virtual ~WindowsWindow();

			void OnUpdate() override;

			inline unsigned int GetWidth() const override { return m_Data.Width; }
			inline unsigned int GetHeight() const override { return m_Data.Height; }

			inline void SetEventCallback( const EventCallbackFunc& callback ) override { m_Data.EventCallback = callback; }
			inline void SetVSync( bool isEnable ) override;
			inline bool IsVSync() const override;

		private:

			virtual void Init( const WindowProps& props );
			virtual void Shutdown();

			GLFWwindow* m_Window;

			struct WindowData
			{
				std::string Title;
				unsigned int Width, Height;
				bool VSync;

				EventCallbackFunc EventCallback;
			};

			WindowData m_Data;
			
	};

}