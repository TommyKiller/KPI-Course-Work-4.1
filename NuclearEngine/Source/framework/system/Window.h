#ifndef NE_WINDOW_H
#define NE_WINDOW_H
#pragma once

// System Headers
#include <GLFW/glfw3.h>

// Local Headers
#include "events/WindowKeyInputEvent.h"
#include "events/WindowAxisInputEvent.h"

// Define Namespace
namespace ne_system
{
	class Window
	{
	public:
		static Window& getInstance();

		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);

		void close();

		WindowKeyInputEvent keyInput;
		WindowAxisInputEvent axisInput;
	};
} // namespace ne_system

#endif // !NE_WINDOW_H
