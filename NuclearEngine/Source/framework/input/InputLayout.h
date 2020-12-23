#ifndef NE_INPUT_LAYOUT_H
#define NE_INPUT_LAYOUT_H
#pragma once

// Standard Headers
#include <string>
#include <vector>

// Local Headers
#include "Axis.h"
#include "Action.h"
#include "exceptions/AxisDoesNotExistException.h"
#include "exceptions/ActionDoesNotExistException.h"

// Define Namespace
namespace ne_input
{
	class InputLayout
	{
	public:
		Action& addAction(std::string name);
		Action& getAction(std::string name);
		InputLayout& eraseAction(std::string name);

		Axis& addAxis(std::string name, double lowerBound = -1.0, double upper_Bound = 1.0);
		Axis& getAxis(std::string name);
		InputLayout& eraseAxis(std::string name);

	private:
		std::vector<Axis> _axes;
		std::vector<Action> _actions;
	};
} // namespace ne_input

#endif // !NE_INPUT_LAYOUT_H
