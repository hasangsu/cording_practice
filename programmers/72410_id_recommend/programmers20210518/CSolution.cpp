#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

string createId(string new_id)
{
    string id = new_id;

    // process 1 (대문자를 전부 소문자로 변경).
    std::transform(id.begin(), id.end(), id.begin(), ::tolower);

    // process 2 (정규식에 일치하지 않는 문자들은 전부 제거하기).
    regex regex_pattern1("[^a-z0-9-_.]");
    id = std::regex_replace(id, regex_pattern1, "");

    // process 3. (마침표 2개이상연결은 1개로 변경하기).
    regex regex_pattern2("[.]+");
    id = std::regex_replace(id, regex_pattern2, ".");

    // process 4. (마침표가 처음과 끝이라면 제거하기). 처음과 끝에 마침표인지 체크하는 정규식이 있을까?.
    if (!id.empty() && id.find_first_of(".") == 0)
        id.erase(id.begin());
    if (!id.empty() && id.find_last_of(".") == id.length() - 1)
        id.erase(id.end() - 1);

    // process 5. (id가 비어있다면 a를 넣어주기).
    if (id.empty())
        id = "a";

    // process 6. (16자리가 넘어가면 마지막부터 제거하여 15자리를 만들고, 마지막이 마침표라면 제거하기).
    while (1)
    {
        // id의 길이.
        int id_length = id.length();
        if (id_length < 16)
        {
            // id의 길이가 16이하 이지만, 마지막이 마침표인경우 마침표 지워주기.
            if (id.find_last_of(".") == id.length() - 1)
                id.erase(id.end() - 1);

            break;
        }

        id.erase(id.end() - 1);
    }

    // process 7. (2자리 이하라면 마지막문제를 복사하여 3자리로 만들어주기).
    while (1)
    {
        // id의 길이.
        int id_length = id.length();

        if (3 <= id_length)
        {
            // id의 길이가 3자리 이상이라면 종료.
            break;
        }

        // 마지막 문자를 찾아서 마지막에 추가하기.
        if (id.empty())
            id = "a";

        char last_char = id.back();
        id.push_back(last_char);
    }

    return id;
}
int main()
{
    string answer = createId("=.=");
    //string answer = createId("b.%$");
    return 0;
}