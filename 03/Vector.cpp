#include <iostream>
#include "Vector.h"

namespace samples
{
	Vector::Vector()
		: Vector(0, 0)
	{
	}

	Vector::Vector(int x, int y)
		: mX(x)
		, mY(y)
	{
	}

	int Vector::GetX() const
	{
		return mX;
	}

	void Vector::SetX(int x)
	{
		mX = x;
	}

	void Vector::SetY(int y)
	{
		mY = y;
	}

	int Vector::GetY() const
	{
		return mY;
	}

	bool Vector::IsEqual(const Vector& v) const
	{
		return (mX == v.mX && mY == v.mY);
	}

    // @result 개체는 스택에 생성되지만 '값'을 반환하므로
    // 반환 당시에는 값 복사가 된다.
    // C의 구조체가 arg나 return시에 값 복사가 일어나는 메커니즘과 같다.
	Vector Vector::Multiply(const Vector& v) const
	{
        // @v의 각 멤버 변수와 곱하여 새로운 개체를 생성한 뒤에 반환
		Vector result(mX * v.GetX(), mY * v.GetY());

		return result;
	}

	Vector Vector::Multiply(int multiplier) const
	{
        // @multiplier 스칼라 값을 입력받아 각 멤버 변수와 곱한 뒤 새 개체 반환
		Vector result(mX * multiplier, mY * multiplier);

		return result;
	}

	void Vector::Scale(const Vector& v)
	{
		mX *= v.mX;
		mY *= v.mY;
	}

	void Vector::Scale(int multiplier)
	{
		mX *= multiplier;
		mY *= multiplier;
	}
}
