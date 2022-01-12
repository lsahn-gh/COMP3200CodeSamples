#include <iostream>
#include "Cat.h"

namespace samples
{
	Cat::Cat(int age) 
		: Animal(age)
	{
	}

#if 0
	void Cat::Move() const
	{
		std::cout << "A cat is moving" << std::endl;
	}
#endif

	void Cat::Speak() const
	{
		std::cout << "Meow " << std::endl;
	}
}
