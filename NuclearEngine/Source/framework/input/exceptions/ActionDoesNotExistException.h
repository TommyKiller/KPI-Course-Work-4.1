#ifndef NE_ACTION_DOES_NOT_EXIST_EXCEPTION
#define NE_ACTION_DOES_NOT_EXIST_EXCEPTION
#pragma once

// Standard Headers
#include <stdexcept>

// Define Namespace
namespace ne_input
{
	class ActionDoesNotExistException : public std::logic_error
	{
	public:
		ActionDoesNotExistException(const std::string& what);
		ActionDoesNotExistException(const char* what);
	};
} // namespace ne_input

#endif // !NE_ACTION_DOES_NOT_EXIST_EXCEPTION
