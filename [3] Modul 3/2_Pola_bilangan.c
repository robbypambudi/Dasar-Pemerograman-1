/*
Membuat Pola bilangan seperti berikut
1 5 14 30  => Pola bilangan tersebut adalah (1 + 1^2) + (1 + 2^2) + (5 + 3^2) + (14 + 4^2)
*/

#include <stdio.h>

int pola_bilangan(int N);

int main (){

    int N;                  // Inisialisasi Variabel N

    scanf("%d", &N);
    printf("%d\n", pola_bilangan(N));

}

int pola_bilangan(int N){

    if (N == 0) return 0;       // Jika N = 0 maka akan retrun 0

    else{
        return(N * N + (pola_bilangan(N-1)));      // Jika N = 3 =>  3 * 3 + (2 * 2 + (0))  = 14
    }
}

