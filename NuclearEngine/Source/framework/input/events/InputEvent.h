#ifndef NE_INPUT_EVENT_H
#define NE_INPUT_EVENT_H
#pragma once

// System Headers
#include <tk_utilities/tk_events/EventDispatcher.h>

// Local Headers
#include "../Bind.h"
#include "../HandleState.h"

// Define Namespace
namespace ne_input
{
	class InputEvent: public tk_events::EventDispatcher<tk_events::Delegate<void, bind, HandleState>, bind>
	{};
} // namespace ne_input

#endif // !NE_INPUT_EVENT_H
