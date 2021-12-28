#pragma once

#include <string>

using namespace std;

namespace ls
{
    class lstring
    {
    public:
        // 일반 생성자
        lstring();
        lstring(const char* string);
        lstring(const string& string);
        // 복사 생성자
        lstring(const lstring& string);
        // 소멸자
        ~lstring();

        char* Get() const;
        int Length() const;
        int Capacity() const;

    private:
        char* mChar;
        int mLength;
        int mCapacity;
    };
}
