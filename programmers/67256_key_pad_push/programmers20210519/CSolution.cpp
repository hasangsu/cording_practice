#include <string>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;

string getKeyboardOrder(vector<int> numbers, string hand)
{
    if (numbers.empty())
        return "";

    if (hand.compare("right") != 0 && hand.compare("left") != 0)
        return "";

    // �ӽ� Ű�е� �迭 �����ϱ�.
    int number_array[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {-1, 0, -2},
    };

    // Ű�е� �� �����.
    map<int, string> number_map;
    number_map.insert(pair<int, string> (1, "L"));
    number_map.insert(pair<int, string> (2, ""));
    number_map.insert(pair<int, string> (3, "R"));
    number_map.insert(pair<int, string> (4, "L"));
    number_map.insert(pair<int, string> (5, ""));
    number_map.insert(pair<int, string> (6, "R"));
    number_map.insert(pair<int, string> (7, "L"));
    number_map.insert(pair<int, string> (8, ""));
    number_map.insert(pair<int, string> (9, "R"));
    number_map.insert(pair<int, string> (0, ""));

    // Ű�е� �Է��� ��� �� ���� ����Ͽ����� ��� ����.
    string order = "";
    int last_left = -1;
    int last_right = -2;
    
    // �Է� Ű�е� loop.
    for (auto numberIndex = numbers.begin(); numberIndex != numbers.end(); ++numberIndex)
    {
        int number = *numberIndex;
        if (number < 0)
            continue;

        string find_hand = number_map[number];
        if (!find_hand.empty())
        {
            // map�� �̹� ��� �� ���� ������� ���ǵǾ������� �״�� order ����.
            order.append(find_hand);

            // ������ ��� �� ����.
            if (find_hand.compare("L") == 0)
                last_left = number;
            else if (find_hand.compare("R") == 0)
                last_right = number;
        }
        else
        {
            // map�� �̹� ��� �� ���� ������� ���ǵǾ����� ������, ��� ������ �Ǵ��ϱ�.
            int rowSize = sizeof(number_array) / sizeof(number_array[0]);
            int columnSize = sizeof(number_array[0]) / sizeof(int);
            
            // ����, ������, Ÿ���� �迭 ��ġ ���ϱ� pair (int ��, int ��).
            int leftX = 0;
            int leftY = 0;
            int rightX = 0;
            int rightY = 0;
            int targetX = 0;
            int targetY = 0;

            for (int rowIndex = 0; rowIndex < rowSize; rowIndex++)
            {
                for (int columnIndex = 0; columnIndex < columnSize; columnIndex++)
                {
                    int find_number = number_array[rowIndex][columnIndex];
                    if (find_number == last_left)
                    { 
                        leftX = rowIndex;
                        leftY = columnIndex;
                    }
                    if (find_number == last_right)
                    {
                        rightX = rowIndex;
                        rightY = columnIndex;
                    }
                    if (find_number == number)
                    {
                        targetX = rowIndex;
                        targetY = columnIndex;
                    }
                }
            }

            // ã�� �迭 ��ġ�� ����� �� ���ϱ�.
            int leftMoveCount = abs(targetX - leftX) + abs(targetY - leftY);
            int rightMoveCount = abs(targetX - rightX) + abs(targetY - rightY);
            
            if (rightMoveCount < leftMoveCount)
            {
                // �������� �����̴� �Ÿ��� �ּҶ�� �������� ���.
                order.append("R");

                // ������ ��� �� ����.
                last_right = number;
            }
            else if (leftMoveCount < rightMoveCount)
            {
                // ������ �����̴� �Ÿ��� �ּҶ�� ���� ���.
                order.append("L");

                // ������ ��� �� ����.
                last_left = number;
            }
            else if (rightMoveCount == leftMoveCount)
            {
                // ��� ��� �����̴� �Ÿ��� ���ٸ� ������� ���ֻ���ϴ� ��������.
                if (hand.compare("right") == 0)
                {
                    // �������� �����̴� �Ÿ��� �ּҶ�� �������� ���.
                    order.append("R");

                    // ������ ��� �� ����.
                    last_right = number;
                }
                else if (hand.compare("left") == 0)
                {
                    // ������ �����̴� �Ÿ��� �ּҶ�� ���� ���.
                    order.append("L");

                    // ������ ��� �� ����.
                    last_left = number;
                }
            }
        }
    }

    return order;
}

int main() {
    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(5);
    numbers.push_back(8);
    numbers.push_back(0);
    numbers.push_back(8);
    numbers.push_back(3);
    numbers.push_back(1);
    numbers.push_back(5);
    numbers.push_back(7);
    numbers.push_back(6);
    numbers.push_back(2);
        
    string hand = "left";
    string answer = getKeyboardOrder(numbers, hand);

    return 0;
}