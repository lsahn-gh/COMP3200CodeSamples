#include <iostream>
#include <string>
#include "MirrorString.h"

using namespace std;

namespace samples
{
	void MirrorStringExample()
	{
		cout << "+------------------------------+" << endl;
		cout << "|    Mirror String Example     |" << endl;
		cout << "+------------------------------+" << endl;

		string line = "Hello World!";

		cout << "string to mirror: " << line << endl;

		for (int i = (int)line.size() - 1; i >= 0; --i)
		{
			line += line[i];
		}
		cout << "mirrored string" << line << endl;
	}

	void MirrorStringExample2()
	{
		string myLine = "hersheys";

		cout << "myLine = " << myLine << endl;

		myLine += ' ';
		for (int i = (int)myLine.size() - 2; i >= 0; i--)
		{
			myLine += myLine[i];
		}

		cout << "myLine = " << myLine << endl;
	}
}