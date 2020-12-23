#include "Axis.h"

ne_input::Axis::Axis(std::string name, double lowerBound, double upperBound):
	_name(name), _lowerBound(lowerBound), _upperBound(upperBound), _value(0.0), _previous(0.0)
{
	InputController::getInstance().inputController.addEventListener(tk_events::Delegate(&Axis::pollEvent, this), InputControllerEvent::INPUT_HANDLED);
}

std::string ne_input::Axis::getName() const
{
	return _name;
}

double ne_input::Axis::getValue() const
{
	return _value;
}

double ne_input::Axis::getLowerBound() const
{
	return _lowerBound;
}

double ne_input::Axis::getUpperBound() const
{
	return _upperBound;
}

ne_input::Axis& ne_input::Axis::bindTo(bind bind, double scale)
{
	InputController::getInstance().input.addEventListener(tk_events::Delegate(&Axis::alter, this), bind);
	_scales[bind] = scale;

	return *this;
}

ne_input::Axis& ne_input::Axis::unbind(bind bind)
{
	InputController::getInstance().input.removeEventListener(tk_events::Delegate(&Axis::alter, this), bind);
	_scales.erase(bind);

	return *this;
}

void ne_input::Axis::alter(bind bind, HandleState state)
{
	if (state == HandleState::POLLED || state == HandleState::REPEAT)
	{
		double scale = _scales[bind];
		double result = _value / scale;

		if (0 <= result && result < 1) _value = scale;
		else if (result < 0) _value = 0;
	}
	else if (state == HandleState::HANDLED) _value = 0;
}

void ne_input::Axis::pollEvent()
{
	if ((_value != 0) || ((_value == 0) && (_previous != _value)))
		axis.dispatchEvent({ _value }, AxisEvent::AXIS_ALTERED);

	_previous = _value;
}
