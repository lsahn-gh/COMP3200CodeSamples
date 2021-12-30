#include <iostream>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Horse.h"
#include "Pig.h"
#include "InheritanceExample.h"

using namespace std;

namespace samples
{
	void InheritanceExample()
	{
		cout << "+------------------------------+" << endl;
		cout << "|      Inheritance Example     |" << endl;
		cout << "+------------------------------+" << endl;

		Cat cat(3);
		Dog dog(5);
        Horse zebra(7, horse::ZEBRA);
        Horse pony(3, horse::PONY);
        Pig pig(10);

		cout << "Cat's Age: " << cat.GetAge() << endl;
		cout << "Cat's Purring: " << cat.Purr() << endl;

		cout << "Dog's Age: " << dog.GetAge() << endl;
		cout << "Dog's Barking: " << dog.Bark() << endl;

        cout << "Horse's Age: " << zebra.GetAge() << endl;
        cout << "Horse's Whinnying: " << zebra.Whinny() << endl;
        cout << "Horse's Type: " << zebra.GetType() << endl;

        cout << "Horse's Age: " << pony.GetAge() << endl;
        cout << "Horse's Whinnying: " << pony.Whinny() << endl;
        cout << "Horse's Type: " << pony.GetType() << endl;

		cout << "Pig's Age: " << pig.GetAge() << endl;
		cout << "Pig's Oinking: " << pig.Oink() << endl;
	}
}
