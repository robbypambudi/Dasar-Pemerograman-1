#include <stdio.h>
#include <string.h>
#define MOD 1000000007

void make_prime(int prime[])
{
    int i, j;
    for (i = 2; i * i <= 10000; i++)
    {
        if (!prime[i])
        {
            for (j = i * i; j <= 10000; j += i)
                prime[j] = 1;
        }
    }
    prime[0] = 1;
    prime[1] = 1;
}

int main()
{
    int T;

    scanf("%d", &T);
    int prime[10000];
    make_prime(prime);
    int A, B;
    long long result;

    for (int i = 1; i <= T; i++)
    {
        result = 0;
        scanf("%d %d", &A, &B);

        for (int j = 1; j <= B; j++)
        {

            if (j == 1)
            {
                result = ((A % MOD));
            }
            else if (prime[j])
            {

                result = (result % MOD) * ((A - 1) % MOD) % MOD;
            }
            else if (!prime[j])
            {

                result = (result % MOD) * ((A) % MOD) % MOD;
            }
        }
        printf("%lld\n", result);
    }
    return 0;
}