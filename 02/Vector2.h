#pragma once

class Vector2
{
public:
	// constructor (생성자)
	// 보다시피 overloading 한다.
	// overloading은 메서드의 이름은 같으나 인자의 타입이나 갯수에 따라
	// 다른 동작을 하도록 명세하는 방법이다.
	// 프로그래머가 생성자를 명시하지 않으면 컴파일러가 기본 생성자를 생성하고
	// 프로그래머가 생성자를 명시하면 컴파일러는 개입하지 않는다.
	Vector2();
	Vector2(int x, int y);
	
	// const 메서드 (코딩 표준)
	// 해당 메서드는 멤버 변수를 변경시키지 않는다는 명시적 약속.
	// 이렇게 최대한 restrict 하게 코드를 작성하게 하여
	// 프로그래머의 실수를 방지하기 위한 방법.
	int GetX() const;
	int GetY() const;
	void SetX(int x);
	void SetY(int Y);

	// @vector: const Vector2 reference 타입
	// Add 메서드 내부에서 @vector의 멤버 변수 값을 변경하지 않는다는 명시적 약속.
	// 다만 현재 인스턴스의 멤버 변수는 바꿀지 말지 확신할 수 없다.
	void Add(const Vector2& vector);
	
private:
	int mX;
	int mY;
};
