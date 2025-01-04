#pragma once

#include "aepch.h"

#include "Event.h"

namespace Almond
{

	class ALMOND_API MouseMovedEvent : public Event
	{
		//********************* 
		//
		//	public
		//
		//**********************

	public:

		// constructor, set mouse pos XY
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		// specify category at base class
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

		EVENT_CLASS_TYPE(MouseMoved);

		//********************* 
		//
		//	private
		//
		//**********************

	private:
		float m_MouseX, m_MouseY;
	};

	class ALMOND_API MouseScrolledEvent : public Event
	{
		//********************* 
		//
		//	public
		//
		//**********************

		public:

			// constructor, set mouse pos XY
			MouseScrolledEvent(float offsetX, float offsetY)
				: m_OffsetX(offsetX), m_OffsetY(offsetY) {}

			inline float GetOffsetX() const { return m_OffsetX; }
			inline float GetOffsetY() const { return m_OffsetY; }

			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseScrolledEvent: " << m_OffsetX << ", " << m_OffsetY;
				return ss.str();
			}

			// specify category at base class
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

			EVENT_CLASS_TYPE(MouseScrolled);

		//********************* 
		//
		//	private
		//
		//**********************

		private:
			float m_OffsetX, m_OffsetY;
	};

	class ALMOND_API MouseButtonEvent : public Event
	{
		//********************* 
		//
		//	public
		//
		//**********************

		public:

			inline int GetMouseButton() const { return m_Button; }

			// specify category at base class
			EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryMouse | EventCategoryInput);

		//********************* 
		//
		//	protected
		//
		//**********************

		protected:
			MouseButtonEvent(int button)
				: m_Button(button) {}

			int m_Button;
		//********************* 
		//
		//	private
		//
		//**********************

		private:
	};

	class ALMOND_API MouseButtonPressedEvent : public MouseButtonEvent
	{
		//********************* 
		//
		//	public
		//
		//**********************

		public:

			MouseButtonPressedEvent(int button)
				: MouseButtonEvent(button) {}

			std::string ToString() const
			{
				std::stringstream ss;
				ss << "MouseButtonPressedEvent: " << m_Button;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class ALMOND_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
		//********************* 
		//
		//	public
		//
		//**********************

		public:

			MouseButtonReleasedEvent(int button)
				: MouseButtonEvent(button) {}

			std::string ToString() const
			{
				std::stringstream ss;
				ss << "MouseButtonReleasedEvent: " << m_Button;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}