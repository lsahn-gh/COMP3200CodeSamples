#include "Pig.h"

namespace samples
{
    Pig::Pig(int age)
        : Animal(age)
    {
    }

    char* Pig::Oink() const
    {
        return "Oink!";
    }
}
