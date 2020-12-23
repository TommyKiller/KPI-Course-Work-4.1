#ifndef NE_AXIS_EVENT_H
#define NE_AXIS_EVENT_H
#pragma once

// System Headers
#include <tk_utilities/tk_events/EventDispatcher.h>

// Define Namespace
namespace ne_input
{
	class AxisEvent : public tk_events::EventDispatcher<tk_events::Delegate<void, double>, const char*>
	{
	public:
		static constexpr const char* AXIS_ALTERED = "axisAltered";
	};
} // namespace ne_input

#endif // !NE_AXIS_EVENT_H
