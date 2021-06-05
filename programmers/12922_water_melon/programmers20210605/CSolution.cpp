#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
    // 단어를 반복할 횟수.
    int count = n / 2;
    bool isEven = true;
    if (n % 2 != 0)
    {
        isEven = false;;
    }

    // 단어 반복.
    string answer = "";
    while (count--)
        answer += "수박";

    // 홀수일때 추가처리.
    if (!isEven)
        answer += "수";

    // 반환.
    return answer;
}

int main()
{
    string result = solution(3);
    return 0;
}