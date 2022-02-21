#include <iostream>
#include <vector>
#include "ObjectVectorExample.h"
#include "Score.h"

using namespace std;

namespace samples
{
	void ObjectVectorExample()
	{
		// Object를 타입으로 가지는 벡터 생성 및 capacity 5로 설정
		vector<Score> scores;
		scores.reserve(5);

		scores.push_back(Score(30, "C++"));
		scores.push_back(Score(59, "Algorithm"));
		scores.push_back(Score(87, "Java"));
		scores.push_back(Score(74, "Data Comm"));
		scores.push_back(Score(41, "Android"));

		cout << "Before erasing the element" << endl;
		PrintVector(scores);

		cout << "After erasing the element" << endl;

		vector<Score>::iterator iter = scores.begin();
		while (iter != scores.end())
		{
			if (iter->GetClassName() == "Java")
			{
				// 개체가 삭제되면서 'iter + 1' 요소가 한칸 앞으로 당겨진다.
				// 따라서 'iter++'를 추가로 수행하지 않아야 한다.
				iter = scores.erase(iter);
			}
			else
			{
				iter++;
			}
		}
		PrintVector(scores);

		// 위 반복과 아래 반복의 차이는 다음과 같다.
		// 1. 위 반복: ClassName 따라 1) 벡터의 요소를 삭제하거나 2) iter 값을 변경한다.
		//            따라서 while을 이용해 반복을 수행한다.
		// 			  '벡터내 요소의 갯수가 변경되는 로직.'
		// 2. 아래 반복: 벡터의 전체 아이템을 순회하다가 Score가 30인 개체에 대해 SetScore를 수행하는 루틴이다.
		//             '벡터내 요소의 갯수가 변경되지 않는 로직.'

		cout << "After changing the score of class 1" << endl;
		for (vector<Score>::iterator iter = scores.begin(); iter != scores.end(); ++iter)
		{
			// 개체 복사, 따라서 값이 같은 서로 다른 개체가 존재하게 되는 것.
			Score score = *iter;

			if (score.GetScore() == 30)
			{
				// 개체가 복사되었음으로 SetScore를 호출해도 '원본' 개체의 값은 변경되지 않는다.
				score.SetScore(100);
				// '원본' 개체가 바뀌려면 어떻게 코딩해야 할까?
				// --> (*iter).SetScore(100);
			}
		}

		PrintVector(scores);

		// Out of Scope 됨과 동시에 벡터내에 있던 모든 개체도 destroy 된다.
		// 이유는? '개체 포인터'가 아닌 '개체' 그 자신이 벡터 요소로 추가되었기 때문이다.
	}
	
	void PrintVector(const vector<Score>& scores)
	{
		for (vector<Score>::const_iterator iter = scores.begin(); iter != scores.end(); ++iter)
		{
			iter->PrintVariables();
		}
		cout << endl;
	}
}