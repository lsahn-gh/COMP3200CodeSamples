#pragma once

namespace samples
{
	class String
	{
	public:
        // 일반 생성자 (constructor)
		String(const char* str);
        // 복사 생성자
        // 프로그래머가 명시적으로 작성하지 않으면 컴파일러가 묵시적으로
        // 복사 생성자를 만든다.
        // 이때 복사 생성자는 '얕은 복사(shallow copy)'로 동작한다.
		String(const String& str);
        // 소멸자 (destructor)
		~String();

		void Print();

	private:
		char* mString;
		size_t mSize;
	};
}
