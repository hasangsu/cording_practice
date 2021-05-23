#include <vector>
#include <iostream>

using namespace std;

vector<int> deduplication(vector<int> arr)
{
    // 비어있다면 다음 프로세스 진행 필요없으므로 그대로 반환.
    if (arr.empty())
        return arr;

    vector<int> tempArray;

    // 처음부터 마지막까지 돌면서 중복값 비교.
    for (vector<int>::iterator arrIndex = arr.begin(); arrIndex != arr.end(); ++arrIndex)
    {
        // 현재 iterator.
        vector<int>::iterator currentIterator = arrIndex;

        // 현재 iterator의 값.
        int currentValue = *currentIterator;

        // 현재 iterator이 처음이면, 이전은 없으므로 결과에 넣어주고 다음으로 넘어감.
        if (currentIterator == arr.begin())
        {
            tempArray.push_back(currentValue);
            continue;
        }

        // 이전 iterator.
        vector<int>::iterator beforeIterator = arrIndex - 1;
        
        // 이전 iterator의 값.
        int beforeValue = *beforeIterator;

        // 현재와 이전의 값이 같다면 결과에 넣지 않음.
        if (currentValue == beforeValue)
            continue;

        tempArray.push_back(currentValue);
    }

    return tempArray;
}

int main()
{
    vector<int> tempArray;
    tempArray.push_back(4);
    tempArray.push_back(4);
    tempArray.push_back(4);
    tempArray.push_back(3);
    tempArray.push_back(3);
    tempArray.push_back(1);
    tempArray.push_back(1);

    vector<int> result = deduplication(tempArray);
    return 0;
}