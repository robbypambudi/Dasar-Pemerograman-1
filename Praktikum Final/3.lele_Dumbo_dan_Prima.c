#include <stdio.h>

void make_prima(int N, int data[])
{
    int i, j;
    for (i = 2; i * i <= N; i++)
    {
        if (!data[i])
        {
            for (j = i * i; j <= N; j += i)
                data[j] = 1;
        }
    }
    data[1] = 1;
}

int cek_prime(int x)
{
    int i;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    if (x == 1)
    {
        return 0;
    }
    return 1;
}

int number(int x, int y)
{
    int heru = 1, heru_sementara = y;
    while (heru_sementara > 0)
    {
        heru *= 10;
        heru_sementara /= 10;
    }
    return x * heru + y;
}

int main()
{
    int MAX = 1000000;
    int data[MAX + 1];
    make_prima(MAX, data);

    int a, b, ROBBY = 0;
    scanf("%d %d", &a, &b);
    int i, j;

    for (i = a; i <= b; i++)
    {
        for (j = a; j <= b; j++)
        {
            if (data[i] || data[j])
                continue;

            // Counting Number

            int result = number(i, j);

            if (result > MAX && cek_prime(result))
            {
                printf("%d %d\n", i, j);
                ROBBY += 1;
            }
            else if (result <= MAX && !data[result])
            {
                printf("%d %d\n", i, j);
                ROBBY += 1;
            }
        }
    }
    if (!ROBBY)
    {
        printf("TIDAK ADA\n");
    }
    return 0;
}