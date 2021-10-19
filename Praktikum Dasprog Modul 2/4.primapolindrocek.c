#include <stdio.h>
#include <stdbool.h>
#define max 1000000
int main()
{
    int awal = 0;
    int prima[max];
    bool isprime[max];

    for (int i = 0; i <= max; i++)
    {
        isprime[i] = 1;
    }

    // Membuat Bilangan Prima
    for (int i = 2; i <= max; i++)
    {
        if (isprime[i])
        {
            prima[awal++] = i;

            for (int j = i * 2; j <= max; j += i)
                isprime[j] = 0;
        }
    }

    int temp, evl, poli = 0, pal[max];

    // Cek apakah Polianderm
    for (int i = 0; i < awal; i++)
    {
        temp = prima[i];
        evl = 0;
        while (temp > 0)
        {
            evl = evl * 10 + (temp % 10);
            temp /= 10;
        }
        if (evl == prima[i])
        {
            pal[poli++] = evl;
        }
    }

    int n;
    long long int gacha = 1;

    while (scanf("%d", &n) != EOF)
    {
        //for (int i = 1; i <800; i++){
        //  n = i;
        if (n <= 2)
            printf("#%lld : 2\n", gacha++);
        else if (n > pal[poli - 1])
            printf("#%lld : 1003001\n", gacha++);
        else
        {
            for (int i = 0; i < poli; i++)
            {
                if (n <= pal[i])
                {
                    printf("#%lld : %d\n", gacha++, pal[i]);
                    break;
                }
            }
        }
    }
    return 0;
}