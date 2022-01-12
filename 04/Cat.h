#pragma once

#include "Animal.h"

namespace samples
{
	class Cat : public Animal
	{
	public:
		Cat(int age);

#if 0
		virtual void Move() const;
#endif
		virtual void Speak() const;
	};
}
