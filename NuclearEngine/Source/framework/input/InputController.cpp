#include "InputController.h"

ne_input::InputController& ne_input::InputController::getInstance()
{
	static InputController _instance;

	return _instance;
}

void ne_input::InputController::handleInput(int key, int scancode, int action, int mods)
{
	if (key != GLFW_KEY_UNKNOWN)
	{
		if (action == GLFW_PRESS)
		{
			setPolled(bind(key, mods));
		}
		else if (action == GLFW_RELEASE) setHandled(bind(key, mods));
	}
}

//void ne_input::InputController::handleInput(double xpos, double ypos)
//{
//	ne_geom::point2D newPosition(xpos, ypos);
//	ne_geom::point2D offset = newPosition.offset(_mouse.position);
//
//	if (_mouse.position.x == _mouse.previous.x)
//	{
//		if (offset.x < 0) setPolled(bind(mouse::MOUSE_AXIS_X_LEFT, 0));
//		else if (offset.x > 0) setPolled(bind(mouse::MOUSE_AXIS_X_RIGHT, 0));
//	}
//	else if (_mouse.position.x < _mouse.previous.x)
//	{
//		if (offset.x == 0) setHandled(bind(mouse::MOUSE_AXIS_X_LEFT, 0));
//		else if ()
//	}
//
//
//	if (_mouse.position == _mouse.previous)
//	{
//		if (offset.x < 0) setPolled(bind(mouse::MOUSE_AXIS_X_LEFT, 0));
//		else if (offset.x > 0) setPolled(bind(mouse::MOUSE_AXIS_X_RIGHT, 0));
//
//		if (offset.y > 0) setPolled(bind(mouse::MOUSE_AXIS_Y_UP, 0));
//		else if (offset.x < 0) setPolled(bind(mouse::MOUSE_AXIS_Y_DOWN, 0));
//	}
//	else if (_mouse.position != _mouse.previous)
//	{
//		if (offset.x == 0 && _mouse.position.x < _mouse.previous.x) setHandled(bind(mouse::MOUSE_AXIS_X_LEFT, 0));
//		else if (offset.x == 0 && _mouse.position.x > _mouse.previous.x) setHandled(bind(mouse::MOUSE_AXIS_X_RIGHT, 0));
//		else if (offset.x != 0)
//
//		if (offset.y == 0 && _mouse.position.y > _mouse.previous.y) setHandled(bind(mouse::MOUSE_AXIS_Y_UP, 0));
//		else if (offset.y == 0 && _mouse.position.y < _mouse.previous.y) setHandled(bind(mouse::MOUSE_AXIS_Y_DOWN, 0));
//	}
//
//	_mouse.previous = _mouse.position;
//	_mouse.position = newPosition;
//
//
//
//	_mouse.position = ne_geom::point2D(xpos, ypos);
//	ne_geom::point2D offset = _mouse.position.offset(_mouse.previous);
//
//	if (offset.x < 0) setPolled(bind(mouse::MOUSE_AXIS_X_LEFT, 0));
//	else if (offset.x > 0) setPolled(bind(mouse::MOUSE_AXIS_X_RIGHT, 0));
//	else if (offset.x == 0)
//	{
//		setHandled(bind(mouse::MOUSE_AXIS_X_LEFT, 0));
//		setHandled(bind(mouse::MOUSE_AXIS_X_RIGHT, 0));
//	}
//
//	if (offset.y > 0) setPolled(bind(mouse::MOUSE_AXIS_Y_UP, 0));
//	else if (offset.y < 0) setPolled(bind(mouse::MOUSE_AXIS_Y_DOWN, 0));
//	else if (offset.y == 0)
//	{
//		setHandled(bind(mouse::MOUSE_AXIS_Y_UP, 0));
//		setHandled(bind(mouse::MOUSE_AXIS_Y_DOWN, 0));
//	}
//}

void ne_input::InputController::pollEvents()
{
	std::deque<bind> buffer;
	while (!_inputEvents.empty())
	{
		bind bind = _inputEvents.front();
		input.dispatchEvent({ bind, _binds[bind] }, bind);

		switch (_binds[bind])
		{
		case HandleState::POLLED:
			_binds[bind] = HandleState::REPEAT;
			[[fallthrough]];
		case HandleState::REPEAT:
			buffer.push_back(bind);
			break;
		}

		_inputEvents.pop_front();
	}
	_inputEvents = buffer;

	////if (_mouse.previous == _mouse.position)

	inputController.dispatchEvent({}, InputControllerEvent::INPUT_HANDLED);
}

ne_input::InputController::~InputController()
{}

void ne_input::InputController::setPolled(bind bind)
{
	auto result = std::find(_inputEvents.begin(), _inputEvents.end(), bind);
	if (result == _inputEvents.end())
	{
		_inputEvents.push_back(bind);
		_binds[bind] = HandleState::POLLED;
	}
}

void ne_input::InputController::setHandled(bind bind)
{
	auto result = std::find(_inputEvents.begin(), _inputEvents.end(), bind);
	if (result != _inputEvents.end())
	{
		_binds[bind] = HandleState::HANDLED;
	}
}
