#include <string>
#include <vector>

using namespace std;

int getSum(vector<int> absolutes, vector<bool> signs)
{
    // 두 벡터의 사이즈가 다르면 다음을 실행하지 않음.
    if (absolutes.size() != signs.size())
        return 0;

    // 결과를 저장할 변수.
    int result = 0;

    // 더할 숫자와 양수음수 판단.
    for (int index = 0; index < absolutes.size(); index++)
    {
        int absolute = absolutes.at(index);
        bool sign = signs.at(index);

        // 양수면 그대로, 음수면 마이너스.
        int temp = sign ? absolute : absolute * -1;

        // 기존값에 더하기.
        result += temp;
    }
    
    return result;
}

int main()
{
    vector<int> absolutes;
    absolutes.push_back(4);
    absolutes.push_back(7);
    absolutes.push_back(12);

    vector<bool> signs;
    signs.push_back(true);
    signs.push_back(false);
    signs.push_back(true);

    int result = getSum(absolutes, signs);
    return 0;
}