#pragma once

#include "Almond/Core.h"
#include "aepch.h"

namespace Almond
{

	enum class EventType
	{
		None = 0,
		
		// Window Event
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMove,

		// Application
		AppTick, AppUpdate, AppRender,

		//	Keybaord
		KeyPressed, KeyReleased,

		// mouse event
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication		= 1<<0 ,
		EventCategoryInput				= 1<<1 ,
		EventCategoryKeyboard			= 1<<2 ,
		EventCategoryMouse				= 1<<3 ,
		EventCategoryMouseButton		= 1<<4 
	};

	// ##type combine "type" token with "EventType::" token so it's something like EventType::WindowClose if type is WindowClose 
	#define EVENT_CLASS_TYPE(type) \
		static EventType GetStaticType() { return EventType::##type; }\
		virtual EventType GetEventType() const override { return GetStaticType(); }\
		virtual const char* GetName() const override { return #type; }		// #type converts type to string

	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class ALMOND_API Event
	{
		friend class EventDispatcher;

		//********************* 
		//
		//	public
		//
		//**********************

		public:

			virtual EventType GetEventType() const = 0;
			virtual const char* GetName() const = 0;
			virtual int GetCategoryFlags() const = 0;
			virtual std::string ToString() const { return GetName(); };

			inline bool IsInCategory( EventCategory category )
			{
				return category & GetCategoryFlags();
			}

			bool Handled = false;


		//********************* 
		//
		//	protected
		//
		//**********************

		protected:

		//********************* 
		//
		//	private
		//
		//**********************

		private:

	};

	class ALMOND_API EventDispatcher
	{
		// eventFunc is a function that will retrun bool?
		template<typename T> 
		using EventFunc = std::function<bool( T& )>;

		//********************* 
		//
		//	public
		//
		//**********************

		public:

			// construct event to be dispatch ( kind of like loading a canon)
			EventDispatcher( Event& event )
				: m_Event(event)
			{
			}

			// TODO: learn more about this
			// 	Dispatch is kind of like firing the canon with the loaded canonball ( m_Event )
			// 		by checking if event type match with template event type
			// 
			// 	By dispatching, it means calling "func"
			// 	using EventFunc, we can ensure func is a function that will take T as argument
			template< typename T > 
			bool Dispatch( EventFunc< T > func )
			{
				if( m_Event.GetEventType() == T::GetStaticType() )
				{
					m_Event.Handled = func( *(T*)&m_Event );
					return true;
				}
				return false;
			}

		//********************* 
		//
		//	protected
		//
		//**********************

		protected:


		//********************* 
		//
		//	private
		//
		//**********************

		private:

			Event& m_Event;

	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}