#include "ReverseInputString.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace samples
{
	void ReverseInputStringExample()
	{
		cout << "+------------------------------+" << endl;
		cout << "|    Reverse String Example    |" << endl;
		cout << "+------------------------------+" << endl;

        // line 버퍼의 크기를 512로 지정
		const int LINE_SIZE = 512;
		char line[LINE_SIZE];

        // 문자열이나 EOF를 받겠다
		cout << "Please enter a string to reverse" << endl
			<< "or EOF to quit: ";

        // 512 크기 또는 \n 까지의 문자열을 받는다.
        // 이때 \n은 버린다.
        // cin.get(): 512 크기또는 \n 까지 입력받는다.
        //            단 \n은 아직 입력 스트림에 남아있다.
		cin.getline(line, LINE_SIZE);
        // 입력은 전부 문자열인데 fail인 이유는?
        // eof를 입력받아도 fail bit이 설정된다.
		if (cin.fail())
		{
            // 스트림을 good 상태로 변경하고 리턴
			cin.clear();
			return;
		}

        // 첫번째와 마지막 문자를 지정한다
		char* p = line;
		char* q = line + strlen(line) - 1;
		while (p < q)
		{
            // p와 q의 값을 치환한다
			char temp = *p;
			*p = *q;
			*q = temp;

            // 다음 변경을 위해 포인터를 보정한다.
			++p;
			--q;
		}
		
		cout << "Reversed string: " << line << endl;
	}

    void MyReverseInputString()
    {
        const int LINESZ = 512;
        char line[LINESZ];

		while (true)
		{
			cout << "Input a string for reversing or EOF : ";
			cin.getline(line, LINESZ);

			// cin.get()을 쓰고
			//   - eof()을 쓴 뒤에 엔터치면 무한 루프이다.
			//     \n 은 입력 스트림에 남아있다.
			//   - fail()을 쓰면 fail bit이 설정되어 종료한다.
			// cin.getline()을 쓰고
			//   - eof()을 쓴 뒤에 엔터치면 \n은 이미 getline에서 삭제되었고
			//     아무 입력이 없는 상태이므로 출력은 없고 다음 입력으로 넘어간다.
			//   - fail()을 쓰면 eof()와 마찬가지로 \n은 이미 getline에서 삭제되었으므로
			//     아무 입력이 없는 상태로 출력하며 다음 입력으로 넘어간다.
			if (cin.fail())
			{
				cin.clear();
				return;
			}

			char *s = line;
			char *e = line + strlen(line) - 1;

			while (s < e)
			{
				char tmp = *s;
				*s = *e;
				*e = tmp;

				s++;
				e--;
			}

			cout << "Reversing : " << line << endl;
		}
    }
}
