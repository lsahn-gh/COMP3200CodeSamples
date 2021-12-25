#include <iostream>
#include "Vector1.h"
#include "VectorExample1.h"

using namespace std;

namespace samples
{
	void VectorExample1()
	{
		// -- RAII(Resource Acquisition Is Initialization)? --
		// 'acquired before use' type의 resources에 대한 C++ 프로그래밍 기법.
		// 예) heap allocation, lock, socket, db connection and etc.
		// 요점은 "이러한 자원을 개체의 lifetime에 bind(묶는)하는 방식"
		//
		// 개체 A가 생성될때 사용할 자원을 constructor에서 할당하고 준비해둔다.
		// (언제 사용할지 모르지만 이럴경우 lazy allocation을 고려해보자.)
		// 그러다가 개체의 lifetime이 끝난다면 destructor에서 해당 자원들을
		// 반납하도록 코드를 작성하여 프로그래머가 '실수'하지 않도록 한다.
		// 
		// 개체의 lifetime은 다음과 같다.
		// 1. 명시적 delete 호출 (개체가 heap allocated인 경우)
		// 2. 개체가 생성된 scope를 벗어나는 경우 (개체가 주로 stack에 생성된 경우)
		//
		// Link: https://en.cppreference.com/w/cpp/language/raii

		// -- new/delete와 malloc/free 차이 정리 --
		// 1) new/delete
		//    1. constructor/destructor 호출
		//       거기서 멤버변수 초기화 가능
		//    2. operator이다. (오버라이딩하여 다른 로직으로 수정 가능?)
		//    3. fail 시에 'bad_alloc' exception을 던진다.
		//    4. const, reference 타입같이 선언과 동시에 초기화가 필요할 경우
		//       constructor에서 런타임에 초기화가 가능하다.
		//
		// 2) malloc/free
		//    1. constructor가 없어 초기화시에 수동으로 해줘야 한다.
		//    2. function이다.
		//    3. fail 시에 NULL 값을 반환한다.
		
		cout << "+------------------------------+" << endl;
		cout << "|       Vector Example 1       |" << endl;
		cout << "+------------------------------+" << endl;

		// stack에 vector 인스턴스 생성
		Vector1 v1;
		Vector1 v2(10, 55);
	}

	void VectorExample3()
	{
		// pointer 크기
		// - 32-bit machine에서 4 bytes
		// - 64-bit machine에서 8 bytes

		// - Stack에 Vector1 개체 생성
		// - VectorExample3 scope 넘어갈시 메모리에서 해제됨
		Vector1 v1;
		// - Heap에 Vector1 개체 생성
		// - VectorExample3 scope 넘어가도 메모리에서 해제되지 않음.
		// - delete 이용하여 명시적으로 해제 필요.
		Vector1* v2 = new Vector1();
		// - Heap에 Vector1 영역 생성
		//   (new와 분리하기 위해 '영역'으로 표시)
		// - VectorExample3 scope 넘어가도 메모리에서 해제되지 않음.
		// - free 이용하여 명시적으로 해제 필요.
		Vector1* v3 = (Vector1*)malloc(sizeof(Vector1));
		// - Heap에 Vector1 개체를 저장할 수 있는 영역 10개 생성
		// - 해당 영역들은 포인터를 담을 수 있는 4/8 바이트 공간들이 아님.
		// - mX, mY를 담을 수 있는 8 바이트 공간 10개를 의미.
		Vector1* vec_list = new Vector1[10];
		// - Heap에 Vector1 pointer를 저장할 수 있는 영역 10개 생성
		// - 해당 영역들은 포인터를 담는 4/8 바이트 공간이다.
		// - 따라서 각 인덱스 별로 'Vector1* <- 포인터' 값이여야 한다.
		Vector1** vec_p_list = new Vector1*[10];
	}
}
