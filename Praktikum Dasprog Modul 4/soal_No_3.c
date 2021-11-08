#include <stdio.h>

void fungsi(int *N, int *M, int array[200][200])
{
    int hasil = 0;

    for (int x = 1; x <= *N; x++)
    {
        for (int y = 1; y <= *M; y++)
        {

            if (x != y)
            {
                hasil += *(*(array + x) + y);
                printf("%d ", *(*(array + x) + y));
            }
        }
    }
    printf("\n");
    printf("%d\n", hasil);
}

int main()
{
    int N, M;

    scanf("%d %d", &N, &M);
    int array[200][200];

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", *(array + i) + j);
        }
    }
    fungsi(&N, &M, array);
}