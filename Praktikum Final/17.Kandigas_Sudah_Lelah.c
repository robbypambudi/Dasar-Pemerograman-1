/*
Kampus tempat Kadigas berkuliah mulai menerapkan kuliah hybrid hari ini. 50 % mahasiswa diharuskan datang ke kampus untuk berkuliah terutama yang tinggal di sekitar kota kampus tersebut. Kadigas termasuk di dalam 50 % mahasiswa yang mengikuti kuliah hybrid. Kelas pertama yang diikuti Kadigas adalah mata kuliah Dasar Pemrograman. Setelah masuk ke kelas, pertama-tama dosen meminta para mahasiswa untuk memilih komting mereka sendiri. Kemudian mereka mengajukan 3 nama untuk dilakukan voting: Kadigas, Zhard, dan Nop. Setelah voting ternyata jumlah voting Kadigas paling banyak di antara yang lain. Dan akhirnya Kadigas menjadi komting di kelas Dasar Pemrograman.

Lalu dosen di kelas tersebut meminta bantuan Kadigas untuk memproses beberapa data dan kemudian mencetaknya sesuai dengan permintaan. Karena dosen yang meminta bantuan adalah dosen Dasar Pemrograman, Kadigas diharuskan membuat program struct sesuai yang telah dipelajari. Tetapi, Kadigas sudah lelah karena telah membuat banyak program dari awal semester. Karena Zhard dan Nop adalah teman baik Kadigas, mereka pun membantu Kadigas. Namun, karena mereka sama-sama tidak bisa, mereka menyewa kalian sebagai programmer handal. Buatkan mereka sebuah program.

Input Format

Baris pertama merupakan n jumlah paragraf.

n baris berikutnya adalah isi dari sebuah paragraf yang dapat berisi 1 kalimat/lebih.

Baris selanjutnya adalah q jumlah query dengan aturan:

1 a adalah mencetak paragraf ke-a
2 a b adalah mencetak kalimat ke-a dari paragraf ke-b
3 a b c adalah mencetak kata ke-a dari kalimat ke-b dari paragraf ke-c
Constraints

Setiap kata dibatasi oleh spasi(" "), setiap kalimat dibatasi oleh tanda titik("."), dan setiap paragraf dibatasi oleh newline("\n").
Kata terakhir dalam kalimat tidak diakhiri dengan spasi.
Paragraf terakhir tidak diakhiri dengan baris baru.
Hanya berisi huruf besar dan huruf kecil
0 < jumlah paragraf < 11
0 < jumlah karakter di semua paragraf < 501
Output Format

Cetak output berupa kata/kalimat/paragraf sesuai aturan di atas.
Sample Input 0

2
Dasar Pemrograman.
Dasar Pemrograman.Alpro.
3
1 2
2 2 2
3 2 1 1
Sample Output 0

Dasar Pemrograman.Alpro.
Alpro
Pemrograman
*/

#include <stdio.h>
#include <string.h>

struct DATA
{
    char paragraf[1024];
};

void fungsi_1(int a, struct DATA *data)
{
    int b;
    scanf("%d", &b);
    printf("%s\n", data[b - 1].paragraf);
}

void fungsi_2(struct DATA *data)
{
    int a, b;
    scanf("%d %d", &a, &b);
    int awal;
    int kalimat = 1;
    // printf("%s\n", data[b - 1].paragraf);
    for (int i = 0; i < strlen(data[b - 1].paragraf); i++)
    {
        if (a == kalimat)
        {
            awal = i;
            break;
        }
        if (data[b - 1].paragraf[i] == '.')
        {
            kalimat += 1;
        }
    }
    // printf("%d %d %d\n", awal, a, kalimat);
    for (int i = awal; i < strlen(data[b - 1].paragraf); i++)
    {
        if (data[b - 1].paragraf[i] == '.')
        {
            printf("\n");
            break;
        }
        printf("%c", data[b - 1].paragraf[i]);
    }
}

void fungsi_3(struct DATA *data)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int awal;
    int kalimat = 1;
    for (int i = 0; i < strlen(data[c - 1].paragraf); i++)
    {
        if (kalimat == b)
        {
            awal = i;
            break;
        }
        if (data[c - 1].paragraf[i] == '.')
        {
            kalimat += 1;
        }
    }
    int kata = 1;
    int kata_awal;

    for (int i = awal; i < strlen(data[c - 1].paragraf); i++)
    {
        if (kata == a)
        {
            kata_awal = i;
            break;
        }
        if (data[c - 1].paragraf[i] == ' ')
        {
            kata += 1;
        }
    }
    for (int i = kata_awal; i < strlen(data[c - 1].paragraf); i++)
    {
        if (data[c - 1].paragraf[i] == ' ' || data[c - 1].paragraf[i] == '.')
        {
            printf("\n");
            break;
        }
        printf("%c", data[c - 1].paragraf[i]);
    }
    // printf("Awal = %d\n", awal);
}
int main()
{
    int x;
    scanf("%d", &x);
    struct DATA data[x];

    for (int i = 0; i < x; i++)
    {
        scanf(" %[^\n]", data[i].paragraf);
    }
    int X;

    scanf("%d", &X);
    for (int i = 0; i < X; i++)
    {
        int a;
        scanf("%d", &a);
        if (a == 1)
        {
            fungsi_1(a, data);
        }

        if (a == 2)
        {
            fungsi_2(data);
        }
        if (a == 3)
        {
            fungsi_3(data);
        }
    }
}