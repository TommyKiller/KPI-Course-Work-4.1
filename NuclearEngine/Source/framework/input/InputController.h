#ifndef NE_INPUT_CONTROLLER_H
#define NE_INPUT_CONTROLLER_H
#pragma once

// System Headers
#include <GLFW/glfw3.h>

// Standard Headers
#include <deque>
#include <unordered_map>

// Local Headers
#include "Mouse.h"
#include "events/InputEvent.h"
#include "events/InputControllerEvent.h"

// Define Namespace
namespace ne_input
{
	class InputController
	{
	public:
		static InputController& getInstance();

		InputEvent input;
		InputControllerEvent inputController;

		void handleInput(int key, int scancode, int action, int mods);
		void handleInput(double xpos, double ypos);
		void pollEvents();

	private:
		mouse _mouse;
		std::unordered_map<bind, HandleState> _binds;
		std::deque<bind> _inputEvents;

		InputController() = default;
		InputController(const InputController&) = delete;
		~InputController();

		InputController& operator=(const InputController&) = delete;
		void setPolled(bind bind);
		void setHandled(bind bind);
	};
} // namespace ne_input

#endif // !NE_INPUT_CONTROLLER_H
