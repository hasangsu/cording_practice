#include <string>
#include <vector>

using namespace std;

int getSum(vector<int> absolutes, vector<bool> signs)
{
    // �� ������ ����� �ٸ��� ������ �������� ����.
    if (absolutes.size() != signs.size())
        return 0;

    // ����� ������ ����.
    int result = 0;

    // ���� ���ڿ� ������� �Ǵ�.
    for (int index = 0; index < absolutes.size(); index++)
    {
        int absolute = absolutes.at(index);
        bool sign = signs.at(index);

        // ����� �״��, ������ ���̳ʽ�.
        int temp = sign ? absolute : absolute * -1;

        // �������� ���ϱ�.
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