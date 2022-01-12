#include <iostream>
#include "Animal.h"

namespace samples
{
	Animal::Animal(int age)
		: mAge(age)
	{
	}

    // Animal 클래스에서 'virtual' 키워드를 통해 가상함수로 선언하여도
    // Animal 객체에 대한 구현체가 있어야 하므로 정의한다.
	Animal::~Animal()
	{
	}

	void Animal::Move() const
	{
		std::cout << "An animal is moving" << std::endl;
	}

	void Animal::Speak() const
	{
		std::cout << "An animal is speaking" << std::endl;
	}

	int Animal::GetAge() const
	{
		return mAge;
	}
}
