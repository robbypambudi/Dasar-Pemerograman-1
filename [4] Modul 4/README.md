# Soal Latihan

## Soal No 1

Implementasikan fungsi bernama tambah berisi 3 parameter, di mana parameter pertama merupakan bilangan 1, parameter kedua merupakan bilangan 2, dan parameter terakhir adalah variabel tempat hasil output.

### Contoh pemanggilan:

```
int a = 1;
int b = 2;
int c;
tambah(a, b, &c);
printf(“%d”, c);
```

### Output-nya :

```
3
```

---

## Soal No 2

Buatlah struct untuk menyimpan data nilai UN mahasiswa yang berisi nama, nilai Matematika, nilai IPA, nilai Bahasa Indonesia, dan nilai Bahasa Inggris. Setelah itu buat program yang dapat memasukkan list data nilai UN lalu menampilkan data sesuai nama.

Keterangan: urutan pemasukan nilai adalah Matematika, IPA, Bahasa Indonesia, Bahasa Inggris. Berikut merupakan contoh input dan output. 4 kelompok data di awal merupakan jumlah data nilai UN yang akan dimasukkan. Angka 3 di akhir merupakan jumlah nama yang akan dicari.

### Sample Input

```
4
Hope
100
90
20
90
Ricky
80
70
80
90
Maden
100
100
100
100
Tenten
90
80
99
100
3
Maden
Dennis
Tenten
```

### Sample Output

```
Nilai Maden
Matematika : 100
IPA : 100
Bahasa Indonesia : 100
Bahasa Inggris : 100
Nilai Dennis tidak ditemukan
Nilai Tenten
Matematika : 90
IPA : 80
Bahasa Indonesia : 99
Bahasa Inggris : 100
```

### Code

```

#include <stdio.h>

int tambah(int a, int b, int *c) // 2  3  0x...
{
    *c = a + b; // 5
}

int main()
{
    int a, b;
    int c; // Memory 0x...

    scanf("%d %d", &a, &b); // 2 3
    c = tambah(a, b, &c);
    printf("%d", c);
}
```

### Code

```
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

```

## Soal 3

Buatlah fungsi bernama reverse() untuk me-reverse array of integer menggunakan pointer. Fungsinya dapat digunakan seperti berikut.

```
int arr[5]
.
.
//input

reverse(arr, 5);
.
.
//print isi arr
```

### Sample Input:

```
5
8 4 2 3 1
```

### Sample Output:

```
1 3 2 4 8
```

### Code

```
#include <stdio.h>

void reverse(int arr[], int N);

int main()
{
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    reverse(arr, N);
}

void reverse(int arr[], int N)
{
    int min_idx;

    for (int i = 0; i < N - 1; i++)
    {

        // Fing the minimum element in unsorteed Array
        min_idx = i;
        for (int j = i + 1; j < N; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Tukar
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
```
