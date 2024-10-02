#pragma once
#pragma once

#include "aepch.h"

#include "Event.h"

namespace Almond
{

	class ALMOND_API WindowResizeEvent : public Event
	{
	
		
		public:
			WindowResizeEvent( unsigned int width_px, unsigned int height_px )
				: m_Width_px( width_px ), m_Height_px( height_px ) {}

			inline unsigned int GetWidth() const { return m_Width_px; }
			inline unsigned int GetHeight() const { return m_Height_px; }

			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "WindowResizeEvent: " << m_Width_px << ", " << m_Height_px;
				return ss.str();
			}

			EVENT_CLASS_CATEGORY( EventCategoryApplication )

			EVENT_CLASS_TYPE( WindowResize )

		private:

			unsigned int m_Width_px, m_Height_px;

	};

	class ALMOND_API WindowCloseEvent : public Event
	{
		public:

			WindowCloseEvent() {}

			EVENT_CLASS_CATEGORY( EventCategoryApplication )
			EVENT_CLASS_TYPE( WindowClose )
	};

	class ALMOND_API WindowFocusEvent : public Event
	{
		public:

			WindowFocusEvent() {}

			EVENT_CLASS_CATEGORY( EventCategoryApplication )
			EVENT_CLASS_TYPE( WindowFocus )
	};

	class ALMOND_API WindowLostFocusEvent : public Event
	{
		public:

			WindowLostFocusEvent() {}

			EVENT_CLASS_CATEGORY( EventCategoryApplication )
			EVENT_CLASS_TYPE( WindowLostFocus )
	};

	class ALMOND_API WindowMoveEvent : public Event
	{
		public:

			WindowMoveEvent() {}

			EVENT_CLASS_CATEGORY( EventCategoryApplication )
			EVENT_CLASS_TYPE( WindowMove )
	};

	class ALMOND_API AppTickEvent : public Event
	{
		public:

			AppTickEvent() {}

			EVENT_CLASS_CATEGORY( EventCategoryApplication )
			EVENT_CLASS_TYPE( AppTick )
	};

	class ALMOND_API AppUpdateEvent : public Event
	{
		public:

			AppUpdateEvent() {}

			EVENT_CLASS_CATEGORY( EventCategoryApplication )
			EVENT_CLASS_TYPE( AppUpdate )
	};

	class ALMOND_API AppRenderEvent : public Event
	{
		public:

			AppRenderEvent() {}

			EVENT_CLASS_CATEGORY( EventCategoryApplication )
			EVENT_CLASS_TYPE( AppRender )
	};

}