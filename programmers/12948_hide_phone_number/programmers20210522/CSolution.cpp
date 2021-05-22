#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string>

using namespace std;

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
string setNumberHide(string phone_number)
{
    // ��ȭ��ȣ�� ������ ���� ������ ���� ����.    
    if (phone_number.empty())
        return "";

    // ��ȭ��ȣ ���ڼ��� 4�ڸ� ���ϸ� �� �ʿ䰡 ����.
    int phone_length = phone_number.size();
    if (phone_length < 4)
        return phone_number;

    for (auto numberIndex = 0; numberIndex < phone_length - 4; numberIndex++)
    {
        // ������ 4�ڸ������� ���� ��ȣȭ.
        phone_number.replace(numberIndex, 1, "*");
    }

    // ����� ��ȭ��ȣ�� ����.
    return phone_number;
}

int main()
{
    string result = setNumberHide("01033334444");
    return 0;
}