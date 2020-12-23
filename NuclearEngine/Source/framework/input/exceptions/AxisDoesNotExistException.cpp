#include "AxisDoesNotExistException.h"

ne_input::AxisDoesNotExistException::AxisDoesNotExistException(const std::string& what):
	logic_error(what)
{}

ne_input::AxisDoesNotExistException::AxisDoesNotExistException(const char* what):
	logic_error(what)
{}
