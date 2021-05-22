#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string>

using namespace std;

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
string setNumberHide(string phone_number)
{
    // 전화번호가 없으면 다음 진행을 하지 않음.    
    if (phone_number.empty())
        return "";

    // 전화번호 글자수가 4자리 이하면 할 필요가 없음.
    int phone_length = phone_number.size();
    if (phone_length < 4)
        return phone_number;

    for (auto numberIndex = 0; numberIndex < phone_length - 4; numberIndex++)
    {
        // 마지막 4자리전까지 전부 암호화.
        phone_number.replace(numberIndex, 1, "*");
    }

    // 변경된 전화번호를 리턴.
    return phone_number;
}

int main()
{
    string result = setNumberHide("01033334444");
    return 0;
}