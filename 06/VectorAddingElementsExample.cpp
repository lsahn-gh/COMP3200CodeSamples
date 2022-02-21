#include <iostream>
#include <vector>
#include "VectorAddingElementsExample.h"

using namespace std;

namespace samples
{
	void VectorAddingElementsExample()
	{
		vector<int> scores;
		// 미리 5개의 bucket을 할당한다.
		// 몇개 사용할지 미리 알고 있다면 이러한 방식으로 작성하는것이 좋다.
		scores.reserve(5);

		// 벡터의 마지막에 아이템 추가
		scores.push_back(30);
		scores.push_back(50);
		scores.push_back(80);
		scores.push_back(65);
		scores.push_back(73);
		PrintScores(scores);

		// 벡터의 마지막 값을 삭제한다. 이때 삭제되는 값은 반환되지 않으므로
		// 삭제 이전에 미리 받아오는 코드를 작성해야 한다.
		scores.pop_back();
		scores.pop_back();
		PrintScores(scores);

		// capacity/size를 10으로 늘린다.
		// 기존 5개의 아이템 이후로 나머지 추가된 칸 5개는 기본값(0)으로 초기화된다.
		scores.resize(10);
		PrintScores(scores);

		// capacity는 늘어난 10 그대로지만, size가 1로 변한다.
		scores.resize(1);
		PrintScores(scores);
	}

	void PrintScores(const vector<int>& scores)
	{
		cout << "Current elements : ";
		// 1. arg 'scores'가 const 가 붙어서 넘어오므로 'const_iterator'를 사용하자.
		// 2. 'iterator'는 포인터 타입이므로 '++iter' 연산을 수행할 수 있다.
		for (vector<int>::const_iterator iter = scores.begin(); iter != scores.end(); ++iter)
		{
			// 역참조
			cout << *iter << " ";
		}
		cout << endl;

		cout << "Current capacity : " << scores.capacity() << endl;
		cout << "Current size : " << scores.size() << endl << endl;
	}
}
