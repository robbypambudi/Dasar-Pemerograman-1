#include <stdio.h>
long long int hasil = 1;
void fibonaci(int N)
{
    static int N1 = 0, N2 = 1, N3; // Static Int

    if (N > 0)
    {
        N3 = N1 + N2;
        N1 = N2;
        N2 = N3;
        // printf("%d ", N3);
        hasil = N3;
        fibonaci(N - 1);
    }
}

int main()
{
    int N;
    // printf("Enter the number of elements : ");
    scanf("%d", &N);
    // printf(" 0 1 ");
    fibonaci(N - 1); // Number 1 and 2 already Printed
    if (N == 0)
    {
        printf("0");
    }
    else if (N == 1)
    {
        printf("125");
    }
    else if (N == 2)
    {
        printf("125");
    }
    else
    {
        printf("%lld", hasil * 125);
    }
}