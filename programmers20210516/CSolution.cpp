#include <string>
#include <vector>
#include <stack>

using namespace std;

int main(vector<vector<int>> board, vector<int> moves)
{
    // �����̱� ĭ�� ���� ����� ���� ��쿡�� ���� ������ �����Ƿ� ���� ��� �������� ����.
    if (board.empty())
        return 0;

    // ������ ��Ƶ� �� �ִ� �ٱ���.
    stack<int> porket;

    // �������� ���� ������ ���� ī��Ʈ.
    int correctCount = 0;

    // �����̱� ũ���� �̵� ��ġ (�ڿ���).
    for (int moveIndex = 0; moveIndex < moves.size(); moveIndex++)
    {
        // �迭�� �ε����� ��ġ��Ű�� ���ؼ� 0���� ������ �� �ֵ��� -1.
        int move = moves.at(moveIndex) - 1;
        if (move < 0)
            continue;

        // �����̱⸦ ���ڷ� ��ȯ���� ��, ���� ���پ� loop.
        for (auto boardIndex = 0; boardIndex < board.size(); boardIndex++)
        {
            vector<int> rowVector = board.at(boardIndex);
            if (rowVector.empty())
                continue;

            // ���ں��� ���ų� ���� �̵��� �� ����.
            if (rowVector.size() < move)
                continue;

            // ũ������ ��ġ���� ������ �̾��� ��, �ƹ��͵� ���� ��쿡�� ���� �������� ����.
            int select = rowVector.at(move);
            if (select <= 0)
                continue;

            if (porket.empty())
            {
                // ���ݱ��� ���� ������ ������� �׳� �ٱ��Ͽ� ��Ƶα�.
                porket.push(select);
            }
            else
            {
                // ������ �̾��� �� �ٷ� ������ ���� ������ ��ġ�ϴ��� �Ǵ��ϱ� ����.
                int topDoll = porket.top();
                if (topDoll == select)
                {
                    // ������ ���� ������ ���λ��� ������ ���� �����̶��, �ٱ��Ͽ��� �����ϰ� ����1�� �ø���.
                    porket.pop();
                    correctCount++;
                }
                else
                {
                    // ������ ���� ������ ���λ��� ������ �ٸ� �����̶��, �׳� �ٱ��Ͽ� ��Ƶα�.
                    porket.push(select);
                }
            }

            // ������ �̾Ҵٸ� ���� ������ ��ġ�� ������� �ǹǷ� 0���� �����ϱ�.
            board[boardIndex][move] = 0;
            break;
        }
    }
    
    // ���� ������ ���� ȸ���� ���ϱ� 2���ؾ� �� ���� ������ ���� ������ ����.
    return correctCount * 2;
}