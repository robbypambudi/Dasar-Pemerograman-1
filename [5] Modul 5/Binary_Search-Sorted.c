#include "stdio.h"

int myFunction(int arr[], int l, int N, int M)
{
    int result = -1;
    while (l <= N)
    {
        int mid = (N + l) / 2;

        if (arr[mid] > M)
            N = mid - 1;

        else if (arr[mid] < M)
        {
            l = mid + 1;
        }
        else
        {
            result = mid;
            N = mid - 1;
        }
    }
    return result;
}
int main()
{
    int N, M, X;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &X);
        int poition = myFunction(arr, 0, N - 1, X);
        printf("%d\n", poition);
    }
}