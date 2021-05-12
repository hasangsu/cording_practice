#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int maximumScore(int number1, int number2, int number3)
{
	// create temp vector.
	vector<int> tempVector;
	tempVector.push_back(number1);
	tempVector.push_back(number2);
	tempVector.push_back(number3);

	if (tempVector.size() != 3)
		return 0;

	// buble sort.
	int temp = 0;
	for (int bubleIndex1 = 0; bubleIndex1 < tempVector.size() - 1; bubleIndex1++)
	{
		for (int bubleIndex2 = bubleIndex1 + 1; bubleIndex2 < tempVector.size(); bubleIndex2++)
		{
			if (tempVector.at(bubleIndex1) > tempVector.at(bubleIndex2))
			{
				temp = tempVector.at(bubleIndex1);
				tempVector[bubleIndex1] = tempVector.at(bubleIndex2);
				tempVector[bubleIndex2] = temp;
			}
		}
	}

	// init minimum, middle, maximum.
	int minimum = tempVector.at(0);
	int middle = tempVector.at(1);
	int maximum = tempVector.at(2);

	// check score.
	int score = 0;
	if (minimum + middle < maximum)
	{
		score = minimum + middle;
	}
	else
	{
		score = (minimum + middle + maximum) / 2;
	}

	return score;
}

int main()
{
	int number1 = 2;
	int number2 = 4;
	int number3 = 6;
	int result = maximumScore(number1, number2, number3);
	cout << result << endl;
	return 0;

}