#include <cstring>
#include "lstring.h"

using namespace std;

namespace ls
{
	lstring::lstring()
		: mLength(0)
		, mCapacity(15)
	{
		mChar = new char[mCapacity + 1];
	}

	lstring::lstring(const size_t capacity)
		: mLength(0)
		, mCapacity(capacity)
	{
		mChar = new char[mCapacity];
	}

	lstring::lstring(const char* string)
		// We don't really care about the string's overflow.
		: mLength(strlen(string))
		, mCapacity(mLength + 1)
	{
		mChar = new char[mCapacity]();
		memcpy(mChar, string, mLength);
	}

	lstring::lstring(const string& string)
		: mLength(string.size())
		, mCapacity(mLength + 1)
	{
		mChar = new char[mCapacity]();
		memcpy(mChar, string.c_str(), mLength);
	}

	lstring::lstring(const lstring& string)
		: mLength(string.mLength)
		, mCapacity(string.mCapacity)
	{
		mChar = new char[mCapacity]();
		memcpy(mChar, string.mChar, mLength);
	}

	lstring::~lstring()
	{
		delete[] mChar;
	}

	char* lstring::GetString() const
	{
		return mChar;
	}

	void lstring::SetString(const char* string)
	{
		delete[] mChar;

		size_t strSize = strlen(string);
		mLength = strSize;
		mCapacity = strSize + 1;

		mChar = new char[mCapacity]();
		memcpy(mChar, string, mLength);
	}

	size_t lstring::GetLength() const
	{
		return mLength;
	}

	size_t lstring::GetCapacity() const
	{
		return mCapacity;
	}

	// Operator Overloadings
	lstring lstring::operator+(const lstring& rhs) const
	{
		lstring newString(mLength + rhs.mLength + 1);
		memcpy(newString.mChar, mChar, mLength);
		memcpy(newString.mChar + mLength, rhs.mChar, rhs.mLength);
		newString.mLength = mLength + rhs.mLength;
		newString.mChar[newString.mLength] = '\0';

		return newString;
	}

	// lstring 클래스 멤버함수 아님, 전역함수
	ostream& operator<<(ostream& os, const lstring& rhs)
	{
		// 1. string string::operator<< 가 어떻게 구현되어 있는지 확인해보기
		// 2. os << rhs.mChar 시에 segfault 발생 (포인터 전달은?)
		os << string(rhs.mChar);
		return os;
	}
}
