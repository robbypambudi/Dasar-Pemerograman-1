#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int kode[] = {
        'A',
        'a',
        'B',
        'b',
        'C',
        'c',
        'D',
        'd',
        'E',
        'e',
        'F',
        'f',
        'G',
        'g',
        'H',
        'h',
        'I',
        'i',
        'J',
        'j',
        'K',
        'k',
        'L',
        'l',
        'M',
        'm',
        'N',
        'n',
        'O',
        'o',
        'P',
        'p',
        'Q',
        'q',
        'R',
        'r',
        'S',
        's',
        'T',
        't',
        'U',
        'u',
        'V',
        'v',
        'W',
        'w',
        'X',
        'x',
        'Y',
        'y',
        'Z',
        'z',
    };

    int K;
    char kalimat[100000];
    scanf("%d", &K);

    while (K >= 52)
    {
        K = K - 52;
    }
    // Binary Code

    int num, angka = 0, base = 1, rem;
    scanf("%d", &num);
    while (num != -1)
    {
        base = 1;
        // printf("%d ", num);
        //  Konversi to angka
        while (num > 0)
        {
            rem = num % 10;
            angka = angka + rem * base;
            num = num / 10;
            base = base * 2;
        }
        scanf(" %[^\n]", kalimat);
        if (angka == 0 && angka > 16)
        {
            continue;
        }
        else if (angka == 2 || angka == 3 || angka == 5 || angka == 7 || angka == 11 || angka == 13 || angka == 17)
        {
            for (int i = 0; i < strlen(kalimat); i++)
            {

                for (int j = 0; j < 52; j++)
                {

                    if (kalimat[i] == kode[j])
                    {
                        int awal = j;
                        awal += K;
                        if (awal > 51)
                        {
                            awal = awal - 52;
                        }
                        kalimat[i] = kode[awal];
                        break;
                    }
                }
            }
            printf("Mumun: %s\n", kalimat);
        }
        else
        {
            for (int i = 0; i < strlen(kalimat); i++)
            {

                for (int j = 0; j < 52; j++)
                {
                    if (kalimat[i] == kode[j])
                    {
                        int awal = j;
                        awal -= K;
                        if (awal < 0)
                        {
                            awal = awal + 52;
                        }
                        kalimat[i] = kode[awal];
                        break;
                    }
                }
            }
            printf("Robot: %s\n", kalimat);
        }
        // printf("%d\n", angka);
        angka = 0;
        scanf(" %d", &num);
    }
}