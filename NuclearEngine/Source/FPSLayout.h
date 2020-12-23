#ifndef FPS_LAYOUT_H
#define FPS_LAYOUT_H
#pragma once

// Local Headers
#include "framework/input/InputLayout.h"

// Define Namespace
namespace ne_input
{
	class FPSLayout : public InputLayout
	{
	public:
		static constexpr const char* MOVE_FORWARD_AXIS = "moveForwardAxis";
		static constexpr const char* MOVE_RIGHT_AXIS = "moveRightAxis";

		FPSLayout();
	};
} // namespace ne_input

#endif // !FPS_LAYOUT_H
