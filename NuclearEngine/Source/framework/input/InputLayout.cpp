#include "InputLayout.h"

ne_input::Action& ne_input::InputLayout::addAction(std::string name)
{
	_actions.push_back(Action(name));

	_actions.back();
}

ne_input::Action& ne_input::InputLayout::getAction(std::string name)
{
	auto result = std::find_if(_actions.begin(), _actions.end(), [&name](const Action& action) -> bool {
		return action.getName() == name;
	});

	if (result != _actions.end()) return _actions.at(std::distance(_actions.begin(), result));
	else throw ActionDoesNotExistException("Can not find an action of a given name!");
}

ne_input::InputLayout& ne_input::InputLayout::eraseAction(std::string name)
{
	auto result = std::find_if(_actions.begin(), _actions.end(), [&name](const Action& action) -> bool {
		return action.getName() == name;
		});

	if (result != _actions.end()) _actions.erase(result);

	return *this;
}

ne_input::Axis& ne_input::InputLayout::addAxis(std::string name, double lowerBound, double upper_Bound)
{
	_axes.push_back(Axis(name, lowerBound, upper_Bound));

	_axes.back();
}

ne_input::Axis& ne_input::InputLayout::getAxis(std::string name)
{
	auto result = std::find_if(_axes.begin(), _axes.end(), [&name](const Axis& axis) -> bool {
		return axis.getName() == name;
		});

	if (result != _axes.end()) return _axes.at(std::distance(_axes.begin(), result));
	else throw AxisDoesNotExistException("Can not find an axis of a given name!");
}

ne_input::InputLayout& ne_input::InputLayout::eraseAxis(std::string name)
{
	auto result = std::find_if(_axes.begin(), _axes.end(), [&name](const Axis& axis) -> bool {
		return axis.getName() == name;
	});

	if (result != _axes.end()) _axes.erase(result);

	return *this;
}
