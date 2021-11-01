<h1> Soal dan Jawaban Praktikum Dasprog Modul 3</h1>

<h2> Soal No 1</h2>
<p>Materi <br> 1. Bilangan Fibonaci <br> 2. Recursive </p>
<h4> Deskripsi Soal </h4>
<p>Anton yang semakin hari merasa semakin susah untuk mencari jodoh, dia bingung dan ingin menenangkan pikirannya dengan memanggil dirinya sendiri dalam pikirannya. </p>
<p>Diketahui suatu deret <strong>0,1,1,2,3,5,8,...</strong></p>
<p>yang merupakan banyak kali Anton memanggil dirinya sendiri di waktu n-menit. Anton meminta bantuanmu untuk membuat fungsi rekursif yang bisa mendapatkan jumlah Anton memanggil dirinya sendiri pada waktu n-menit.<p>
<p><strong>Input Format </strong></p>
<p>Bilangan n</p>
<p><strong>Constraints</strong></p>
```
0 ≤ n ≤ 45
```
<p><strong>Output Format</strong></p>
<p>Bilangan yang menyatakan banyak pemanggilan diri Anton dikalikan dengan bilangan 125 yang merupakan angka favorit Anton</p>
<p><strong>Sample Input 0</strong>
```
3
```
<p><strong>Sample Output 0</strong></p>
```
250
```
<p><strong>Langkah Penyelesaian</strong></p>
1. Membuat Fungsi Rekursif
2. Berhenti Ketika Pemangilan ke N
3. Cetak Hasil di N dan Dikalikan 125
<p><strong>CODE</strong></p>
```
#include <stdio.h>
long long int hasil = 1;
void fibonaci(int N)
{
    static int N1 = 0, N2 = 1, N3;

    if (N > 0)
    {
        N3 = N1 + N2;
        N1 = N2;
        N2 = N3;
        //printf("%d ", N3);
        hasil = N3;
        fibonaci(N - 1);
    }

}

int main()
{
int N;
//printf("Enter the number of elements : ");
scanf("%d", &N);
//printf(" 0 1 ");
fibonaci(N - 1); // Number 1 and 2 already Printed
if (N == 0){
printf("0");
}
else if (N == 1) {
printf("125");
}
else if (N == 2){
printf("125");
}
else {
printf("%lld", hasil \* 125);
}
}

```

```
