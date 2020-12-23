#ifndef NE_ACTION_EVENT_H
#define NE_ACTION_EVENT_H
#pragma once

// System Headers
#include <tk_utilities/tk_events/EventDispatcher.h>

// Define Namespace
namespace ne_input
{
	class ActionEvent : public tk_events::EventDispatcher<tk_events::Delegate<void>, const char*>
	{
	public:
		static constexpr const char* ACTION_STARTED = "actionStarted";
		static constexpr const char* ACTION_ENDED = "actionEnded";
	};
} // namespace ne_input

#endif // !NE_ACTION_EVENT_H
