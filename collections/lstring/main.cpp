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

    // 1. oldString + " " 우선 처리.
    //    - lstring operator+(const lstring& rhs) 메서드만 정의된 경우.
    //      @concatStr = oldString + lstring(" ")로 타입 캐스팅되어
    //      lstring 개체 생성하고 두 개체에 대해 '+' 연산 수행되어
    //      @concatStr 개체가 생성된다. 여기서 lstring 개체가 2개 생성된다.
    //      1) lstring(" ") 생성.
    //      2) operator+ 메서드 반환값으로 @concatStr 개체 생성.
    //    - lstring operator+(const char* rhs) 메서드가 정의된 경우.
    //      위 메서드에서 oldString + " "(const char*)로 새로운 개체
    //      @concatStr이 만들어지고 거기에 + newString이 처리된다.
    //
    // 2. @concatStr + newString 처리.
    lstring concatString = oldString + " " + newString;
    cout << "concatString: " << concatString
        << ", length: " << concatString.GetLength()
        << ", capacity: " << concatString.GetCapacity()
        << endl;

    return 0;
}
