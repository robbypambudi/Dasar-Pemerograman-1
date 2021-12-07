// https://www.hackerrank.com/contests/dasprog-fp-2021/challenges/pic-internal-game
#include <stdio.h>

int main()
{
    long long int N;
    scanf("lld", &N);

    if (N % 2 == 0)
    {
        printf("Nopal\n");
    }
    else
    {
        printf("Zydhan\n");
    }
}