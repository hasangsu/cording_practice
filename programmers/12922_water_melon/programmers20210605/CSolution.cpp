#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
    // �ܾ �ݺ��� Ƚ��.
    int count = n / 2;
    bool isEven = true;
    if (n % 2 != 0)
    {
        isEven = false;;
    }

    // �ܾ� �ݺ�.
    string answer = "";
    while (count--)
        answer += "����";

    // Ȧ���϶� �߰�ó��.
    if (!isEven)
        answer += "��";

    // ��ȯ.
    return answer;
}

int main()
{
    string result = solution(3);
    return 0;
}