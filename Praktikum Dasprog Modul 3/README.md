# Soal Dan Jawaban

-   Praktikum Dasprog Modul 3

## Soal No 1 : Anton Memanggil Dirinya

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
