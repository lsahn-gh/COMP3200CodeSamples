#include <iostream>
#include <vector>
#include "PointerVectorExample.h"
#include "Score.h"

using namespace std;

namespace samples
{
	void PointerVectorExample()
	{
		// '개체 포인터'를 담는 벡터 선언 후 크기를 5로 지정.
		// 32bits = 4 bytes, 64bits = 8 bytes
		vector<Score*> scores;
		scores.reserve(5);

		// 개체를 힙에 생성
		Score* cppScore = new Score(30, "C++");
		Score* algoScore = new Score(59, "Algorithm");
		Score* javaScore = new Score(87, "Java");
		Score* dataCommScore = new Score(74, "Data Comm");
		Score* androidScore = new Score(41, "Android");

		scores.push_back(cppScore);
		scores.push_back(algoScore);
		scores.push_back(javaScore);
		scores.push_back(dataCommScore);
		scores.push_back(androidScore);

		PrintVector(scores);

		vector<Score*>::iterator iter = scores.begin();
		while (iter != scores.end())
		{
			Score* score = *iter;
			if (score->GetClassName() == "Java")
			{
				// 지워도 괜찮다. 각 아이템 별로 주소를 백업해놓았으니 말이다.
				iter = scores.erase(iter);
			}
			else
			{
				iter++;
			}
		}

		PrintVector(scores);

		for (vector<Score*>::iterator iter = scores.begin(); iter != scores.end(); ++iter)
		{
			// 값 복사지만 포인터 주소이다.
			Score* score = *iter;

			if (score->GetScore() == 30)
			{
				// 원본에 값 변경이 일어난다.
				// 이유는? 벡터의 요소들은 개체의 포인터를 가지고 있고 아래 코드는 해당 요소의 포인터를
				//        역참조하여 원본 개체의 SetScore 함수를 호출하기 때문이다.
				score->SetScore(100);
			}
		}

		cout << "After chaning the score of class 1" << endl;
		PrintVector(scores);

		for (vector<Score*>::iterator iter = scores.begin(); iter != scores.end(); ++iter)
		{
			delete *iter;
		}

		// delete cppScore;
		// delete algoScore;
		delete javaScore;
		// delete dataCommScore;
		// delete androidScore;
	}

	void PrintVector(const vector<Score*>& scores)
	{
		for (vector<Score*>::const_iterator iter = scores.begin(); iter != scores.end(); iter++)
		{
			Score* score = *iter;
			score->PrintVariables();
		}
		cout << endl;
	}
}