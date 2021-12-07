/*
Tiba waktunya kita berpisah dengan Sang Ambis...

Tak terasa sudah Final Praktikum dan sudah saatnya kita semua berpisah dengan tim asdos tercinta. Begitu juga yang dirasakan oleh Sang Ambis, setelah banyak hal yang dia lalui seperti belajar materi Sistem Digital, mengkloning Squid Games, dan membuat game versinya sendiri sudah dijalani hingga sekarang waktunya untuk berpisah...

Eits, tapi tunggu dulu, Sang Ambis masih butuh bantuan kalian! Belakangan ini dia butuh uang tambahan untuk beli NFT sehingga ia memutuskan untuk bekerja di suatu supermarket. Saat bekerja, dia diberikan kertas list barang berisi informasi kode barang, nama barang, dan harga barang.

image

Karena dia harus melihat kertas itu setiap ada barang yang dibeli oleh pelanggan, ia merasa kesulitan dan dirasa terlalu ribet. Oleh karena itu, ia memutuskan untuk menggunakan ilmu yang telah didapatkan untuk membuat program guna mempermudah pekerjaannya tersebut. Program tersebut diharapkan dapat menampun sebanyak n barang dengan nama barang dan harga yang bervariasi. Bantulah dia untuk memasukkan data tersebut dan membantunya untuk mengetahui total belanja para pelanggan!

Apabila terdapat n jenis barang dan pembeli ingin membeli sebanyak x barang, maka item yang akan dibeli adalah 1, 2, 3, ..., x masing-masing 1 barang.

WAJIB PAKAI STRUCT!!!

Input Format

Baris pertama berisi bilangan n, yaitu banyaknya barang.

n baris selanjutnya berisi kode barang, nama barang, dan harga barang

Baris-baris selanjutnya, masing-masing berisi bilangan bulat x yaitu banyak barang yang ingin dibeli oleh pembeli.

Constraints

1 <= n <= 10000

1 <= x <= n

Kode barang dan nama barang memiliki karakter kurang dari 20

1000 <= Harga barang <= 200000

Banyak baris x <= 100000

Output Format

Keluarkan seperti pada contoh output sesuai dengan banyak baris pada input

Sample Input 0

5
00001 MinyakGoreng1L 20000
00002 TepungTerigu 17000
00003 Beras 30000
00004 Susu 27500
00005 SabunMandi 15000
2
3
5
Sample Output 0

=====================================

No. Transaksi    : 1
Total item       : 2
Item termurah    : 00002 TepungTerigu
Item termahal    : 00001 MinyakGoreng1L
Total pembayaran : 37000

=====================================

No. Transaksi    : 2
Total item       : 3
Item termurah    : 00002 TepungTerigu
Item termahal    : 00003 Beras
Total pembayaran : 67000

=====================================

No. Transaksi    : 3
Total item       : 5
Item termurah    : 00005 SabunMandi
Item termahal    : 00003 Beras
Total pembayaran : 109500

=====================================
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef unsigned long long llu;
typedef long long ll;
struct data
{
    char ID[100];
    char Nama[100];
    int harga;
};
struct data barang[100001];

int main()
{
    int N, x, i = 1;
    char data[30], data_1[30], data_2[30], data_3[30];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", barang[i].ID);
        scanf("%s", barang[i].Nama);
        scanf("%d", &barang[i].harga);
    }
    while (scanf("%d", &x) != EOF)
    {
        int mahal = -1, murah = 1000000000;
        int Result = 0;
        for (int j = 0; j < x; j++)
        {
            if (barang[j].harga < murah)
            {
                murah = barang[j].harga;
                strcpy(data, barang[j].ID);
                strcpy(data_2, barang[j].Nama);
            }
            if (barang[j].harga > mahal)
            {
                mahal = barang[j].harga;
                strcpy(data_1, barang[j].ID);
                strcpy(data_3, barang[j].Nama);
            }
            Result = Result + barang[j].harga;
        }
        printf("=====================================\n\n");
        printf("No. Transaksi    : %d\n", i);
        printf("Total item       : %d\n", x);
        printf("Item termurah    : %s %s\n", data, data_2);
        printf("Item termahal    : %s %s\n", data_1, data_3);
        printf("Total pembayaran : %d", Result);
        printf("\n\n");
        i++;
    }
    printf("=====================================\n");
}