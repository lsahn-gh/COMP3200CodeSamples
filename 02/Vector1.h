#pragma once

class Vector1
{
// Access Modifier(접근제어자) 키워드가 없으면 기본은 private 이다.
public:
	// Constructor (생성자)
	// 1. 생성자가 하나라도 없다면 컴파일러가 알아서 생성자 1개를 생성하도록 한다.
	//    - 인스턴스 생성 도중 다른 클래스가 멤버로 있다면 해당 클래스의 개체까지
	//      생성한다.
	// 2. Overloading 특성을 통해 생성자 2개 선언.
	//    - 호출시 인자의 갯수 및 타입에 따라 호출되는 생성자가 달라짐.
	Vector1();
	Vector1(int x, int y);

// 클래스 단위 접근제어자 (개체가 아님)
// private이 아래에 작성되는 것인 업계 표준
private:
	// m은 member 변수 의미
	int mX;
	int mY;
};
