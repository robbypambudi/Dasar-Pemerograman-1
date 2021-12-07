#include "stdio.h"
#define max(a, b) (((a) > (b)) ? (a) : (b))

void Fungsi_1(int DATA[][100], int a, int b, int c, int d, int e, int *MAX)
{
    if (a < 0 || a >= c)
        return;
    if (b < 0 || b >= d)
        return;
    if (DATA[a][b] != e)
        return;
    if (DATA[a][b] == -1)
        return;

    DATA[a][b] = -1;
    *MAX += 1;
    Fungsi_1(DATA, a + 1, b, c, d, e, MAX);
    Fungsi_1(DATA, a - 1, b, c, d, e, MAX);
    Fungsi_1(DATA, a, b + 1, c, d, e, MAX);
    Fungsi_1(DATA, a, b - 1, c, d, e, MAX);
}

int main()
{
    int X, Y;
    scanf("%d %d", &X, &Y);

    int DATA[100][100];

    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            scanf("%d", &DATA[i][j]);
        }
    }
    int temp = 0;
    int MAX = 0;
    for (int i = 0; i < X; i++)
        for (int j = 0; j < Y; j++)
        {
            MAX = 0;

            Fungsi_1(DATA, i, j, X, Y, DATA[i][j], &MAX);
            temp = max(temp, MAX);
        }
    printf("%d\n", temp);
}