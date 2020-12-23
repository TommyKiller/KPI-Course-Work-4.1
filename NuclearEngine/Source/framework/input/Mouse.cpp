#include "Mouse.h"

ne_input::mouse::mouse()
{
	double x, y;
	glfwGetCursorPos(glfwGetCurrentContext(), &x, &y);

	position = ne_geom::point2D(x, y);
	previous = ne_geom::point2D(x, y);
}
