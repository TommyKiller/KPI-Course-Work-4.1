#ifndef NE_ACTION_H
#define NE_ACTION_H
#pragma once

// Standard Headers
#include <string>

// Local Headers
#include "Bind.h"
#include "HandleState.h"
#include "InputController.h"
#include "events/ActionEvent.h"

// Define Namespace
namespace ne_input
{
	class Action
	{
	public:
		ActionEvent action;

		Action(std::string name);

		std::string getName() const;

		Action& bindTo(bind bind);
		Action& unbind(bind bind);

	private:
		std::string _name;

		void pollEvent(bind bind, HandleState state);
	};
} // namespace ne_input

#endif // !NE_ACTION_H
