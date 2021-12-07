/*
Hufi, seorang mahasiswi yang sedang dimabuk cinta, merasa curiga dengan gebetannya, yaitu Mehas, karena gelagatnya yang aneh akhir-akhir ini. Ia mengambil kesempatan untuk melihat-lihat pesan yang masuk di HP Mehas. Namun, ada satu pesan yang terdiri dari beberapa baris kalimat dan bilangan. Pesan itu menarik perhatian Hufi dan membuatnya terdiam sejenak dan menyesal karena telah merasa curiga kepada Mehas.

Setelah membaca pesan itu, Hufi meminta maaf kepada Mehas. Lalu, ia menyatakan perasaannya kepada Mehas and they lived happily ever after

Input Format

Baris pertama, n, banyak kalimat yang akan diinput
n baris selanjutnya berisi kalimat yang di-input.
Baris selanjutnya, m, merupakan banyak pasangan index kata & index kalimat
m baris berisi a & b. a merupakan index kalimat dan b merupakan index kata.
Constraints

Tiap kalimat memiliki banyak karakter kurang dari 150
0 < n < 150
a tidak lebih besar dari banyak kalimat.
b tidak lebih besar dari banyak kata di tiap kalimatnya.
Output Format

Satu baris kalimat pesan tersembunyi dari pesan Mehas.

Sample Input 0

5
Kok badminton aku nyangkut di atap rumah Hufi
Tadinya mau ditembak pake ketapel
Tapi ada anjing ngejar
Juga dikira mau maling
Jadi belum diambil sih
6
1 1
1 8
5 2
2 3
4 1
5 4
Sample Output 0

Kok Hufi belum ditembak Juga sih
Sample Input 1

4
dafarel bermain bersama ocan
aryansw memijat vito di rumah khosyi
mahendradaffa bertengkar dengan ahdafilza
daffasas memukul gungadhi
9
1 1
1 4
2 1
2 3
2 6
3 1
3 4
4 1
4 3
Sample Output 1

dafarel ocan aryansw vito khosyi mahendradaffa ahdafilza daffasas gungadhi
*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char str[500];
    char kata[500][500];
} string;
string data[500];

int main()
{
    int n, m,
        i, temp_3,
        temp_1, temp_2;

    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        scanf(" %[^\n]", data[i].str);

        int len = strlen(data[i].str);
        temp_1 = 1, temp_2 = 0;

        for (temp_3 = 0; temp_3 < len; temp_3++)
        {
            if (data[i].str[temp_3] == ' ' || data[i].str[temp_3] == '\0')
            {
                data[i].kata[temp_1][temp_2] = '\0';
                temp_2 = 0;
                temp_1++;
            }
            else
            {
                data[i].kata[temp_1][temp_2] = data[i].str[temp_3];
                temp_2++;
            }
        }
    }
    scanf("%d", &m);
    int dat_1[m], dat_2[m];

    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &dat_1[i], &dat_2[i]);
    }
    for (i = 0; i < m; i++)
    {
        if (i > 0)
        {
            printf(" ");
        }
        printf("%s", data[dat_1[i]].kata[dat_2[i]]);
    }
    printf("\n");
    return 0;
}