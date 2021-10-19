#include <stdio.h>
#include <string.h>

int main()
{
    unsigned int T;
    char kata[110];
    char sandi[110];
    unsigned int C;
    int K;

    scanf("%u\n", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%u %d\n", &C, &K);

        if (C == 1 && K <= 26 && K >= 0)
        {
            scanf("%[^\n]", kata);
            if (strlen(kata) <= 100)
            {

                for (int j = 0; j <= strlen(kata); j++)
                {
                    if (kata[j] == 32 || kata[j] <= 64 || (kata[j] == 91 || kata[j] == 92 || kata[j] == 93 || kata[j] == 94 || kata[j] == 95 || kata[j] == 96) || kata[j] >= 123)
                    {
                        continue;
                    }
                    else if (kata[j] < 91 && kata[j] >= 65)
                    {
                        if ((kata[j] - K) <= 64)
                        {
                            int temp = 65 - kata[j] + K;
                            kata[j] = 91;
                            kata[j] -= temp;
                        }
                        else
                        {
                            kata[j] -= K;
                        }
                    }
                    else if ((kata[j] - K) < 97)
                    {
                        int temp = 97 - kata[j] + K;
                        kata[j] = 123;
                        kata[j] -= temp;
                    }
                    else
                    {
                        kata[j] -= K;
                    }
                }
            }
        }
        else if (C == 2 && K <= 26 && K >= 0)
        {
            scanf("%[^\n]", sandi);
            if (strlen(sandi) <= 100)
            {

                for (int a = 0; a <= strlen(sandi); a++)
                {
                    if (sandi[a] == 32 || sandi[a] <= 64 || (sandi[a] == 91 || sandi[a] == 92 || sandi[a] == 93 || sandi[a] == 94 || sandi[a] == 95 || sandi[a] == 96) || sandi[a] >= 123)
                    {
                        continue;
                    }
                    else if (sandi[a] < 91 && sandi[a] >= 65)
                    {
                        if ((sandi[a] + K) > 90)
                        {
                            int temp = sandi[a] + K;
                            temp -= 91;
                            sandi[a] = 65 + temp;
                        }
                        else
                        {
                            sandi[a] += K;
                        }
                    }
                    else if (sandi[a] + K > 122)
                    {
                        int temp = sandi[a] + K;
                        temp -= 122;
                        sandi[a] = 96 + temp;
                    }
                    else
                    {
                        sandi[a] += K;
                    }
                }
            }
        }

        if (C == 1 && K <= 26 && K >= 0)
        {
            printf("%s\n", kata);
        }
        else if (C == 2 && K <= 26 && K >= 0)
        {
            printf("%s\n", sandi);
        }
    }
}
