#include "ActionDoesNotExistException.h"

ne_input::ActionDoesNotExistException::ActionDoesNotExistException(const std::string& what):
	logic_error(what)
{}

ne_input::ActionDoesNotExistException::ActionDoesNotExistException(const char* what):
	logic_error(what)
{}
