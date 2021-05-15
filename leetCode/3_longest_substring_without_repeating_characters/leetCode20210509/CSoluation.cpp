#include <stdio.h>
#include <string>
#include <iostream>
#include <list>
#include <vector>

// namesapce 사용하는 이유?.
using namespace std;

// get longest substring.
int lengthOfLongestSubstring(string text)
{
	// text length is empty - can not process.
	if (text.empty())
		return 0;

	// get char list - text parsing.
	vector<char> charVector;
	for (string::iterator string_index = text.begin(); string_index != text.end(); ++string_index)
	{
		// get one text.
		char one_char = *string_index;

		// append char to list.
		charVector.push_back(one_char);
	}

	// char list is empty - can not process.
	if (charVector.empty())
		return 0;

	int longestCount = 0;
	for (int originalIndex = 0; originalIndex < charVector.size(); originalIndex++)
	{
		// original char.
		char original_char = charVector[originalIndex];

		// temp string.
		string tempString = "";
		tempString.push_back(original_char);

		// comapre char loop.
		for (int compareIndex = originalIndex + 1; compareIndex < charVector.size(); compareIndex++)
		{
			char compare_char = charVector[compareIndex];
			
			// check already char.
			bool overlap = false;

			// find char.
			size_t findSize = tempString.find(compare_char);
			if (findSize != string::npos)
			{
				// find success.
				overlap = true;
				break;
			}
			else
			{
				// find fail.
				overlap = false;
				tempString.push_back(compare_char);
			}
		}

		// old longest to new longes comapre.
		int tempLongest = tempString.size();
		if (longestCount < tempLongest)
		{
			longestCount = tempLongest;
		}
	}

	// return longest count.
	return longestCount;
}

int main()
{
	// out put text.
	int result = lengthOfLongestSubstring("abcabcbb");
	cout << "연속된 최대 갯수는 : " << result << endl;
	return 0;
}

