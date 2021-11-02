#include <stdio.h>

long long h, arr[1000][1000];
long long temp[1000][1000];
long long path[1000][1000];
long long min(int x, int y)
{
    if (temp[x][y] != 0)
        return temp[x][y];
    if (x == h)
        return temp[x][y] = arr[x][y];

    if (min(x + 1, y) < min(x + 1, y + 1))
    {
        temp[x][y] = arr[x][y] + min(x + 1, y);
        path[x][y] = '~';
    }
    else
    {
        temp[x][y] = arr[x][y] + min(x + 1, y + 1);
        path[x][y] = 'p';
    }
    return temp[x][y];
}
int main()
{

    scanf("%lld", &h);
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            scanf("%lld", &arr[i][j]);
            temp[i][j] = 0;
        }
    }
    min(1, 1);
    arr[1][1] = -1; // Edited
    int j = 1;
    for (int i = 1; i < h; i++)
    {
        if (path[i][j] == '~')
        {
            arr[i + 1][j] = -1;
        }
        else if (path[i][j] == 'p')
        {
            j++;
            arr[i + 1][j] = -1;
        }
    }

    for (int i = 1; i <= h; i++)
    {
        for (int k = 1; k <= i; k++)
        {
            printf("%lld ", arr[i][k]);
        }
        printf("\n");
    }
}