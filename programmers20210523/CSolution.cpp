#include <vector>
#include <iostream>

using namespace std;

vector<int> deduplication(vector<int> arr)
{
    // ����ִٸ� ���� ���μ��� ���� �ʿ�����Ƿ� �״�� ��ȯ.
    if (arr.empty())
        return arr;

    vector<int> tempArray;

    // ó������ ���������� ���鼭 �ߺ��� ��.
    for (vector<int>::iterator arrIndex = arr.begin(); arrIndex != arr.end(); ++arrIndex)
    {
        // ���� iterator.
        vector<int>::iterator currentIterator = arrIndex;

        // ���� iterator�� ��.
        int currentValue = *currentIterator;

        // ���� iterator�� ó���̸�, ������ �����Ƿ� ����� �־��ְ� �������� �Ѿ.
        if (currentIterator == arr.begin())
        {
            tempArray.push_back(currentValue);
            continue;
        }

        // ���� iterator.
        vector<int>::iterator beforeIterator = arrIndex - 1;
        
        // ���� iterator�� ��.
        int beforeValue = *beforeIterator;

        // ����� ������ ���� ���ٸ� ����� ���� ����.
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