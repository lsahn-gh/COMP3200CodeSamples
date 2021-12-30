#include "Vector2.h"

namespace samples
{
	Vector2::Vector2()
		: Vector2(0, 0)
	{
	}

	Vector2::Vector2(int x, int y)
		: mX(x)
		, mY(y)
	{
	}

	int Vector2::GetX() const
	{
		return mX;
	}

	void Vector2::SetX(int x)
	{
		mX = x;
	}

	void Vector2::SetY(int y)
	{
		mY = y;
	}

	int Vector2::GetY() const
	{
		return mY;
	}

	bool Vector2::operator==(const Vector2& rhs) const
	{
		return (mX == rhs.mX && mY == rhs.mY);
	}

    // 'Vector2 * Vector2' 형태
	Vector2 Vector2::operator*(const Vector2& rhs) const
	{
		Vector2 result(mX * rhs.mX, mY * rhs.mY);

		return result;
	}

    // 'Vector2 * integer' 형태이므로 Vector2 클래스의 멤버함수로 정의한다.
	Vector2 Vector2::operator*(int multiplier) const
	{
		Vector2 result(mX * multiplier, mY * multiplier);

		return result;
	}

    // 'integer * Vector2' 형태이므로 전역변수 형태로 정의한다.
    // Vector2 클래스의 멤버함수는 아니다.
	Vector2 operator*(int multiplier, const Vector2& v)
	{
		Vector2 result(v.mX * multiplier, v.mY * multiplier);

		return result;
	}

    // Vector2 vec2;
    // 'vec2 *= vec1' 형태
    // 기존 vec2 개체에 vec1 값을 곱하여 vec2 레퍼런스 반환
	Vector2& Vector2::operator*=(const Vector2& rhs)
	{
		mX *= rhs.mX;
		mY *= rhs.mY;
		
        // 자기 자신을 리턴함
        // 연속 체이닝 가능
        // - vec1 *= vec2 *= vec3
        //   vec1 *= vec2
        //   vec1 *= vec3 순으로 처리
        //
        // 왜 refer 타입인가?
		return *this;
	}

	Vector2& Vector2::operator*=(int multiplier)
	{
		mX *= multiplier;
		mY *= multiplier;

		return *this;
	}

	std::ostream& operator<<(std::ostream& out, const Vector2& v)
	{
		out << v.mX << ", " << v.mY << std::endl;
		
		return out;
	}
}
