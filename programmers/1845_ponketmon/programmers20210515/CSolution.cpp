#include <vector>
#include <algorithm>

using namespace std;

int getKindOfPonketmon(vector<int> ponketmonVector)
{
    // ���ϸ� ���Ͱ� ����ִٸ� ���� ���� �ʿ���� ��ȯ.
    if (ponketmonVector.empty())
        return 0;

    // ���ϸ��� ��ü ����.
    int totalPonketmonCount = ponketmonVector.size();

    // ���ϸ��� ������ ¦�������� �ָ�, Ȧ����� �������� �ʴ´ٴ� ����.
    if (totalPonketmonCount % 2 != 0)
        return 0;

    // ������ �� �ִ� ���ϸ��� ��ü ����(N)�� ����.
    int selectCount = totalPonketmonCount / 2;

    // �ߺ����þ��� ���ϸ��� �����ϱ� ���� ������ �ߺ�����.
    sort(ponketmonVector.begin(), ponketmonVector.end());
    ponketmonVector.erase(unique(ponketmonVector.begin(), ponketmonVector.end()), ponketmonVector.end());

    // �ߺ����� �� ���ϸ��� ���� ��.
    int kindOfPonketmonCount = ponketmonVector.size();

    if (selectCount <= kindOfPonketmonCount)
    {
        // ��ü ���ϸ��� ������ �����ؾ��ϴ� �������� ���ٸ�.
        // ��� �����ص� �ߺ��� �ƴϹǷ�, ������ ���ð��� ��ȯ�ϸ� �ִ� ������ ��.
        return selectCount;
    }
    else
    {
        // ��ü ���ϸ��� ������ �����ؾ��ϴ� �������� ���ٸ�.
        // ������ ������ �����ϸ� �ִ� ������ ��.
        return kindOfPonketmonCount;
    }
}

int main()
{
    // ��ü ���ϸ��� ����.
    vector<int> ponketmonVector;
    ponketmonVector.push_back(1);
    ponketmonVector.push_back(2);
    ponketmonVector.push_back(3);
    ponketmonVector.push_back(4);
    ponketmonVector.push_back(5);
    ponketmonVector.push_back(6);
    ponketmonVector.push_back(7);
    ponketmonVector.push_back(8);

    // �ִ� ������ ���ϸ��� ���� ���ϱ�.
    int answer = getKindOfPonketmon(ponketmonVector);
    return answer;
}