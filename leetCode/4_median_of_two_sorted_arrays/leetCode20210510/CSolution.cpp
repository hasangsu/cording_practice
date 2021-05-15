#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMedianSortedArrays(vector<int> *vector1, vector<int> * vector2)
{
	// can not ref.
	if (!vector1 && !vector2)
		return 0;

	// is all vectors is empty?.
	bool isVector1Empty = true;
	bool isVector2Empty = true;
	if (vector1)
		isVector1Empty = vector1->empty();
	if (vector2)
		isVector2Empty = vector2->empty();

	if (isVector1Empty && isVector2Empty)
		return 0;

	// create temp vector.
	vector<int> tempVector;
	if (!isVector1Empty)
	{
		// loop vector1.
		for (auto vectorIndex = vector1->begin(); vectorIndex != vector1->end(); ++vectorIndex)
		{
			int value = *vectorIndex;
			tempVector.push_back(value);
		}
	}
	if (!isVector2Empty)
	{
		// loop vector2.
		for (auto vectorIndex = vector2->begin(); vectorIndex != vector2->end(); ++vectorIndex)
		{
			int value = *vectorIndex;
			tempVector.push_back(value);
		}
	}

	// sort temp vector.
	sort(tempVector.begin(), tempVector.end());

	// get temp vector length.
	int tempVectorLength = tempVector.size();

	// is temp vector length odd & even ?.
	bool isEven = (tempVectorLength % 2) == 0 ? true : false;

	// result.
	double result = 0.0;

	if (isEven)
	{
		// is even.
		int startIndex = (tempVectorLength / 2) - 1;
		int endIndex = (tempVectorLength / 2);

		int startValue = tempVector[startIndex];
		int endValue = tempVector[endIndex];

		result = (startValue + endValue) / 2.0;
	}
	else
	{
		// is odd.
		int startIndex = (tempVectorLength / 2);
		int startValue = tempVector[startIndex];

		result = startValue;
	}

	return result;
}

int main()
{
	// create vector1.
	vector<int> vector1;
	vector1.push_back(1);
	vector1.push_back(2);

	// create vector2.
	vector<int> vector2;
	vector2.push_back(3);
	vector2.push_back(4);

	// result.
	double result = findMedianSortedArrays(&vector1, &vector2);
	cout << "중간값은 : " << result;
	
	return 0;
}