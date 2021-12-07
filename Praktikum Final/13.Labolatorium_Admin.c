// https://www.hackerrank.com/contests/dasprog-fp-2021/challenges/admin-lab

#include <stdio.h>
#include <stdlib.h>
#define T 1
#define F 0

int arr[1001];

int main()
{
    int Komputer,
        Switch,
        i, j, k,
        temp, R, LL, S = 0;

    scanf("%d %d", &Komputer, &Switch);
    for (i = 0; i < Switch; i++)
    {
        scanf("%d", &temp);
        for (j = 0; j < temp; j++)
        {
            scanf("%d", &R);
            if (arr[R - 1] == F)
            {
                arr[R - 1] = T;
            }
            else if (arr[R - 1] == T)
            {
                arr[R - 1] = F;
            }
            LL = 0;
            for (k = 0; k < Komputer; k++)
            {
                LL += arr[k];
                if (arr[k] == F)
                {
                    break;
                }
            }
            if (LL == Komputer)
            {
                printf("YES");
                return 0;
            }
        }
    }
    if (S == 0)
    {
        printf("NO");
    }
    return 0;
}
