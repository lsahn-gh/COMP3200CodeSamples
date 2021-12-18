#include <iostream>
#include "Swap.h"

using namespace std;

namespace samples
{
	void SwapExample()
	{
		cout << "+------------------------------+" << endl;
		cout << "|         Swap Example         |" << endl;
		cout << "+------------------------------+" << endl;
		int number1 = 1;
		int number2 = 2;

		cout << "Before swap: " << number1 << ", " << number2 << endl;
		Swap(number1, number2);
		cout << "After swap: " << number1 << ", " << number2 << endl;
	}

    // reference: 어떠한 변수(메모리)?에 별칭/닉네임을 붙이는 행위
    // 새로운 변수를 만드는 것도 아니고 값을 복사하는 것도 아니다.
    // 그냥 기존에 있는 메모리(변수) 영역에 다른 이름의 '닉네임'을 선언하는 것.
    // 그렇기에 참조를 사용해도 해당 메모리의 값이 변경된다.
    //
    // pointer: 메모리 영역을 하나 소유하고 그 메모리에는 오로지 주소만 저장할
    //          수 있다. (추가적인 메모리 영역 필요)
    //          따라서 math 연산이 가능하다. 예) +1, *2 등의 연산 가능.
    //          lvalue 이므로 연산하여 저장이 가능함.
    // reference: 소유한 메모리 영역을 가르키는 또다른 닉네임이 생성되나
    //            그 닉네임은 포인터처럼 추가적인 메모리를 필요로 하지 않는다.
    //            단지 기존의 메모리 영역을 또 다른 이름으로 매핑하는 것일 뿐.
    //            하나의 메모리 영역에 2개 이상의 이름이 부여되는 행위.
    //            (추가적인 메모리 영역 불필요)
	void Swap(int& number1, int& number2)
	{
        // number1 (reference)
        // 1. NULL이 될 수 없다. 특성상 소유한 메모리를 가르켜야함.
        // 2. math 연산이 불가능하다. 포인터처럼 주소에 +1 이런거 불가능.
        // 따라서 참조의 메모리 영역이 유효함을 syntax 레벨에서 확인 가능.
		int temp = number1;
		number1 = number2;
		number2 = temp;
	}

    void SwapExample2()
    {
        cout << "+-----------leesoo-------------+" << endl;
        cout << "|       my reference swap exam |" << endl;
        cout << "+------------------------------+" << endl;

        int number1 = 10;
        int number2 = 20;

        cout << "number 1 = " << number1 << ", number2 = " << number2 << endl;
        Swap2(number1, number2);
        cout << "number 1 = " << number1 << ", number2 = " << number2 << endl;
    }

    void Swap2(int& x, int& y)
    {
        int t = x;
        x = y;
        y = t;
    }
}
