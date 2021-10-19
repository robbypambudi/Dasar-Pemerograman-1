// Implementasikan fungsi bernama tambah berisi 3 parameter, di mana parameter pertama merupakan bilangan 1,
//  parameter kedua merupakan bilangan 2, dan parameter terakhir adalah variabel tempat hasil output.

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