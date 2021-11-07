/*

Buatlah struct untuk menyimpan data nilai UN mahasiswa yang berisi nama, nilai Matematika, nilai IPA,
 nilai Bahasa Indonesia, dan nilai Bahasa Inggris. Setelah itu buat program yang dapat memasukkan list
 data nilai UN lalu menampilkan data sesuai nama.
Keterangan: urutan pemasukan nilai adalah Matematika, IPA, Bahasa Indonesia,
Bahasa Inggris. Berikut merupakan contoh input dan output. 4 kelompok data di awal
 merupakan jumlah data nilai UN yang akan dimasukkan. Angka 3 di akhir merupakan jumlah nama yang akan dicari.

*/
#include <stdio.h>
#include <string.h>

struct Mahasiswa
{
    char nama[100];
    int Matematika;
    int IPA;
    int BIndonesia;
    int Binggris;
};

struct Cari
{
    char nama[20];
};

void cetak(int N, struct Mahasiswa *mhs)
{
    printf("Nilai %s\n", mhs[N].nama);
    printf("Matematika : %d\n", mhs[N].Matematika);
    printf("IPA : %d\n", mhs[N].IPA);
    printf("Bahasa Indonesia : %d\n", mhs[N].BIndonesia);
    printf("Bahasa Inggris : %d\n", mhs[N].Binggris);
    return;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    struct Mahasiswa mhs1[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%s", mhs1[i].nama);
        scanf("%d", &mhs1[i].Matematika);
        scanf("%d", &mhs1[i].IPA);
        scanf("%d", &mhs1[i].BIndonesia);
        scanf("%d", &mhs1[i].Binggris);
    }
    int hahah;
    scanf("%d", &hahah);
    struct Cari cari[hahah];
    for (int i = 0; i < hahah; i++)
    {
        scanf("%s", cari[i].nama);
    }

    for (int i = 0; i < hahah; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (strcmp(cari[i].nama, mhs1[j].nama) == 0)
            {
                cetak(j, mhs1);
                break;
            }
            if (j == N - 1)
                printf("Nilai %s tidak ada\n", cari[i].nama);
        }
    }

    return 0;
}
