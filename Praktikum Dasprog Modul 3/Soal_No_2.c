#include <stdio.h>
// Sumber https://www.tutorialspoint.com/sum-triangle-from-an-array-in-c-programming

void cetak(long long arr[], long long int n)
{
    if (n < 1)
    {
        return;
    }
    long long temp[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        unsigned long long int x = arr[i] + arr[i + 1]; // Ditambahkan dengan depanya
        temp[i] = x;                                    // Disimpan dalam array baru
    }
    cetak(temp, n - 1); // Fungsi rekursif
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            printf("%lld ", arr[i]);
        }
        else
        {
            printf("%lld ", arr[i]);
        }
    }
    printf("\n");
}

int main()
{
    unsigned long long int N;
    scanf("%llu", &N);
    long long arr[N];
    int a = 1;
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &arr[i]);
        if (arr[i] <= 0)
        {
            a = 0;
        }
    }

    if (a == 1)
    {
        cetak(arr, N);
    }
}
