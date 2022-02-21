#include <iostream>
#include <vector>
#include "VectorSwappingElementsExample.h"
#include "VectorAddingElementsExample.h"

using namespace std;

namespace samples
{
	void VectorSwappingElementsExample()
	{
		vector<int> scores;
		scores.reserve(2);

		scores.push_back(85);
		scores.push_back(73);

		cout << "scores" << endl;
		PrintScores(scores);

		vector<int> anotherScores;
		// '.assign(7, 100)' : capacity/size를 모두 7로 변경, 초기값은 100이 됨.
		anotherScores.assign(7, 100);

		// 두 벡터간 전체 요소를 서로 바꿈.
		// @벡터 내부 아이템 리스트는 pointer로 참조하고 있을것이므로 포인터만 서로 변경하면 O(1)로 끝내기 가능.
		scores.swap(anotherScores);

		cout << "scores" << endl;
		PrintScores(scores);

		cout << "anotherScores" << endl;
		PrintScores(anotherScores);
	}
}