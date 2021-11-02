#include <stdio.h>
#include <stdlib.h>

int x, y;

int main()
{

    scanf("%d %d", &x, &y);

    char antijebol[y + 1][x + 1];
    for (int i = 0; i <= y; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            scanf("%c", &antijebol[i][j]);
        }
    }
    for (int j = 0; j <= x; j++)
    {
        for (int i = 0; i <= y; i++)
        {
            if (antijebol[i][j] == '~' && antijebol[i][j + 1] == '#')
            {
                if (antijebol[i + 1][j] == 46)
                    antijebol[i + 1][j] = '~';
                if (antijebol[i - 1][j] == '.')
                {
                    antijebol[i - 1][j] = '~';
                    i = 0;
                }
            }
            if (antijebol[i][j] == '~' && antijebol[i][j + 1] == '.')
                antijebol[i][j + 1] = 126;
        }
    }
    for (int i = 0; i <= y; i++)
    {
        if (antijebol[i][x] == 126)
        {
            printf("Siluman ambis!");
            break;
        }
        else if (i == y)
        {
            printf("Nah gini kan kane");
            break;
        }
    }
    return 0;
}