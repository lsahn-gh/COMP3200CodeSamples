#include <iostream>
#include <string>
#include <cstring>
#include "String.h"

using namespace std;

namespace samples
{
    // 일반 생성자
    // const char 타입의 배열을 입력받아 새로운 char 개체를 생성하고
    // (이때 크기는 @str 크기 + 1 이다)
    // @str 값을 새로운 char 개체에 복사한다.
	String::String(const char* str)
		: mSize(strlen(str) + 1)
	{
		mString = new char[mSize];
		memcpy(mString, str, mSize);
	}

    // 복사 생성자
    // const class 타입의 레퍼런스를 인자로 입력받는다.
    // 일반 primitive 타입은 빠르게 초기화해주고 포인터 타입의 멤버 변수는
    // @mSize 크기의 char 개체를 생성하고 해당 개체에 값을 복사한다.
	String::String(const String& str)
        // private으로 선언된 멤버 변수 @mSize가 dot(.)으로 값을 참조할 수 있는
        // 이유는 cpp의 private 접근 제어자는 클래스간 private 멤버변수를 공유할
        // 수 있는 특징을 가지고 있기 때문이다.
		: mSize(str.mSize)
	{
        // '깊은 복사(deep copy)' 방식
		mString = new char[mSize];
		memcpy(mString, str.mString, mSize);
	}
    // 컴파일러가 생성하는 복사 생성자는 '얕은 복사' 생성자이고
    // 위와 같이 heap에 allocation 해야하는 멤버 변수가 있다면 2개 이상의
    // 개체가 같은 heap 주소를 공유하게 되어 race condition이 발생할 수 있다.
    // 따라서 멤버 변수가 primitive 타입이 아니라면 deep copy 방식을 이용해야
    // 데이터 무결성을 보장할 수 있다.

	String::~String()
	{
        // char 객체는 여러개의 char 원소를 가지므로 delete[]로 삭제한다
		delete[] mString;
	}

	void String::Print()
	{
		cout << "Member string : " << mString << endl;
	}
}
