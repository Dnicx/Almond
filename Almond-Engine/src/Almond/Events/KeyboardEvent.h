#pragma once

#include "aepch.h"

namespace Almond
{
	class ALMOND_API KeyEvent : public Event
	{
		//********************* 
		//
		//	public
		//
		//**********************

		public:
			inline int getKeycode() const { return m_Keycode; }

			// specify category at base class
			EVENT_CLASS_CATEGORY( EventCategoryKeyboard | EventCategoryInput );
			
		//********************* 
		//
		//	protected
		//
		//**********************

		protected:
			KeyEvent( int keycode )
				: m_Keycode( keycode ) {}

			int m_Keycode;

	};

	class ALMOND_API KeyPressedEvent : public KeyEvent
	{
		//********************* 
		//
		//	public
		//
		//**********************

		public:

			KeyPressedEvent( int keycode, int repeatCount ):
				: KeyEvent( keycode ), m_RepeatCount( repeatCount ) {}

			inline int GetRepeatcount() { return m_RepeatCount; }

			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "KeyPressedEvent: " << m_Keycode << " (" << m_RepeatCount << " repeats)";
				return ss.str();
			}

			// define specific event type in concrete class
			EVENT_CLASS_TYPE( KeyPressed )

		//********************* 
		//
		//	private
		//
		//**********************

		private:

			int m_RepeatCount;
	};

	class ALMOND_API KeyReleasedEvent : public KeyEvent
	{
		//********************* 
		//
		//	public
		//
		//**********************

		public:

			KeyReleasedEvent( int keycode, int repeatCount ):
				: KeyEvent( keycode ), m_RepeatCount( repeatCount ) {}

			inline int GetRepeatcount() { return m_RepeatCount; }

			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "KeyReleasedEvent: " << m_Keycode ;
				return ss.str();
			}

			// define specific event type in concrete class
			EVENT_CLASS_TYPE( KeyReleased )

		//********************* 
		//
		//	private
		//
		//**********************

		private:

			int m_RepeatCount;

	};
}