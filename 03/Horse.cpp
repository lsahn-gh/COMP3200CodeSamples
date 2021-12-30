#include "Horse.h"

namespace samples
{
    Horse::Horse(int age)
        : Animal(age)
    {
    }

    Horse::Horse(int age, int type)
        : Animal(age)
        , mType(type)
    {
    }

    std::string Horse::Whinny() const
    {
        // 반환형이 std::string 클래스이므로 자동으로 형변환
        return "Whinny!";
    }

    int Horse::GetType() const
    {
        return mType;
    }
}
