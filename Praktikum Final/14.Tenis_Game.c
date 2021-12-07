// https://www.hackerrank.com/contests/dasprog-fp-2021/challenges/tennis-game-zydhan-slugnya-error-jir-kalo-cuman-tennis-game/submissions/code/1339012770

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define ull unsigned long long

int main()
{
    ull A, B, X;
    scanf("%llu %llu %llu", &A, &B, &X);

    bool STATUS;
    if (A > X || B > X)
        STATUS = 0;

    else if (A == X)
    {
        if (B == 1)
            STATUS = 1;

        else
            STATUS = 0;
    }
    else if (B == X)
        STATUS = 0;

    else
    {
        if (A * B > X)
            STATUS = 0;

        else if (A * B == X)
            STATUS = 1;

        else
        {
            if (A == 2)
            {
                if (X % 2 != 0)
                    STATUS = 0;

                else
                    STATUS = 1;
            }
            else
            {
                if (B == 1)
                {
                    if (X % 2 != 0)
                        STATUS = 0;

                    else
                        STATUS = 1;
                }
                else
                {
                    STATUS = 1;
                }
            }
        }
    }

    if (STATUS)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}