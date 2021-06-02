#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    // 체육 수업을 듣는 학생수가 없다면 종료.
    if (n < 1)
        return 0;

    // 체육복이 없는 학생이 없으므로 학생수 반환하고 종료.
    if (lost.empty())
        return n;

    // 중복 번호 찾기.
    vector<int> interactionVector;
    for (int reserveIndex = 0; reserveIndex < reserve.size(); reserveIndex++)
    {
        int number = reserve.at(reserveIndex);

        vector<int>::iterator lostIterator = std::find(lost.begin(), lost.end(), number);
        if (lostIterator != lost.end())
        {
            // 중복.
            interactionVector.push_back(number);
        }
    }

    // 여벌의 체육복이 있었지만 도둑맞아서 빌려줄 수 없는 경우.
    for (int interactionIndex = 0; interactionIndex < interactionVector.size(); interactionIndex++)
    {
        int interactionNumber = interactionVector.at(interactionIndex);
        vector<int>::iterator interactionIterator1 = std::find(lost.begin(), lost.end(), interactionNumber);
        vector<int>::iterator interactionIterator2 = std::find(reserve.begin(), reserve.end(), interactionNumber);
        if (interactionIterator1 != lost.end())
        {
            // 여벌이 있었지만 도둑맞아서 빌려줄 수 없을 때.
            lost.erase(interactionIterator1);
        }

        if (interactionIterator2 != reserve.end())
        {
            // 여벌이 있었지만 도둑맞아서 빌려줄 수 없을 때.
            reserve.erase(interactionIterator2);
        }
    }

    // 체육복을 빌리지 않아도 체육 수업을 들을 수 있는 학생 수.
    int count = n - lost.size();

    // 여벌의 체육복이 있는 학생들을 확인하여 빌려주기.
    for (int reserveIndex = 0; reserveIndex < reserve.size(); reserveIndex++)
    {
        // 여벌 체육복을 가져온 학생 번호.
        int reserveNumber = reserve.at(reserveIndex);

        // 체격조건으로 인하여 자기자신, -1, +1의 학생에게만 빌려줄 수 있음.
        int beforeNumber = reserveNumber - 1;
        int afterNumber = reserveNumber + 1;

        // 학생 이터레이터 찾기.
        vector<int>::iterator beforeIterator = std::find(lost.begin(), lost.end(), beforeNumber);
        vector<int>::iterator afterIterator = std::find(lost.begin(), lost.end(), afterNumber);

        if (beforeIterator != lost.end())
        {
            // 체격이 비슷한 앞 번호 학생이 있을경우.
            lost.erase(beforeIterator);

            // 체육복을 빌려서 체육 수업 참여 가능한 학생수 더해주기.
            count += 1;
            continue;
        }

        if (afterIterator != lost.end())
        {
            // 체격이 비슷한 뒤 번호 학생이 있을경우.
            lost.erase(afterIterator);

            // 체육복을 빌려서 체육 수업 참여 가능한 학생수 더해주기.
            count += 1;
            continue;
        }
    }

    return count;
}

int main()
{
    // 체육 수업을 듣는 전체 학생 수.
    int n = 5;

    // 체육복이 없는 학생들.
    vector<int> lost;
    lost.push_back(5);
    lost.push_back(4);
    lost.push_back(2);

    // 여벌의 체육복이 있어서 빌려줄 수 있는 학생들.
    vector<int> reserve;
    reserve.push_back(2);
    reserve.push_back(4);

    int answer = solution(n, lost, reserve);
    return 0;
}