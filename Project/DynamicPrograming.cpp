#include "DynamicPrograming.h"

int BiggestSquare(vector<vector<int>> board)
{
    int answer = 0;

    int row = board.size();
    int column = board[0].size();


    // ���� �� �ִ� ���簢���� 1���̰ų� 1�� �ƿ� ���� ���
    if (row == 1)
    {
        answer = board[0][0] == 0 ? 0 : 1;
        return answer;
    }

    for (int y = 0; y < row; ++y)
    {
        for (int x = 0; x < column; ++x)
        {
            // ������ ���� 0�̰ų� üũ�Ҽ� ���� ��ġ��
            if (board[y][x] == 0 ||
                y == 0 || x == 0)
            {
                continue;
            }

            else
            {
                int left = board[y][x - 1];
                int up = board[y - 1][x];
                int leftUp = board[y - 1][x - 1];

                int minNumber = min(min(left, up), leftUp);
                board[y][x] = minNumber + 1;

                answer = board[y][x] >= answer ? board[y][x] : answer;

            }
        }
    }


    return answer * answer;
}