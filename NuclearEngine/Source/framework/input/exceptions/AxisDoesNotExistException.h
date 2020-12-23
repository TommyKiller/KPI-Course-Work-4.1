#ifndef NE_AXIS_DOES_NOT_EXIST_EXCEPTION
#define NE_AXIS_DOES_NOT_EXIST_EXCEPTION
#pragma once

// Standard Headers
#include <stdexcept>

// Define Namespace
namespace ne_input
{
	class AxisDoesNotExistException : public std::logic_error
	{
	public:
		AxisDoesNotExistException(const std::string& what);
		AxisDoesNotExistException(const char* what);
	};
} // namespace ne_input

#endif // !NE_AXIS_DOES_NOT_EXIST_EXCEPTION

