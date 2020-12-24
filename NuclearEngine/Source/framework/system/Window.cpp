#include "Window.h"

ne_system::Window& ne_system::Window::getInstance()
{
	static Window _instance;

	return _instance;
}

void ne_system::Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	ne_system::Window::getInstance().keyInput.dispatchEvent({ key, scancode, action, mods }, WindowKeyInputEvent::WINDOW_KEY_INPUT_POLLED);
}

void ne_system::Window::cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
	ne_system::Window::getInstance().axisInput.dispatchEvent({ xpos, ypos }, WindowAxisInputEvent::WINDOW_AXIS_INPUT_POLLED);
}

void ne_system::Window::close()
{
	glfwSetWindowShouldClose(glfwGetCurrentContext(), true);
}
