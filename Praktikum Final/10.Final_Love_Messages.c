#include <stdio.h>
#include <string.h>

int main()
{
    char kalimat[1000];

    scanf("%[^\n]", kalimat);
    while (strcmp(kalimat, "exit") != 0)
    {
        for (int i = 0; i < strlen(kalimat) - 1; i++)
        {
            for (int j = i + 1; j < strlen(kalimat); j++)
            {
                if (kalimat[i] > kalimat[j])
                {
                    int temp = kalimat[i];
                    kalimat[i] = kalimat[j];
                    kalimat[j] = temp;
                }
            }
        }
        for (int i = 0; i < strlen(kalimat); i++)
        {
            if (kalimat[i] == ' ')
            {
                for (int j = i; j < strlen(kalimat); j++)
                {
                    kalimat[j] = kalimat[j + 1];
                }
                i = 0;
            }
        }
        if (kalimat[0] == ' ')
        {
            for (int i = 0; i < strlen(kalimat); i++)
            {
                kalimat[i] = kalimat[i + 1];
            }
        }

        printf("%s\n", kalimat);
        scanf(" %[^\n]", kalimat);
    }
}