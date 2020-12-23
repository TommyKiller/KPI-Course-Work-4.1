#include "Mouse.h"

ne_input::mouse::mouse()
{
	double x, y;
	glfwGetCursorPos(glfwGetCurrentContext(), &x, &y);

	previous = ne_geom::point2D(x, y);
}
