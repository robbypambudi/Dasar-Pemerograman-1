#include <stdio.h>

void myFunction(int arr[], int Li, int Ri, int *Result, int N)
{
    for (int j = 0; j < N; j++)
    {
        if (Li <= arr[j])
        {
            if (Ri >= arr[j])
            {
                *Result += 1;
            }
        }
    }
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

    int A;
    scanf("%d", &A);
    int Li, Ri, Result = 0;
    for (int i = 0; i < A; i++)
    {
        Result = 0;
        scanf("%d %d", &Li, &Ri);
        myFunction(arr, Li, Ri, &Result, N);
        printf("%d\n", Result);
    }
}