#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getSolution(vector<int> numbers)
{
    // 입력값이 비어있으면 그대로 반환하여 종료.
    if (numbers.empty())
        return numbers;

    // 결과를 담을 벡터를 생성.
    vector<int> resultVector;

    // 입력값으로 더하기 계산.
    for (vector<int>::iterator numberIndex = numbers.begin(); numberIndex != numbers.end(); ++numberIndex)
    {
        // 현재 이터레이터의 값.
        int number = *numberIndex;

        // 마지막이면 다음값이랑 더할것 없으므로 하지않음.
        if (numberIndex == numbers.end())
            continue;

        // 현재 값과 더할 다음 값을 가져오기.
        for (vector<int>::iterator targetNumberIndex = numberIndex + 1; targetNumberIndex != numbers.end(); ++targetNumberIndex)
        {
            // 다음 값.
            int nextNumber = *targetNumberIndex;

            // 현재 값과 다음 값 더하여 백터에 담아두기.
            int result = number + nextNumber;
            resultVector.push_back(result);
        }
    }

    // 백터를 정렬하고 중복값을 제거한다.
    sort(resultVector.begin(), resultVector.end());
    resultVector.erase(unique(resultVector.begin(), resultVector.end()), resultVector.end());

    return resultVector;
}

int main()
{
    vector<int> answer;
    answer.push_back(2);
    answer.push_back(1);
    answer.push_back(3);
    answer.push_back(4);
    answer.push_back(1);

    vector<int> result = getSolution(answer);

    return 0;
}