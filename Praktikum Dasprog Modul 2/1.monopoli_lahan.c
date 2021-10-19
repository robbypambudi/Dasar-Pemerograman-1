#include <stdio.h>
#define MODD 1000000007

int main()
{
    int angka;
    unsigned long long bil, x, data[5];
    scanf("%d", &angka);

    while (angka--)
    {
        x = 0;
        scanf("%llu", &bil);
        for (int i = 0; i < 5; i++)
        {
            data[i] = 0;
        }
        data[0] = 1;
        for (int i = 2; i <= bil; i++)
        {
            data[4] = (data[4] % MODD + data[3] % MODD) % MODD;
            data[3] = (data[3] % MODD + data[2] % MODD) % MODD;
            data[2] = (data[2] % MODD + data[1] % MODD) % MODD;
            data[1] = (data[1] % MODD + data[0] % MODD) % MODD;
            data[0] = 1;
        }
        for (int i = 0; i < 5; i++)
        {
            x = (x + data[i] % MODD) % MODD;
        }
        printf("%lld\n", x);
    }
    return 0;
}