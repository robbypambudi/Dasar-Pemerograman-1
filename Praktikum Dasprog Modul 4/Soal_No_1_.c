#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct HADIAH
{
    char hewan[50];
    char warna[50];
    int x;
};

int main()
{
    int N;
    char hewan_dicari[50], warna_dicari[50];
    int angka;

    scanf("%d", &N);
    struct HADIAH hadiah[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%s %s %d", hadiah[i].hewan, hadiah[i].warna, &hadiah[i].x);
    }

    scanf("%s, %s, %d", hewan_dicari, warna_dicari, &angka);

    bool apakahadahewan = false, apakahadawarna = false, apakahdanomer = false;
    for (int i = 0; i < N; i++)
    {
        if ((strcmp(hadiah[i].hewan, hewan_dicari) == 0))
        { // Jika Hewan tidak ada
            apakahadahewan = true;
        }
    }
    for (int i = 0; i < N; i++)
        if ((strcmp(hadiah[i].warna, warna_dicari) == 0)) // Jika warna tidak ada
        {
            apakahadawarna = true;
        }

    for (int i = 0; i < N; i++)
        if (!(hadiah[i].x == angka)) // Jika warna tidak ada
        {
            apakahdanomer = true;
        }

    if (apakahdanomer && apakahadahewan && apakahdanomer)
        printf("Asik hadiahnya ada^^");
    else
        printf("Bantu aku langit :(");

    return 0;
}
