#include <stdio.h>

void binsearch(int arr[], int N, int data)
{
    int mid = N / 2;
    int result = -1;

    for (int i = 0; i <= mid; i++)
    {
        if (arr[i] == data)
        {
            result = i;
            break;
        }
    }

    if (result == -1)
    {
        for (int i = mid + 1; i < N; i++)
        {
            if (arr[i] == data)
            {
                result = i;
                break;
            }
        }
    }
    printf("%d\n", result);
    return;
}

int main()
{
    int N;

    scanf("%d", &N);
    int arr[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    int X, dat;
    scanf("%d", &X);
    for (int i = 0; i < X; i++)
    {
        scanf("%d", &dat);
        binsearch(arr, N, dat);
    }
    return 0;
}