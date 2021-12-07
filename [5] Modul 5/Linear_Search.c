#include <stdio.h>

int main()
{

    int N, M;
    scanf("%d %d", &N, &M);
    int arr[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    int mid = N / 2;
    int result = -1;

    for (int i = mid; i >= 0; i--)
    {
        if (arr[i] == M)
            result = i;
    }

    if (arr[mid] < M && result == -1)
    {
        for (int i = mid; i < N; i++)
        {
            if (arr[i] == M)
            {
                result = i;
                break;
            }
        }
    }

    printf("%d\n", result);

    return 0;
}