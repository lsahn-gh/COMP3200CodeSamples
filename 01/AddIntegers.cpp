#include "AddIntegers.h"
#include <iostream>
#include <climits>
#include <iomanip>

using namespace std;

namespace samples
{
	void AddIntegersExample()
	{
        // 예제 제목 출력
		cout << "+------------------------------+" << endl;
		cout << "|     Add Integers Example     |" << endl;
		cout << "+------------------------------+" << endl;

		int number;
		int sum = 0;

		while (true)
		{
            // 입력으로 '정수' 또는 EOF만 받는다.
			cout << "Please enter an integer or EOF: ";
            // integer 타입으로 받도록 하면 cin이 알아서
            // integer 타입으로 변환 후에 number에 저장
			cin >> number;

            // eof가 입력되었으면 loop 종료
            // linux는 Ctrl+D 입력
			if (cin.eof())
			{
				break;
			}

            // fail bit가 set되는 경우는 아래와 같다.
            // 1. 456abc
            // 2. abc
            // 3. eof
            //
            // 예를 들어 456abc를 입력받았다고 해보자.
            // 456은 읽고 abc를 읽을때 실패하게 되며
            // 이때 입력 스트림은 a를 포인팅하고 있다.
            // 따라서 입력 스트림에는 아직 데이터가 남아 있다.
            // 이러한 실패를 처리하기 위해 아래 작업을 수행한다.
			if (cin.fail())
			{
				cout << "Invalid input" << endl;
                // 입력 스트림을 good 상태로 변경한다.
                // 이때 스트림의 데이터는 아직 남아있다.
				cin.clear();
                // 스트림에 존재하는 데이터를 실제로 삭제한다.
                // LLONG_MAX만큼 전부 하거나 \n을 만날때까지 한다.
                // - ignore() : 문자 1개 삭제
                // - ignore(10) : 문자 10개
                // - ignore(LLONG_MAX, '\n') : LLONG_MAX 크기 또는 \n 문자까지
				cin.ignore(LLONG_MAX, '\n');
                // 다음 입력을 위해 continue 한다.
				continue;
			}
            // 성공인 경우 sum에 누계한다.
			sum += number;
		}
        // 입력 완료 후에는 스트림을 good 상태로 변경한다.
		cin.clear();

		cout << "The sum is " << sum << endl;
	}

    void MyCode()
    {
        int number;
        cin >> number;
        cout << "Input number is " << number << endl;

		char buf[4];
		cin >> setw(4) >> buf;
		cout << "Buf value : " << buf << endl;
    }
}
