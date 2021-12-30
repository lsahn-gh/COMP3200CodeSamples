#include <iostream>
#include "Cat.h"

using namespace std;

namespace samples
{
    // 상속시 메모리 레이아웃
    //
    //     4      4
    //  +------+------+---------+
    //  | age  | mType|
    //  +------+------+---------+
    //     |      |
    //     |      V
    //     |     Cat
    //     V
    //   Animal
    //
    // 따라서 (Animal*)로 Animal 개체를 가져오는 것도 가능하고
    //        (Cat*)로 Cat 개체를 가져오는 것도 가능하다.
	Cat::Cat(int age)
		: Animal(age)
	{
	}

	string Cat::Purr() const
	{
		return string("Purr");
	}
}
