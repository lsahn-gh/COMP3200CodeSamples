#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "PolymorphismExample.h"

namespace samples
{
    // 정리 필요
    // 1. 다형성 (어떻게 설명할 것인가?)
    // 2. 정적 바인딩
    //    - 컴파일 타임에 클래스 멤버함수의 주소 offset이 결정되는 메커니즘
    // 3. 동적 바인딩 (가상함수)
    //    - 런타임에 클래스 멤버함수의 주소 offset이 결정되는 방식
    //    - 멤버함수 주소를 lookup하는 시간이 필요하므로 정적 바인딩에 비하면
    //      느리다.
    //    - 동적 바인딩 메커니즘을 구현하기 위해 '가상함수 테이블'이 구현된다.
    // 4. 가상(함수) 테이블
    //    - 컴파일 타임에 생성되는 클래스의 멤버함수 주소 테이블.
    //      동적 바인딩에서 사용되며 객체가 아닌 클래스마다 소유하게 된다.
	void PolymorphismExample()
	{
        Animal* myAnimals[] = {
            new Cat(3),
            new Dog(5),
        };

        for (size_t i = 0; i < sizeof(myAnimals)/sizeof(myAnimals[0]); i++)
        {
        }

#if 0
		Animal* cat = new Cat(3);
		Animal* dog = new Dog(5);

		cat->Move();
		cat->Speak();

		dog->Move();
		dog->Speak();

		delete cat;
		delete dog;
#endif
	}
}
