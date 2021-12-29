#include <iostream>
#include "lstring.h"

using namespace std;
using namespace ls;

int main(int argc, char *argv[])
{
	lstring oldString("Hello World");
	lstring newString(oldString);

	cout << "oldString: " << oldString
		 << ", length: " << oldString.GetLength()
		 << ", capacity: " << oldString.GetCapacity()
		 << endl;
	cout << "newString: " << newString
		 << ", length: " << newString.GetLength()
		 << ", capacity: " << newString.GetCapacity()
		 << endl;

	newString.SetString("Hell World");

	cout << "oldString: " << oldString
		 << ", length: " << oldString.GetLength()
		 << ", capacity: " << oldString.GetCapacity()
		 << endl;
	cout << "newString: " << newString
		 << ", length: " << newString.GetLength()
		 << ", capacity: " << newString.GetCapacity()
		 << endl;

	lstring concatString = oldString + " " + newString;
	cout << "concatString: " << concatString
		 << ", length: " << concatString.GetLength()
		 << ", capacity: " << concatString.GetCapacity()
		 << endl;

	return 0;
}
