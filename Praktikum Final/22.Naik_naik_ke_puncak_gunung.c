/*
https://www.hackerrank.com/contests/dasprog-fp-2021/challenges/naik-naik-ke-puncak-gunung
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int P;
    while (scanf("%d", &P) != EOF)
    {
        if (P == -1)
        {
            break;
        }
        int K[P + 1], Hasil = 0;
        for (int i = 0; i <= P; i++)
        {
            scanf("%d", &K[i]);

            if (K[i] > Hasil)
            {
                Hasil = K[i];
            }
        }
        char Temp[Hasil + 1][P + 1];
        for (int i = 0; i <= Hasil; i++)
        {
            for (int j = 0; j < P; j++)
            {
                Temp[i][j] = ' ';
            }
        }
        for (int i = 1; i <= P; i++)
        {
            if (K[i] > K[i - 1])
            {
                Temp[Hasil - K[i - 1]][i - 1] = '/';
            }
            else if (K[i] < K[i - 1])
            {
                Temp[Hasil - K[i]][i - 1] = '\\';
            }
            else
            {
                Temp[Hasil - K[i]][i - 1] = '_';
            }
        }
        for (int i = 0; i <= Hasil; i++)
        {
            if (i == 0)
            {
                int Temp_1 = 1;
                for (int j = 0; j < P; j++)
                {
                    if (Temp[i][j] != ' ')
                    {
                        Temp_1 = 0;
                        break;
                    }
                }
                if (Temp_1)
                {
                    continue;
                }
            }
            for (int j = 0; j < P; j++)
            {
                printf("%c", Temp[i][j]);
            }
            printf("\n");
        }
        printf("***\n");
    }
    return 0;
}