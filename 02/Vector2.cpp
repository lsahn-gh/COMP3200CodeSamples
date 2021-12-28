#include "Vector2.h"

Vector2::Vector2()
	// mX, mY를 0으로 초기화
	: mX(0)
	, mY(0)
{
	// 대입
	// mX = 0;
	// mY = 0;

	// 대입과 초기화 방식의 차이는?
	// 클래스의 멤버 변수에 const나 reference로 선언된 변수를
	// 초기화할 때 차이가 있다.
	// 대입은 이미 생성된 변수에 '새' 값을 assign 하는 것이라
	// const/reference 타입 변수에 assign 할 수 없고 컴파일 오류가 난다.
	// 그에 비해 초기화 방식은 개체가 만들어짐과 동시에 const/reference 변수를
	// 초기화하므로 컴파일 오류가 나지 않는다.
}

Vector2::Vector2(int x, int y)
	: mX(x)
	, mY(y)
{
}

// const 메서드이므로 멤버 변수를 변경하게 되면 컴파일 오류가 난다.
// Vector2.cpp:30:12: error: assignment of member ‘Vector2::mX’ in read-only object
//    30 |         mX = 0;
//       |         ~~~^~~
int Vector2::GetX() const
{
	// mX = 0;
	return mX;
}

int Vector2::GetY() const
{
	return mY;
}

void Vector2::SetX(int x)
{
	mX = x;
}

void Vector2::SetY(int y)
{
	mY = y;
}

void Vector2::Add(const Vector2& vector)
{
	mX += vector.mX;
	mY += vector.mY;
}
