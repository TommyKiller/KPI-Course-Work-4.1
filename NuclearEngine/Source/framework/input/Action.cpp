#include "Action.h"

ne_input::Action::Action(std::string name):
	_name(name)
{}

std::string ne_input::Action::getName() const
{
	return _name;
}

ne_input::Action& ne_input::Action::bindTo(bind bind)
{
	InputController::getInstance().input.addEventListener(tk_events::Delegate(&Action::pollEvent, this), bind);

	return *this;
}

ne_input::Action& ne_input::Action::unbind(bind bind)
{
	InputController::getInstance().input.removeEventListener(tk_events::Delegate(&Action::pollEvent, this), bind);

	return *this;
}

void ne_input::Action::pollEvent(bind bind, HandleState state)
{
	if (state == HandleState::POLLED) action.dispatchEvent({}, ActionEvent::ACTION_STARTED);
	else if (state == HandleState::HANDLED) action.dispatchEvent({}, ActionEvent::ACTION_ENDED);
}
