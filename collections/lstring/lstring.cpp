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

    lstring::lstring(const char* string)
        // We don't really care about the string's overflow.
        : mLength(strlen(string))
        , mCapacity(mLength + 1)
    {
        mChar = new char[mCapacity];
        memcpy(mChar, string, mLength);
        mChar[mLength] = '\0';
    }

    lstring::lstring(const string& string)
        : mLength(string.size())
        , mCapacity(mLength + 1)
    {
        mChar = new char[mCapacity];
        memcpy(mChar, string.c_str(), mLength);
        mChar[mLength] = '\0';
    }

    lstring::lstring(const lstring& string)
        : mLength(string.mLength)
        , mCapacity(string.mCapacity)
    {
        mChar = new char[mCapacity];
        memcpy(mChar, string.mChar, mLength);
        mChar[mLength] = '\0';
    }

    lstring::~lstring()
    {
        delete[] mChar;
    }

    char* lstring::Get() const
    {
        return mChar;
    }

    int lstring::Length() const
    {
        return mLength;
    }

    int lstring::Capacity() const
    {
        return mCapacity;
    }
}
