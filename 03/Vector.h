#pragma once

namespace samples
{
	class Vector
	{
	public:
		Vector();
		Vector(int x, int y);
        // 컴파일러에 의해 복사 생성자 생성
        // 멤버 변수가 primitive 타입이라
        // 명시적으로 작성하지 않아도 된다.

		int GetX() const;
		void SetX(int x);

		int GetY() const;
		void SetY(int y);
		
		bool IsEqual(const Vector& v) const;
        // 메서드 오버로딩
		Vector Multiply(const Vector& v) const;
		Vector Multiply(int multiplier) const;

        // 메서드 오버로딩
		void Scale(const Vector& v);
		void Scale(int multiplier);

	private:
		int mX;
		int mY;
	};
}
