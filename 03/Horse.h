#pragma once

#include <string>
#include "Animal.h"

namespace samples
{
    namespace horse
    {
        enum
        {
            ZEBRA = 0,
            PONY,
        };
    }
    
    class Horse : public Animal
    {
    public:
        Horse(int age);
        Horse(int age, int type);

        std::string Whinny() const;
        int GetType() const;

    private:
        int mType;
    };
}
