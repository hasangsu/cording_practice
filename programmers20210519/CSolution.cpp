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

    // 임시 키패드 배열 생성하기.
    int number_array[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {-1, 0, -2},
    };

    // 키패드 맵 만들기.
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

    // 키패드 입력을 어느 쪽 손을 사용하였는지 결과 저장.
    string order = "";
    int last_left = -1;
    int last_right = -2;
    
    // 입력 키패드 loop.
    for (auto numberIndex = numbers.begin(); numberIndex != numbers.end(); ++numberIndex)
    {
        int number = *numberIndex;
        if (number < 0)
            continue;

        string find_hand = number_map[number];
        if (!find_hand.empty())
        {
            // map에 이미 어느 쪽 손을 사용할지 정의되어있으면 그대로 order 지정.
            order.append(find_hand);

            // 마지막 사용 손 저장.
            if (find_hand.compare("L") == 0)
                last_left = number;
            else if (find_hand.compare("R") == 0)
                last_right = number;
        }
        else
        {
            // map에 이미 어느 쪽 손을 사용할지 정의되어있지 않으면, 어느 손인지 판단하기.
            int rowSize = sizeof(number_array) / sizeof(number_array[0]);
            int columnSize = sizeof(number_array[0]) / sizeof(int);
            
            // 왼쪽, 오른쪽, 타겟의 배열 위치 구하기 pair (int 행, int 렬).
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

            // 찾은 배열 위치로 가까운 손 구하기.
            int leftMoveCount = abs(targetX - leftX) + abs(targetY - leftY);
            int rightMoveCount = abs(targetX - rightX) + abs(targetY - rightY);
            
            if (rightMoveCount < leftMoveCount)
            {
                // 오른쪽이 움직이는 거리가 최소라면 오른쪽을 사용.
                order.append("R");

                // 마지막 사용 손 저장.
                last_right = number;
            }
            else if (leftMoveCount < rightMoveCount)
            {
                // 왼쪽이 움직이는 거리가 최소라면 왼쪽 사용.
                order.append("L");

                // 마지막 사용 손 저장.
                last_left = number;
            }
            else if (rightMoveCount == leftMoveCount)
            {
                // 양손 모두 움직이는 거리가 같다면 사용자의 자주사용하는 방향으로.
                if (hand.compare("right") == 0)
                {
                    // 오른쪽이 움직이는 거리가 최소라면 오른쪽을 사용.
                    order.append("R");

                    // 마지막 사용 손 저장.
                    last_right = number;
                }
                else if (hand.compare("left") == 0)
                {
                    // 왼쪽이 움직이는 거리가 최소라면 왼쪽 사용.
                    order.append("L");

                    // 마지막 사용 손 저장.
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