#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    // ü�� ������ ��� �л����� ���ٸ� ����.
    if (n < 1)
        return 0;

    // ü������ ���� �л��� �����Ƿ� �л��� ��ȯ�ϰ� ����.
    if (lost.empty())
        return n;

    // �ߺ� ��ȣ ã��.
    vector<int> interactionVector;
    for (int reserveIndex = 0; reserveIndex < reserve.size(); reserveIndex++)
    {
        int number = reserve.at(reserveIndex);

        vector<int>::iterator lostIterator = std::find(lost.begin(), lost.end(), number);
        if (lostIterator != lost.end())
        {
            // �ߺ�.
            interactionVector.push_back(number);
        }
    }

    // ������ ü������ �־����� ���ϸ¾Ƽ� ������ �� ���� ���.
    for (int interactionIndex = 0; interactionIndex < interactionVector.size(); interactionIndex++)
    {
        int interactionNumber = interactionVector.at(interactionIndex);
        vector<int>::iterator interactionIterator1 = std::find(lost.begin(), lost.end(), interactionNumber);
        vector<int>::iterator interactionIterator2 = std::find(reserve.begin(), reserve.end(), interactionNumber);
        if (interactionIterator1 != lost.end())
        {
            // ������ �־����� ���ϸ¾Ƽ� ������ �� ���� ��.
            lost.erase(interactionIterator1);
        }

        if (interactionIterator2 != reserve.end())
        {
            // ������ �־����� ���ϸ¾Ƽ� ������ �� ���� ��.
            reserve.erase(interactionIterator2);
        }
    }

    // ü������ ������ �ʾƵ� ü�� ������ ���� �� �ִ� �л� ��.
    int count = n - lost.size();

    // ������ ü������ �ִ� �л����� Ȯ���Ͽ� �����ֱ�.
    for (int reserveIndex = 0; reserveIndex < reserve.size(); reserveIndex++)
    {
        // ���� ü������ ������ �л� ��ȣ.
        int reserveNumber = reserve.at(reserveIndex);

        // ü���������� ���Ͽ� �ڱ��ڽ�, -1, +1�� �л����Ը� ������ �� ����.
        int beforeNumber = reserveNumber - 1;
        int afterNumber = reserveNumber + 1;

        // �л� ���ͷ����� ã��.
        vector<int>::iterator beforeIterator = std::find(lost.begin(), lost.end(), beforeNumber);
        vector<int>::iterator afterIterator = std::find(lost.begin(), lost.end(), afterNumber);

        if (beforeIterator != lost.end())
        {
            // ü���� ����� �� ��ȣ �л��� �������.
            lost.erase(beforeIterator);

            // ü������ ������ ü�� ���� ���� ������ �л��� �����ֱ�.
            count += 1;
            continue;
        }

        if (afterIterator != lost.end())
        {
            // ü���� ����� �� ��ȣ �л��� �������.
            lost.erase(afterIterator);

            // ü������ ������ ü�� ���� ���� ������ �л��� �����ֱ�.
            count += 1;
            continue;
        }
    }

    return count;
}

int main()
{
    // ü�� ������ ��� ��ü �л� ��.
    int n = 5;

    // ü������ ���� �л���.
    vector<int> lost;
    lost.push_back(5);
    lost.push_back(4);
    lost.push_back(2);

    // ������ ü������ �־ ������ �� �ִ� �л���.
    vector<int> reserve;
    reserve.push_back(2);
    reserve.push_back(4);

    int answer = solution(n, lost, reserve);
    return 0;
}