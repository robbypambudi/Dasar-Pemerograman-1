#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int data[n][3];
    for (int x = 0; x < n; x++)
    {
        scanf("%d%d%d", &data[x][0], &data[x][1], &data[x][2]);
    }
    for (int x = 0; x < n; x++)
    {
        int temp = 0;

        for (int i = 0; i <= data[x][2]; i++)
        {
            int j = 0;

            while ((data[x][0] * i) +
                       (data[x][1] * j) <=
                   data[x][2])
            {

                if ((data[x][0] * i) + (data[x][1] * j) == data[x][2])
                {
                    temp++;
                }
                j++;
            }
        }
        printf("%d\n", temp);
    }
    return 0;
}