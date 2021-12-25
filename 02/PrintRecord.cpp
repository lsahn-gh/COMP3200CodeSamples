#include <iostream>
#include <sstream>
#include <string>
#include "PrintRecord.h"

using namespace std;

namespace samples
{
	void PrintRecordExample()
	{
		cout << "+------------------------------+" << endl;
		cout << "|     Print Record Example     |" << endl;
		cout << "+------------------------------+" << endl;

		string firstName;
		string lastName;
		string studentID;
		int score;

		// string을 가지는 inputStream 생성
		istringstream inputStream("Pope Kim A12345678 80");
		ostringstream outputStream;

		// input stringStream에서 데이터를 읽어온다.
		inputStream >> firstName >> lastName >> studentID >> score;
		// output stringStream으로 데이터를 저장(출력?)한다.
		// 이때 데이터는 stream buffer에 저장되어 있다.
		outputStream << firstName << " " << lastName << " " << studentID << " " << score;

		// console output stream에 데이터를 출력한다.
		cout << outputStream.str() << endl;
	}

	void PrintRecordExample2()
	{
		cout << "Leesoo -- My example" << endl;

		string firstName;
		string lastName;
		string studentID;
		int score;

		istringstream ilsStream("Leesoo Ahn 220318045 100");
		ostringstream olsStream;

		ilsStream >> firstName >> lastName >> studentID >> score;
		olsStream << studentID << ": " << lastName << " " << firstName << " -- " << score;

		cout << olsStream.str() << endl;
	}
}
