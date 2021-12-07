#include <stdio.h>

int main()
{
    int A, B;
    long long a, b, data_a[1000000], data_b[100000];
    scanf("%d", &A);
    for (int i = 1; i <= A; i++)
    {
        scanf("%d", &B);
        for (int j = 1; j < B; j++)
            scanf("%lld", &data_a[j]);

        for (int k = 1; k <= B; k++)
            scanf("%lld", &data_b[k]);

        for (int l = 1; l <= B; l++)
        {
            a = data_a[l];
            b = data_b[l];
            if (a != b)
            {
                a = b;
                break;
            }
        }
        printf("%lld\n", a);
    }
}