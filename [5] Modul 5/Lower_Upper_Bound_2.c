#include <stdio.h>

int main()
{

    int arr[100001];
    int n, number;
    scanf("%d", &n);

    while (n--)
    {
        scanf("%d", &number);
        arr[number] += 1;
    }

    for (int i = 1; i < 100001; i++)
    {
        arr[i] += arr[i - 1];
    }

    int x;
    scanf("%d", &x);

    while (x--)
    {
        int a, b, result;
        scanf("%d %d", &a, &b);
        result = arr[b] - arr[a - 1];
        printf("%d\n", result);
    }
}