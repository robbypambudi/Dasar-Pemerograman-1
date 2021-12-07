/*
Pada hari ini, Anto sangat senang. Ia mendapatkan nilai yang terbaik dalam kuis mata kuliah probabilitas dan statistik. Sebagai wujud rasa syukurnya, ia membeli sebanyak a mesin pembuat roti. Setiap mesin tersebut dapat membuat tak terhingga roti. Akan tetapi, setiap mesin roti hanya dapat membuat jumlah roti sesuai dengan jumlah yang telah diatur dan produksi hanya dapat dilakukan sekali. Misalnya, jika mesin roti diatur untuk membuat 5 roti, maka tiap mesin akan memproduksi tepat 5 roti dalam sekali produksi. Roti yang dapat dibuat akan dibagikan kepada b orang. Setiap orang mendapatkan jumlah roti yang sama. Akan tetapi, ia juga ingin merasakan roti tersebut. Oleh karena itu, sebelum membagikan kepada sebanyak b orang tersebut, ia mengambil tepat satu roti. Karena tidak semua jumlah mesin dan jumlah orang dapat menghasilkan ketentuan yang ia inginkan, maka ia ingin mencari tahu apakah jumlah mesin roti yang akan dibelinya dapat dipenuhi ketentuan yang diinginkannya.

Input Format

Baris pertama adalah bilangan bulat T, yaitu banyaknya testcase
T baris berikutnya berisi bilangan bulat a dan b

Constraints

1 <= T <= 100
1 <= a, b <= 10^9

Output Format

Untuk setiap testcase,
Jika jumlah mesin dan jumlah orang dapat memenuhi ketentuan, maka keluarkan Bisa dong, tiap orang dapet: x, dengan x adalah jumlah minimum roti yang dapat diterima tiap orang.
Jika jumlah mesin dan jumlah orang tidak dapat memenuhi ketentuan, maka keluarkan Nggak pas :"(

Sample Input 0

4
3 5
7 8
400241197 691553794
717536758 685411850
Sample Output 0

Bisa dong, tiap orang dapet: 1
Bisa dong, tiap orang dapet: 6
Bisa dong, tiap orang dapet: 244081804
Mesinnya nggak pas :"(
Explanation 0

Pada case pertama, setiap orang bisa mendapat 1 roti, dengan tiap mesin memproduksi 2 roti
Pada case kedua, setiap orang bisa mendapat 6 roti, dengan tiap mesin memproduksi 7 roti
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int gcd(int a, int b, int *x, int *y)
{
    if (b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int d = gcd(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - y1 * (a / b);

    return d;
}

bool find_any_solution(int a, int b, int c)
{
    int g, x0, y0;
    g = gcd(abs(a), abs(b), &x0, &y0);
    if (c % g)
    {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0)
        x0 = -x0;
    if (b < 0)
        y0 = -y0;

    while (y0 < 0)
        y0 += a;

    printf("Bisa dong, tiap orang dapet: %d\n", y0);

    return true;
}

int main()
{
    int a, b, T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &a, &b);
        if (!find_any_solution(a, -b, 1))
        {
            printf("Mesinnya nggak pas :\"(\n");
        }
    }
}