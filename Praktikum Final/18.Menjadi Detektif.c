/*
Karena Hodaka pernah bermain-main dengan string, ia ditawari untuk bergabung kedalam kepolisian. Kini ia bekerja sebagai seorang detektif yang sedang menangani kasus pertamanya. Salah satu hal yang dapat menjadi petunjuk dalam kasus yang ia tangani terdapat pada pesan yang telah ditinggalkan oleh pelaku. Sayangnya, pesan tersebut telah dienkripsi dengan metode caesar cipher. Sebagai seorang programer handal, bantulah Hodaka dengan menyusun program yang dapat mendeteksi apakah string s2 bisa jadi merupakan bagian dari string s1 yang telah dienkripsi atau tidak.

Input Format

Sebuah baris yang berisi bilangan N yang menyatakan banyaknya pasang string, diikuti dengan N baris yang berisi string s1 dan s2 yang dipisahkan oleh spasi. string s1 dan s2 dijamin hanya memiliki huruf lowercase.

Constraints

1 ≤ N ≤ 106

5 ≤ |s1|, |s2| ≤ 31

'a' ≤ s1[i], s2[i] ≤ 'z'

Output Format

N baris yang berisi string "YSTTS" jika string s2 bisa jadi merupakan bagian dari string s1 yang telah dienkripsi dan string "YNTKTS" untuk selainnya.

Sample Input 0

2
klifxfwujrwtlwfrfsmb dasarpemrograman
klifhgywujrwtlwfrfsmb dasarpemrograman
Sample Output 0

YSTTS
YNTKTS
Explanation 0

Apabila string "klifxfwujrwtlwfrfsmb" dienkripsi dengan metode caesar cipher dengan geseran sebanyak 21 kali, maka akan didapat string "fgdasarpemrogramanhw" yang terdapat string "dasarpemrograman" didalamnya. Adapun untuk string s1 selanjutnya apabila dienkripsi dengan cara yang sama, akan didapat string "fgdacbtrpemrogramanhw".
*/

#include <stdio.h>
#include <string.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

void cocokan(int a, int b, int data[], int data_1[], int *temp, char kata[], char kunci[])
{
    while (data_1[b] == data[a])
    {

        if (b == strlen(kunci) - 1)
            return;
        if (a == strlen(kata) - 1)
            return;
        // printf("%c %c %d %d\n", kata[a], kunci[b], a, b);
        *temp = *temp + 1;

        a += 1;
        b += 1;
    }
    return;
}

int main()
{
    int N;
    scanf("%d", &N);
    char kata[1024];
    char kunci[1024];
    int data[1024];
    int data_1[1024];

    for (int i = 0; i < N; i++)
    {
        scanf(" %s %s", kata, kunci);

        for (int j = 0; j < strlen(kata) - 1; j++)
        {
            data[j] = kata[j + 1] - kata[j];
            //  printf("%d ", data[j]);
        }

        // printf("\n");
        for (int j = 0; j < strlen(kunci) - 1; j++)
        {
            data_1[j] = kunci[j + 1] - kunci[j];
            // printf("%d ", data_1[j]);
        }

        // printf("\n");

        int panjang = strlen(kunci);
        int temp;

        for (int k = 0; k < strlen(kata); k++)
        {
            for (int a = 0; a < strlen(kunci); a++)
            {
                temp = 1;
                if (data_1[a] != data[k] || k == strlen(kata) - 1 || a == strlen(kunci) - 1)
                    break;

                if (data_1[a] == data[k])
                {
                    cocokan(k, a, data, data_1, &temp, kata, kunci);
                }

                if (temp == panjang)
                    break;
            }

            if (temp == panjang)
            {
                break;
            }
        }
        // printf("%d\n", temp);

        if (temp == panjang)
        {
            printf("YSTTS\n");
        }
        else
        {
            printf("YNTKTS\n");
        }
    }
}
