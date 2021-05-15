#include <vector>
#include <algorithm>

using namespace std;

int getKindOfPonketmon(vector<int> ponketmonVector)
{
    // 폰켓몬 벡터가 비어있다면 다음 실행 필요없이 반환.
    if (ponketmonVector.empty())
        return 0;

    // 폰켓몬의 전체 갯수.
    int totalPonketmonCount = ponketmonVector.size();

    // 폰켓몬은 무조건 짝수마리를 주며, 홀수라면 실행하지 않는다는 조건.
    if (totalPonketmonCount % 2 != 0)
        return 0;

    // 선택할 수 있는 폰켓몬은 전체 갯수(N)의 절반.
    int selectCount = totalPonketmonCount / 2;

    // 중복선택없는 폰켓몬을 선택하기 위한 벡터의 중복제거.
    sort(ponketmonVector.begin(), ponketmonVector.end());
    ponketmonVector.erase(unique(ponketmonVector.begin(), ponketmonVector.end()), ponketmonVector.end());

    // 중복제거 후 폰켓몬의 종류 수.
    int kindOfPonketmonCount = ponketmonVector.size();

    if (selectCount <= kindOfPonketmonCount)
    {
        // 전체 폰켓몬의 종류가 선택해야하는 갯수보다 많다면.
        // 어떻게 선택해도 중복이 아니므로, 무조건 선택갯수 반환하면 최대 갯수가 됨.
        return selectCount;
    }
    else
    {
        // 전체 폰켓몬의 종류가 선택해야하는 갯수보다 적다면.
        // 각각의 종류를 선택하면 최대 갯수가 됨.
        return kindOfPonketmonCount;
    }
}

int main()
{
    // 전체 폰켓몬의 벡터.
    vector<int> ponketmonVector;
    ponketmonVector.push_back(1);
    ponketmonVector.push_back(2);
    ponketmonVector.push_back(3);
    ponketmonVector.push_back(4);
    ponketmonVector.push_back(5);
    ponketmonVector.push_back(6);
    ponketmonVector.push_back(7);
    ponketmonVector.push_back(8);

    // 최대 종류의 폰켓몬을 선택 구하기.
    int answer = getKindOfPonketmon(ponketmonVector);
    return answer;
}