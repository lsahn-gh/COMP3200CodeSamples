#pragma once

namespace samples
{
	class Animal
	{
	public :
        // 생성자
		Animal(int age);

        // 가상 소멸자
        // 소멸자가 정적 바인딩으로 선언되버리면 아래의 문제가 생긴다.
        //
        // Animal* myCat = new Cat(3);
        // delete myCat;
        // 
        // 이때 delete는 Animal 클래스의 소멸자를 호출하므로 Cat 클래스내에서
        // heap allocation을 한 코드가 있다면 메모리 누수 문제가 발생한다.
		virtual ~Animal();
		
        // 동적 바인딩을 통해 자식 객체를 부모 타입(Animal)으로 정의하여도
        // 자식의 멤버함수를 호출할 수 있도록 가상함수 타입으로 선언한다.
		virtual void Move() const;
		virtual void Speak() const;

		int GetAge() const;

	private:
		int mAge;
	};
}
