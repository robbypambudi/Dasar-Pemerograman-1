#include <stdio.h>
#include <string.h>

void cek(int arr[], int dat)
{
    if (arr[dat] == -1)
        printf("-1\n");
    else
    {
        printf("%d\n", arr[dat]);
    }
}

int main()
{
    int arr[100001];
    int N, a;
    scanf("%d", &N);
    memset(arr, -1, sizeof(arr));

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a);
        if (arr[a] == -1)
            arr[a] = i;
    }

    int b, c;
    scanf("%d", &b);
    for (int i = 0; i < b; i++)
    {
        scanf("%d", &c);
        cek(arr, c);
    }
}