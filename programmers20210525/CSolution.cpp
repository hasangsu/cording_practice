#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getSolution(vector<int> numbers)
{
    // �Է°��� ��������� �״�� ��ȯ�Ͽ� ����.
    if (numbers.empty())
        return numbers;

    // ����� ���� ���͸� ����.
    vector<int> resultVector;

    // �Է°����� ���ϱ� ���.
    for (vector<int>::iterator numberIndex = numbers.begin(); numberIndex != numbers.end(); ++numberIndex)
    {
        // ���� ���ͷ������� ��.
        int number = *numberIndex;

        // �������̸� �������̶� ���Ұ� �����Ƿ� ��������.
        if (numberIndex == numbers.end())
            continue;

        // ���� ���� ���� ���� ���� ��������.
        for (vector<int>::iterator targetNumberIndex = numberIndex + 1; targetNumberIndex != numbers.end(); ++targetNumberIndex)
        {
            // ���� ��.
            int nextNumber = *targetNumberIndex;

            // ���� ���� ���� �� ���Ͽ� ���Ϳ� ��Ƶα�.
            int result = number + nextNumber;
            resultVector.push_back(result);
        }
    }

    // ���͸� �����ϰ� �ߺ����� �����Ѵ�.
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