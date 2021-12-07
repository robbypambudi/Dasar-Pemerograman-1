/*
FizzBuzzMore adalah versi lebih dari permainan klasik Fizz Buzz, dimana dalam Fizz Buzz klasik, kedua pemain bergantian mengucapkan angka berurutan dari 1 - n, dan dimana ada angka yang merupakan kelipatan dari 3, akan diganti dengan kata Fizz, dan dimana ada angka yang merupakan kelipatan dari 5, akan diganti dengan Buzz, dan ketika ada kelipatan dari keduanya, akan menjadi FizzBuzz, urutan keluar sesuai dengan urutan input.

Namun, versi ini akan lebih banyak, karena jumlah angka yang dites akan bervariasi.

Input Format

Baris pertama merupakan T, dimana T adalah jumlah angka kelipatan yang akan diganti dengan sesuatu

Sebanyak T baris akan berupa:

X yaitu sebuah integer yang akan dicek apakah kelipatannya keluar,

Y yaitu sebuah String yang akan menggantikan angka yang merupakan kelipatan dari X.

Baris selanjutnya adalah N

Constraints

1 <= T <= 100

1 <= N <= 1000

1 <= X <= 100

Y length is not more than 20

Output Format

Output 1 sampai N

Sample Input 0

3
3
Aku
5
Capek
15
Praktikum
20
Sample Output 0

1
2
Aku
4
Capek
Aku
7
8
Aku
Capek
11
Aku
13
14
AkuCapekPraktikum
16
17
Aku
19
Capek
Explanation 0

cape ga praktikum?
*/

#include <stdio.h>

struct data
{
    int nomer;
    char nama[20];
};

int main()
{

    int N;
    scanf("%d", &N);
    struct data a[N];

    for (int i = 1; i <= N; i++)
    {
        scanf("%d %s", &a[i].nomer, a[i].nama);
    }

    int X, status;
    scanf("%d", &X);

    for (int i = 1; i <= X; i++)
    {
        status = 0;
        for (int j = 1; j <= N; j++)
        {
            if (i % a[j].nomer == 0)
            {
                printf("%s", a[j].nama);
                status = 1;
            }
        }
        if (status == 0)
        {
            printf("%d", i);
        }
        printf("\n");
    }
}