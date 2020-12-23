#include "FPSLayout.h"

ne_input::FPSLayout::FPSLayout()
{
	addAxis(MOVE_FORWARD_AXIS).bindTo({ GLFW_KEY_W, 0 }, 1.0).bindTo({ GLFW_KEY_S, 0 }, -1.0);
	addAxis(MOVE_RIGHT_AXIS).bindTo({ GLFW_KEY_D, 0 }, 1.0).bindTo({ GLFW_KEY_A, 0 }, -1.0);
}
