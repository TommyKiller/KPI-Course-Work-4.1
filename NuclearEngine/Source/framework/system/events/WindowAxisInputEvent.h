#ifndef NE_WINDOW_AXIS_INPUT_EVENT_H
#define NE_WINDOW_AXIS_INPUT_EVENT_H
#pragma once

// System Headers
#include <tk_utilities/tk_events/EventDispatcher.h>

// Define Namespace
namespace ne_system
{
	class WindowAxisInputEvent : public tk_events::EventDispatcher<tk_events::Delegate<void, double, double>, const char*>
	{
	public:
		static constexpr const char* WINDOW_AXIS_INPUT_POLLED = "windowAxisInputPolled";
	};
} // namespace ne_system

#endif // !NE_WINDOW_AXIS_INPUT_EVENT_H
