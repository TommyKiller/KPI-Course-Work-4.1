#ifndef NE_MOUSE_H
#define NE_MOUSE_H
#pragma once

// System Headers
#include <GLFW/glfw3.h>

// Local Headers
#include "../geom/Point2D.h"

// Define Namespace
namespace ne_input
{
	struct mouse
	{
	public:
		static constexpr int MOUSE_AXIS_X_LEFT = 8;
		static constexpr int MOUSE_AXIS_X_RIGHT = 9;
		static constexpr int MOUSE_AXIS_Y_UP = 10;
		static constexpr int MOUSE_AXIS_Y_DOWN = 11;

		ne_geom::point2D position;
		ne_geom::point2D previous;

		mouse();
	};
} // namespace ne_input

#endif // !NE_MOUSE_H
