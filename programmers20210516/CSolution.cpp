#include <string>
#include <vector>
#include <stack>

using namespace std;

int main(vector<vector<int>> board, vector<int> moves)
{
    // 인형뽑기 칸이 전부 비워져 있을 경우에는 뽑을 인형이 없으므로 다음 기능 실행하지 않음.
    if (board.empty())
        return 0;

    // 인형을 담아둘 수 있는 바구니.
    stack<int> porket;

    // 연속으로 같은 인형을 뽑은 카운트.
    int correctCount = 0;

    // 인형뽑기 크레인 이동 위치 (자연수).
    for (int moveIndex = 0; moveIndex < moves.size(); moveIndex++)
    {
        // 배열의 인덱스와 일치시키기 위해서 0부터 시작할 수 있도록 -1.
        int move = moves.at(moveIndex) - 1;
        if (move < 0)
            continue;

        // 인형뽑기를 격자로 변환했을 때, 격자 한줄씩 loop.
        for (auto boardIndex = 0; boardIndex < board.size(); boardIndex++)
        {
            vector<int> rowVector = board.at(boardIndex);
            if (rowVector.empty())
                continue;

            // 격자보다 적거나 많이 이동할 수 없음.
            if (rowVector.size() < move)
                continue;

            // 크레인의 위치에서 인형을 뽑았을 때, 아무것도 없을 경우에는 다음 실행하지 않음.
            int select = rowVector.at(move);
            if (select <= 0)
                continue;

            if (porket.empty())
            {
                // 지금까지 뽑은 인형이 없을경우 그냥 바구니에 담아두기.
                porket.push(select);
            }
            else
            {
                // 인형을 뽑았을 때 바로 이전에 뽑은 인형과 일치하는지 판단하기 위함.
                int topDoll = porket.top();
                if (topDoll == select)
                {
                    // 이전이 뽑은 인형과 새로뽑은 인형이 같은 인형이라면, 바구니에서 제외하고 점수1점 올리기.
                    porket.pop();
                    correctCount++;
                }
                else
                {
                    // 이전이 뽑은 인형과 새로뽑은 인형이 다른 인형이라면, 그냥 바구니에 담아두기.
                    porket.push(select);
                }
            }

            // 인형을 뽑았다면 뽑은 인형의 위치는 비워지게 되므로 0으로 설정하기.
            board[boardIndex][move] = 0;
            break;
        }
    }
    
    // 같은 인형을 뽑은 회수에 곱하기 2를해야 총 같은 인형을 뽑은 인형의 갯수.
    return correctCount * 2;
}