#include <stdio.h>

void reverse(int arr[], int N);

int main()
{
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    reverse(arr, N);
}

void reverse(int arr[], int N)
{
    int min_idx;

    for (int i = 0; i < N - 1; i++)
    {

        // Fing the minimum element in unsorteed Array
        min_idx = i;
        for (int j = i + 1; j < N; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Tukar
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}