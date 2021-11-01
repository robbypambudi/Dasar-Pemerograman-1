# Soal Dan Jawaban

-   Praktikum Dasprog Modul 3

## <p style = 'color: red; text-align:center'>Soal No 1 : Anton Memanggil Dirinya</p>

**KATA KUNCI : Bilangan Fibonaci, Rekursif**

Anton yang semakin hari merasa semakin susah untuk mencari jodoh, dia bingung dan ingin menenangkan pikirannya dengan memanggil dirinya sendiri dalam pikirannya.

Diketahui suatu deret 0,1,1,2,3,5,8,...

yang merupakan banyak kali Anton memanggil dirinya sendiri di waktu n-menit. Anton meminta bantuanmu untuk membuat fungsi rekursif yang bisa mendapatkan jumlah Anton memanggil dirinya sendiri pada waktu n-menit.

### Input Format

Bilangan n

### Constraints

```
0 ≤ n ≤ 45
```

### Output Format

Bilangan yang menyatakan banyak pemanggilan diri Anton dikalikan dengan bilangan 125 yang merupakan angka favorit Anton.

### Sample Input 0

```
3
```

### Sample Output 0

```
250
```

### Langkah Penyelesaian

1. Membuat Fungsi Mencari Bilangan Fibonaci Secara Rekursif
2. Berhenti Ketika fungsi sudah berulang sebanyak n
3. Nilai fungsi dikalikan dengan 125
4. Cetak Hasil

### Code

```
#include <stdio.h>
long long int hasil = 1;
void fibonaci(int N)
{
    static int N1 = 0, N2 = 1, N3; // Static Int

    if (N > 0)
    {
        N3 = N1 + N2;
        N1 = N2;
        N2 = N3;
        // printf("%d ", N3);
        hasil = N3;
        fibonaci(N - 1);
    }
}

int main()
{
    int N;
    // printf("Enter the number of elements : ");
    scanf("%d", &N);
    // printf(" 0 1 ");
    fibonaci(N - 1); // Number 1 and 2 already Printed
    if (N == 0)
    {
        printf("0");
    }
    else if (N == 1)
    {
        printf("125");
    }
    else if (N == 2)
    {
        printf("125");
    }
    else
    {
        printf("%lld", hasil * 125);
    }
}
```

---

## <p style="color: red; text-align:center" >Soal No 2 : Triangle Ladder</p>

**Kata Kunci : Maxsimum Triangle Sum**

Kamu diminta untuk membuat tangga segitiga yang memiliki karakteristik khusus dimana susunan paling bawah merupakan pondasi tangga dengan input yang telah diberikan dan susunan di atasnya merupakan penjumlahan-penjumlahan dari bilangan satu dengan bilangan di sebelahnya berdasarkan susunan tangga di bawahnya. Setiap bilangan pada suatu susunan dipisahkan dengan spasi dan setiap susunan dipisahkan dengan newline.

Contohnya pondasi tangga terdiri dari 5 bilangan yaitu <strong>1,2,3,4,5</strong> sehingga tangga akan memiliki 5 susunan:

Susunan tangga ke-5 yaitu <strong>1,2,3,4,5</strong>

Susunan tangga ke-4 yaitu 1+2,2+3,3+4,4+5, maka hasilnya <strong>3,5,7,9</strong>

Susunan tangga ke-3 yaitu 3+5,5+7,7+9, maka hasilnya 8,12,16

Susunan tangga ke-2 yaitu 8+12,12+16, maka hasilnya 20,28

Susunan tangga ke-1 yaitu 20+28, maka hasilnya 48

Jadi dapat diperoleh tangga segitiganya yaitu

```
48
20 28
8  12 16
3  5  7  9
1  2  3  4  5
```

### Input Format

Baris pertama berisi bilangan n yang menyatakan jumlah bilangan yang menjadi pondasi dari tangga segitiga. n

Baris kedua terdiri dari n bilangan x yang merupakan pondasi dari tangga segitiga.

### Constraints

```
1 ≤ n ≤ 30

1 ≤ x ≤ 10000
```

### Output Format

Sebuah tangga segitiga sesuai dengan permintaan soal.

### Sample Input 0

```
5
1 2 3 4 5
```

### Sample Output 0

```
48
20 28
8 12 16
3 5 7 9
1 2 3 4 5

```

## Langkah Penyelesaian

-   https://www.tutorialspoint.com/sum-triangle-from-an-array-in-c-programming

1. Membuat fungsi untuk menghitung segitiganya
2. Menambahkan array [i] dengan baris depannya [i+1]
3. Kemudian menyimpan dalam array baru
4. Memanggil fungsinya kembali

```
Susunan program
1. Int main memanggil fungsi dengan parameter (arr , N)
2. Fungsi akan memproses dengan base case adalah ketika n < 1
3. Kemudian Masuk kedalam for dengan nilai temp akan disi dengan [i] [i+1]

-> N = 5    -> arr[1] = 1, arr[2] = 2, arr[3] = 3, arr[4] = 4, arr[5] = 5
-> N = 4    -> arr[1] = 3, arr[2] = 5, arr[3] = 7, arr[4] = 9
-> N = 3    -> arr[1] = 8, arr[2] = 12, arr[3] = 16
-> N = 4    -> arr[1] = 20, arr[2] = 28
-> N = 1    -> arr[1] = 48

Ketika sampai dengan base case / N < 1
maka akan mulai untuk mencetak dimulai dari N = 1
N = 1       -> 48
N = 2       -> 20 28
N = 3       -> 8 12 16
N = 4       -> 3 5 7 9
N = 5       -> 1 2 3 4 5

Selesai Program berjalan habis

Atau akan tampil sebagai berikut :
48
20 28
8 12 16
3 5 7 9
1 2 3 4 5
```

## Code

```
#include <stdio.h>

void cetak(long long arr[], long long int n)
{
    if (n < 1)
    {
        return;
    }
    long long temp[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        unsigned long long int x = arr[i] + arr[i + 1];
        temp[i] = x;
    }
    cetak(temp, n - 1);
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            printf("%lld ", arr[i]);
        }
        else
        {
            printf("%lld ", arr[i]);
        }
    }
    printf("\n");
}

int main()
{
    unsigned long long int N;
    scanf("%llu", &N);
    long long arr[N];
    int a = 1;
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &arr[i]);
        if (arr[i] <= 0)
        {
            a = 0;
        }
    }

    if (a == 1)
    {
        cetak(arr, N);
    }
}
```

## <p style="text-align:center; color:red;">Malur Pesawat</p>

**Kata Kunci : Minimum Triangle Sum**
