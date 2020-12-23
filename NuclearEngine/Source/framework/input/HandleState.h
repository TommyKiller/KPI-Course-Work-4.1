#ifndef NE_HANDLE_STATE_H
#define NE_HANDLE_STATE_H
#pragma once

// Define Namespace
namespace ne_input
{
	enum class HandleState
	{
		POLLED,
		REPEAT,
		HANDLED
	};
} // namespace ne_input

#endif // !NE_HANDLE_STATE_H
