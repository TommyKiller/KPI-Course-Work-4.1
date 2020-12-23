#ifndef NE_INPUT_CONTROLLER_EVENT_H
#define NE_INPUT_CONTROLLER_EVENT_H
#pragma once

// System Headers
#include <tk_utilities/tk_events/EventDispatcher.h>

// Define Namespace
namespace ne_input
{
	class InputControllerEvent : public tk_events::EventDispatcher<tk_events::Delegate<void>, const char*>
	{
	public:
		static constexpr const char* INPUT_HANDLED = "inputHandled";
	};
} // namespace ne_input

#endif // !NE_INPUT_CONTROLLER_EVENT_H
