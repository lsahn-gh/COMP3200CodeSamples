#include <iostream>
#include "Vector1.h"
#include "VectorExample1.h"

using namespace std;

namespace samples
{
	void VectorExample1()
	{
		// 1. RAII 찾아보고 정리
		// 2. new/delete 와 malloc/free 차이점 정리
		
		cout << "+------------------------------+" << endl;
		cout << "|       Vector Example 1       |" << endl;
		cout << "+------------------------------+" << endl;

		// stack에 vector 인스턴스 생성
		Vector1 v1;
		Vector1 v2(10, 55);
	}
}