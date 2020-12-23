#ifndef NE_AXIS_H
#define NE_AXIS_H
#pragma once

// Standard Headers
#include <string>
#include <unordered_map>

// Local Headers
#include "Bind.h"
#include "HandleState.h"
#include "events/AxisEvent.h"
#include "InputController.h"

// Define Namespace
namespace ne_input
{
	class Axis
	{
	public:
		AxisEvent axis;

		Axis(std::string name, double lowerBound = -1.0, double upperBound = 1.0);

		std::string getName() const;
		double getValue() const;
		double getLowerBound() const;
		double getUpperBound() const;

		Axis& bindTo(bind bind, double scale);
		Axis& unbind(bind bind);

	private:
		std::string _name;
		double _value;
		double _previous;
		double _lowerBound;
		double _upperBound;
		std::unordered_map<bind, double> _scales;

		void alter(bind bind, HandleState state);
		void pollEvent();

	};
} // namespace ne_input

#endif // !NE_AXIS_H
