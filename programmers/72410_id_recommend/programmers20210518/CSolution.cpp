#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

string createId(string new_id)
{
    string id = new_id;

    // process 1 (�빮�ڸ� ���� �ҹ��ڷ� ����).
    std::transform(id.begin(), id.end(), id.begin(), ::tolower);

    // process 2 (���ԽĿ� ��ġ���� �ʴ� ���ڵ��� ���� �����ϱ�).
    regex regex_pattern1("[^a-z0-9-_.]");
    id = std::regex_replace(id, regex_pattern1, "");

    // process 3. (��ħǥ 2���̻󿬰��� 1���� �����ϱ�).
    regex regex_pattern2("[.]+");
    id = std::regex_replace(id, regex_pattern2, ".");

    // process 4. (��ħǥ�� ó���� ���̶�� �����ϱ�). ó���� ���� ��ħǥ���� üũ�ϴ� ���Խ��� ������?.
    if (!id.empty() && id.find_first_of(".") == 0)
        id.erase(id.begin());
    if (!id.empty() && id.find_last_of(".") == id.length() - 1)
        id.erase(id.end() - 1);

    // process 5. (id�� ����ִٸ� a�� �־��ֱ�).
    if (id.empty())
        id = "a";

    // process 6. (16�ڸ��� �Ѿ�� ���������� �����Ͽ� 15�ڸ��� �����, �������� ��ħǥ��� �����ϱ�).
    while (1)
    {
        // id�� ����.
        int id_length = id.length();
        if (id_length < 16)
        {
            // id�� ���̰� 16���� ������, �������� ��ħǥ�ΰ�� ��ħǥ �����ֱ�.
            if (id.find_last_of(".") == id.length() - 1)
                id.erase(id.end() - 1);

            break;
        }

        id.erase(id.end() - 1);
    }

    // process 7. (2�ڸ� ���϶�� ������������ �����Ͽ� 3�ڸ��� ������ֱ�).
    while (1)
    {
        // id�� ����.
        int id_length = id.length();

        if (3 <= id_length)
        {
            // id�� ���̰� 3�ڸ� �̻��̶�� ����.
            break;
        }

        // ������ ���ڸ� ã�Ƽ� �������� �߰��ϱ�.
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