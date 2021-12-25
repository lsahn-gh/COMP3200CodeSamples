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
		// string class는 내부적으로 다음과 같이 이루어져있다.
		// 
		// pointer: heap 영역을 가르키는 포인터
		// size: 인스턴스에 저장되어 있는 문자 갯수
		// capacity: NULL 문자를 제외한 문자열을 담을 수 있는 공간
		string myLine = "hersheys";

		cout << "myLine = " << myLine << endl;

		myLine += ' ';
		for (int i = (int)myLine.size() - 2; i >= 0; i--)
		{
			// 문자열을 추가하면서 capacity 이상의 크기가 요청되면
			// heap에 새로운 영역을 요청하여 할당받고 old -> new 로 복사한 뒤
			// old heap 영역을 제거한다.
			myLine += myLine[i];
		}

		cout << "myLine = " << myLine << endl;
	}
}
