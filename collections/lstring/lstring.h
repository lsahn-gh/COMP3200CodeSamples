#pragma once

#include <string>

using namespace std;

namespace ls
{
	class lstring
	{
	public:
		// Constructor & Overloading
		lstring();
		lstring(const size_t capacity);
		lstring(const char* string);
		lstring(const string& string);
		// Copy Constructor
		lstring(const lstring& string);
		// Destructor
		~lstring();

		char* GetString() const;
		void SetString(const char* string);

		size_t GetLength() const;
		size_t GetCapacity() const;

		// Operator Overloadings
		friend ostream& operator<<(ostream& os, const lstring& rhs);
		lstring operator+(const lstring& rhs) const;

	private:
		char* mChar;
		size_t mLength;
		size_t mCapacity;
	};
}
