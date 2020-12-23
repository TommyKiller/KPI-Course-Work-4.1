#include "Window.h"

void ne_system::Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	keyInput.dispatchEvent({ key, scancode, action, mods }, WindowKeyInputEvent::WINDOW_KEY_INPUT_POLLED);
}

void ne_system::Window::cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
	axisInput.dispatchEvent({ xpos, ypos }, WindowAxisInputEvent::WINDOW_AXIS_INPUT_POLLED);
}
