#pragma once

#include <string>
#include "Animal.h"

namespace samples
{
    class Pig : public Animal
    {
    public:
        Pig(int age);

        char* Oink() const;

    private:
    };
}
