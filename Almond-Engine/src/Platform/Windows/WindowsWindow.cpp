#include "aepch.h"
#include "WindowsWindow.h"

#include "Almond/Events/ApplicationEvent.h"
#include "Almond/Events/KeyEvent.h"
#include "Almond/Events/MouseEvent.h"

#include <glad/glad.h>

namespace Almond
{
	static bool s_GlfwInitialized = false;

	static void GlfwErrorCallbackFunc( int error_code, const char *description )
	{
		ALMOND_CORE_ERROR( "GLFW error ({0}) : {1}", error_code, description );
	}

	Window* Window::Create( const WindowProps& props )
	{
		return new WindowsWindow( props );
	}

	WindowsWindow::WindowsWindow( const WindowProps& props )
	{
		Init( props );
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}
	
	void WindowsWindow::Init( const WindowProps& props )
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		ALMOND_CORE_INFO( "Creating window {0} ( {1} {2} )", m_Data.Title, m_Data.Width, m_Data.Height );

		if ( !s_GlfwInitialized )
		{
			int success = glfwInit();
			ALMOND_CORE_ASSERT( success, "Fail to initialize glfw" );

			glfwSetErrorCallback( GlfwErrorCallbackFunc );
			s_GlfwInitialized = true;
		}

		m_Window = glfwCreateWindow( (int) m_Data.Width, 
									(int) m_Data.Height, 
									m_Data.Title.c_str(), 
									nullptr, 
									nullptr );

		glfwMakeContextCurrent( m_Window );

		int status = gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress );
		ALMOND_CORE_ASSERT( status, "Failed to init GLAD!!") ;
		// associate m_data to the window
		glfwSetWindowUserPointer( m_Window, &m_Data );

		glfwSetErrorCallback( GlfwErrorCallbackFunc );

		// define as true for now
		SetVSync( true );

		// set callback to a lambda func
		glfwSetWindowCloseCallback( m_Window, [](GLFWwindow* window)
		{
			// get data we associate earlier ( at set window user pointer )
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);
		});

		// Set GLFW callbacks
		glfwSetWindowSizeCallback( m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;
			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});

		glfwSetKeyCallback( m_Window, []( GLFWwindow* window, int key, int scancode, int action, int mods )
		{
			WindowData& data = *(WindowData* )glfwGetWindowUserPointer( window );
			
			switch( action )
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event( key, 0 );
					data.EventCallback( event );
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event( key );
					data.EventCallback( event );
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event( key, 1 );
					data.EventCallback( event );
					break;
				}
			}

		});

		glfwSetMouseButtonCallback( m_Window, []( GLFWwindow* window, int button, int action, int mods )
		{
			WindowData& data = *(WindowData* )glfwGetWindowUserPointer( window );

			switch( action )
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event( button );
					data.EventCallback( event );
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event( button );
					data.EventCallback( event );
					break;
				}
			}
		});

		glfwSetScrollCallback( m_Window, []( GLFWwindow* window, double xoffset, double yoffset  )
		{
			WindowData& data = *(WindowData* )glfwGetWindowUserPointer( window );

			MouseScrolledEvent event( (float) xoffset, (float) yoffset );
			data.EventCallback( event );
		});

		glfwSetCursorPosCallback( m_Window, []( GLFWwindow* window, double xpos, double ypos )
		{
			WindowData& data = *(WindowData* )glfwGetWindowUserPointer( window );

			MouseMovedEvent event( (float) xpos, (float) ypos );
			data.EventCallback( event ); 
		});
		
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers( m_Window );
	}

	void WindowsWindow::SetVSync( bool enableVsync )
	{
		if ( enableVsync )
			glfwSwapInterval( 1 );
		else
			glfwSwapInterval( 0 );

		m_Data.VSync = enableVsync;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow( m_Window );
	}
}