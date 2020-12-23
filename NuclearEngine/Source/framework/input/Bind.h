#ifndef NE_BIND_H
#define NE_BIND_H
#pragma once

// Standard Headers
#include <functional>

// Define Namespace
namespace ne_input
{
	struct bind
	{
	public:
		int key;
		int mods;

		bind(int key, int mods);
		bind(const bind& bind);

		bool operator==(const bind& bind) const;
		bool operator!=(const bind& bind) const;
	};
} // namespace ne_input

// Define Namespace
namespace std
{
	template<>
	struct hash<ne_input::bind>
	{
		size_t operator()(const ne_input::bind& bind) const noexcept
		{
			return ((hash<int>()(bind.key) ^ (hash<int>()(bind.key) << 1)) >> 1);
		}
	};
}

#endif // !NE_BIND_H
