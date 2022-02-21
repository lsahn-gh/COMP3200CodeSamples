#include <iostream>
#include <vector>
#include "VectorCalculatingSumExample.h"

using namespace std;

namespace samples
{
	int CalculateSum(const vector<int>& scores)
	{
		int sum = 0;

		// '.size()' : 벡터에 저장된 아이템의 갯수만큼 반환
		for (size_t i = 0; i < scores.size(); i++)
		{
			// 'operator[]'가 구현되어 있어 Array 요소 접근하듯이 사용 가능.
			// 반환 타입은 reference 이므로 대입하였을때 벡터 요소가 변경된다.
			sum += scores[i];
		}

		return sum;
	}

	void VectorCalculatingSumExample()
	{
		vector<int> myScores;
		myScores.reserve(5);

		vector<int> yourScores;
		yourScores.reserve(5);

		myScores.push_back(13);
		myScores.push_back(21);
		myScores.push_back(35);
		myScores.push_back(76);
		myScores.push_back(94);

		yourScores.push_back(61);
		yourScores.push_back(27);
		yourScores.push_back(83);
		yourScores.push_back(91);
		yourScores.push_back(100);

		// 'yourScores'에 있는 모든 아이템을 삭제한다.
		yourScores.clear();

		cout << "myScores" << endl;
		cout << "Sum : " << CalculateSum(myScores) << endl << endl;

		cout << "yourScores" << endl;
		cout << "Sum : " << CalculateSum(yourScores) << endl << endl;
	}
}