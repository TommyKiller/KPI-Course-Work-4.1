#include "Bind.h"

ne_input::bind::bind(int key, int mods):
	key(key), mods(mods)
{}

ne_input::bind::bind(const bind & bind):
	key(bind.key), mods(bind.mods)
{}

bool ne_input::bind::operator==(const bind & bind) const
{
	return (key == bind.key && mods == bind.mods);
}

bool ne_input::bind::operator!=(const bind& bind) const
{
	return !(*this == bind);
}
