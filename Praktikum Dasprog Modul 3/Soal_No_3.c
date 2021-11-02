#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int N, Jumlah = 0;
void printSolution()
{
    Jumlah += 1;
}

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool selesaikan(int board[N][N], int col)
{

    if (col == N)
    {
        printSolution();
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++)
    {
        /* Check if queen can be placed on
        board[i][col] */
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;

            res = selesaikan(board, col + 1);

            board[i][col] = 0; // BACKTRACK
        }
    }

    return res;
}

void Solve()
{
    int board[N][N];
    memset(board, 0, sizeof(board));

    if (selesaikan(board, 0) == false)
    {
        return;
    }

    return;
}

int main()
{
    scanf("%d", &N);
    Solve();

    printf("%d\n", Jumlah);
}