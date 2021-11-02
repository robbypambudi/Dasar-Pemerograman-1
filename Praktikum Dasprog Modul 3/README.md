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

---

## <p style="text-align:center; color:red;">Soal No 3 : Malur Pesawat</p>

**Kata Kunci : Minimum Triangle Sum**

Pesawat Jet milik Perusahaan Malur ingin mempromosikan produk mereka kembali karena kalah bersaing dengan perusahaan yang lain, kekalahan mereka diakibatkan oleh lamanya kedatangan pesawat dari bandara ke sasaran tempat promosi, sehingga Manajer Perusahaan Malur meminta bantuan kepada kalian untuk membuat program yang bisa mencetak rute terpendek pesawat Jet untuk bisa sampai di tempat tujuan tepat waktu.

Rute yang akan dilewati oleh pesawat membentuk suatu segitiga dengan sebaran titik keberangkatan ke titik promosi merupakan tinggi segitiga (h), sedangkan di antara titik keberangkatan ke titik promosi terdapat bandara-bandara (ditandai dengan node) yang mengharuskan pesawat berhenti untuk mengisi bahan bakar, tiap node memiliki suatu nilai node (n) yang menunjukkan jarak bandara keberangkatan dan bandara kedatangan.

### Input Format

<img src="https://s3.amazonaws.com/hr-assets/0/1635039602-de63a57960-Screenshot_1.png" alt="Input Format" >

Baris pertama merupakan nilai dari tinggi segitiga (h) berupa integer, Untuk tiap baris selanjutnya merupakan nilai node n(y,x) dimana y merupakan posisi tingkatan dalam segitiga dan x merupakan posisi elemen dari kiri dalam tingkat tertentu.

```
h
n(1,1)
n(2,1) n(2,2)
n(3,1) n(3,2) n(3,3)
. . .
n(h,1) n(h,2) . . . n(h,h)
```

### Constraints

```
1 ≤ h ≤ 30
1 ≤ n(y,x) ≤ 1.000
```

### Output Format

Print solusi yang didapatkan dengan menandai rute-terpendek yang menjadi solusi dengan nilai -1

```
-1
7 -1
2 -1 6
8 -1 9 4
```

Sample Input dan Output merupakan kasus yang sama dengan Contoh permasalahan dan solusi yang tertera di atas, dengan Format Output sebagai berikut

<img src="https://s3.amazonaws.com/hr-assets/0/1635040000-19f8165942-Screenshot_2.png" alt="Gambar 2">

### Sample Input 0

```
4
3
7 4
2 4 6
8 5 9 4
```

### Sample Output 0

```
-1
7 -1
2 -1 6
8 -1 9 4
```

### Langkah Penyelesaian

```
Refrensi    : http://www.zrzahid.com/min-sum-path-in-triangle/
            : https://www.geeksforgeeks.org/minimum-sum-path-triangle/

1. Membuat Fungsi Untuk Mencari Jalur Minimum
2. Menandai Jalur Jalur yang mempumyai nilai kecil
3. Mencetak Nilai dan mengubah nilai yang ditandai menjadi -1
```

### Code

```
#include <stdio.h>


long long h, arr[1000][1000];
long long temp[1000][1000];
long long path[1000][1000];
long long min(int x, int y)
{
    if (temp[x][y] != 0)
        return temp[x][y];
    if (x == h)
        return temp[x][y] = arr[x][y];

    if (min(x + 1, y) < min(x + 1, y + 1))
    {
        temp[x][y] = arr[x][y] + min(x + 1, y);
        path[x][y] = '~';
    }
    else
    {
        temp[x][y] = arr[x][y] + min(x + 1, y + 1);
        path[x][y] = 'p';
    }
    return temp[x][y];
}
int main()
{

    scanf("%lld", &h);
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            scanf("%lld", &arr[i][j]);
            temp[i][j] = 0;
        }
    }
    min(1,1);
    arr[1][1] = -1;         // Edited
    int j = 1;
    for (int i = 1; i < h; i++)
    {
        if (path[i][j] == '~')
        {
            arr[i + 1][j] = -1;
        }
        else if (path[i][j] == 'p')
        {
            j++;
            arr[i + 1][j] = -1;
        }
    }

    for (int i = 1; i <= h; i++)
    {
        for (int k = 1; k <= i; k++)
        {
            printf("%lld ", arr[i][k]);
        }
        printf("\n");
    }
}
```

## Soal No 4 : Monsterbuster

**Kata Kunci : N problem Solving, Backtracking**

Bambang Sumanto adalah pembuat game bernama monsterbuster, bambang memiliki suatu logika game yaitu bom biru yang akan meledak dengan arah seperti gambar dibawah.
<img src="https://s3.amazonaws.com/hr-assets/0/1606570681-ac4d3e5bc4-bom.png" alt="Monster Buster">
Jika bambang ingin membuat sebuah peta NxN, dan ingin meletakkan N bom biru, tetapi bom biru tidak boleh diletakkan di path ledakkan bom lain, carilah jumlah peletakkan bom yang valid!

### Input Format

```
Baris pertama yaitu N
```

### Constraints

```
1 ≤ N ≤ 12
```

### Ouput Format

```
Bilangan bulat Jumlah Solusi
```

### Sample Input 0

```
4
```

### Sample Output 0

```
2
```

### Explanation 0

<img src="https://s3.amazonaws.com/hr-assets/0/1606783997-8647950160-ScreenShot2020-12-01at07.52.22.png" alt="Explanation_of_MonsterBuster">
jadi banyaknya ada 2

### Langkah Penyelesaian

```
Refrensi    : https://www.geeksforgeeks.org/printing-solutions-n-queen-problem/
            : https://www.techiedelight.com/print-possible-solutions-n-queens-problem/
            : https://tutorialspoint.dev/algorithm/backtracking-algorithms/printing-solutions-n-queen-problem

1. Membuat fungsi untuk menentukan apakah jalur tersebut Memenuhi Persyaratan atau tidak
2. Jika memenuhi akan memangil fungsi printsolution
3. Didalam fungsi tersebut ketika dipangil Variabel Jumlah akan bertambah 1
4. Jika Fungsi sudah selesai Cetak hasil dari variabel Jumlah
```

### Code

```
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int N, Jumlah = 0;
void printSolution()
{
    Jumlah += 1;                                        // Jika fungsi dipangil maka jumlah akan bertambah 1
}

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)                           // Cek bari di sisi kiri
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)  // Periksa Diagonal atas sisi kiri
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)   // Cek Diagonal bawah di sisi kiri
        if (board[i][j])
            return false;

    return true;            // Jika if diatas tidak memenuhi maka posisi row,col adalah memenuhi
}

bool selesaikan(int board[N][N], int col)
{

    if (col == N)
    {
        printSolution();           // Memanngil fungsi printsolution untuk didata
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++)
    {
        /* Check if queen can be placed on
        board[i][col] */
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;

            res = selesaikan(board, col + 1);

            board[i][col] = 0; // BACKTRACK
        }
    }

    return res;
}

void Solve()
{
    int board[N][N];
    memset(board, 0, sizeof(board));    // Set semua nilai ke 0

    if (selesaikan(board, 0) == false)
    {
        return;
    }

    return;
}

int main()
{
    scanf("%d", &N);
    Solve();                        // memanggil fungsi inti

    printf("%d\n", Jumlah);         // mencetak hasil
}
```

## Soal No 5 : Si Paling Bisa Baca Map

**Kata Kunci : Backtracking,Maze**

SYZi merupakan cowok pekerja keras yang tidak pernah libur bekerja from dusk till dawn. Suatu saat ia lelah bekerja dan memutuskan untuk pergi healing bersama istrinya. Mereka melakukan perjalanan keliling Pulau Jawa menggunakan mobil. Seperti biasa, SYZi menyetir dan menyerahkan urusan navigasi kepada istrinya. Pada aplikasi map yang digunakan, diberikan posisi awal (A) dan tujuan(B) sekaligus jalur yang bisa diambil. Bantu istri SYZi menentukan jalur terpendek untuk sampai tujuan!

### Input Format

```
5 <= X, Y <= 15
```

### Ouput Format

Output merupakan map section yang sudah terdapat pilihan jalur terpendek.

Keterangan : x merupakan path yang diambil

### Sample Input 0

```
15 15
###############
##B.....#######
#######......##
#######......##
##......#######
##......#######
#######......##
#######......##
##......#######
##......#######
#######......##
#######......##
##......#######
##..........A##
###############
```

### Sanoke Output 0

```
###############
##Bxxxxx#######
#######x.....##
#######x.....##
##.....x#######
##.....x#######
#######x.....##
#######x.....##
##.....x#######
##.....x#######
#######x.....##
#######x.....##
##.....x#######
##.....xxxxxA##
###############
```

### Langkah Penyelesaian

```
Refrensi        : https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/
                : https://www.youtube.com/watch?v=PwxGTHraMNg

Permasalahan    : Terdapat Jalur yang ganda / 2 Petak

Solusi
1. Membuat Fungsi Untuk Mencari Nilai Jarak Tercepat Yang kemudian disebut minimofroute
2. Kemudian Nilai tersebut disimpang untuk digunakan
3, Membuat fungsi untuk menandai jalan dengan mengunaan indikator Nilai tercepat yang kemudian disebut cetakroute
4. Ketika Nilai Min Fungsi cetakrout == Nilai min fungsi minimofroute maka  maka array yang memenuhi diganti dengan x
5. Memangil Fungsi cetakrout2 untuk mencetak array tersebut.
```

### Code

```
#include <stdio.h>
#include <stdbool.h>

int x, y, ai, aj, bi, bj, min = 999999;
char bambang[20][20];
bool printed = false;

void minimofroute(int P, int O, int jml_perulangan)
{
    if (bambang[P][O] == '#')
        return;
    if (P == bi && O == bj)
    {
        min = jml_perulangan < min ? jml_perulangan : min;
        return;
    }
    // printf("%d %d", P, O);
    bambang[P][O] = '#';
    minimofroute(P + 1, O, jml_perulangan + 1); // Ke Bawah
    minimofroute(P - 1, O, jml_perulangan + 1); // Ke Atas
    minimofroute(P, O + 1, jml_perulangan + 1); // Ke Kanan
    minimofroute(P, O - 1, jml_perulangan + 1); // Ke Kiri
    bambang[P][O] = '.';

    return;
}

void cetakroute(int P, int O, int jml_perulangan)
{
    if (printed)
    {
        return;
    }
    if (P == bi && O == bj)
    {
        if (min != jml_perulangan)
            return;
        printed = true;
        return;
    }

    if (bambang[P][O] == '#')
        return;
    if (bambang[P][O] == 'x')
        return;

    bambang[P][O] = 'x';
    cetakroute(P + 1, O, jml_perulangan + 1); // Ke bawah
    cetakroute(P - 1, O, jml_perulangan + 1); // Ke atas
    cetakroute(P, O + 1, jml_perulangan + 1); // Ke Kanan
    cetakroute(P, O - 1, jml_perulangan + 1); // Ke Kiri retrun selesai

    if (printed)
        return;
    bambang[P][O] = '.';

    return;
}

void cetakroute2()
{

    for (int i = 1; i <= y; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (i == ai && j == aj)
            {
                printf("A");
            }
            else if (i == bi && j == bj)
            {
                printf("B");
            }
            else
            {
                printf("%c", bambang[i][j]);
            }
        }
        printed = true;
        printf("\n");
    }
    return;
}

int main()
{

    scanf("%d %d", &x, &y);
    for (int i = 0; i <= x + 1; i++)
    {
        for (int j = 0; j <= y + 1; j++)
        {
            bambang[i][j] = '#';
        }
    }
    for (int i = 1; i <= y; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            scanf(" %c", &bambang[i][j]);
            if (bambang[i][j] == 'A')
            {
                ai = i;
                aj = j;
            }
            else if (bambang[i][j] == 'B')
            {
                bi = i;
                bj = j;
            }
        }
    }
    minimofroute(ai, aj, 0);
    cetakroute(ai, aj, 0);
    cetakroute2();

    return 0;
}
```
