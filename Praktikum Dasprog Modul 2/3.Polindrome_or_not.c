#include <stdio.h>

int main()
{
    unsigned long long int x, modd, hasil = 0;
    scanf("%llu", &x);
    unsigned long long int temp = x;

    while (x > 0)
    {
        modd = x % 10;
        hasil = hasil * 10 + modd;
        x /= 10;
    }

    if (temp == hasil)
    {
        printf("YAK BISA\n");
    }
    else
    {
        printf("SALAH BAMBANG\n");
    }
}
