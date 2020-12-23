#ifndef NE_WINDOW_KEY_INPUT_EVENT_H
#define NE_WINDOW_KEY_INPUT_EVENT_H
#pragma once

// System Headers
#include <tk_utilities/tk_events/EventDispatcher.h>

// Define Namespace
namespace ne_system
{
	class WindowKeyInputEvent : public tk_events::EventDispatcher<tk_events::Delegate<void, int, int, int, int>, const char*>
	{
	public:
		static constexpr const char* WINDOW_KEY_INPUT_POLLED = "windowKeyInputPolled";
	};
} // namespace ne_system

#endif // !NE_WINDOW_KEY_INPUT_EVENT_H

