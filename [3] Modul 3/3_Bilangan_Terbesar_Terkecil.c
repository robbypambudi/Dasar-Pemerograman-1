// Buatlah program yang mengimplementasikan fungsi untuk menentukan bilangan terbesar
// dan terkecil dari array A dengan N bilangan.

#include <stdio.h>

void cek_max_min(int N, int x[]);           // Prototipe Fungsi

int main (){
    int N;
    scanf("%d", &N);                        // Input N

    int x[N];                               // Array x
    for (int i = 0; i < N; i++){
            scanf("%d", &x[i]);             // Input Array

    }
    cek_max_min(N,x);                       // Pangil Fungsi 

    return 0;

}

void cek_max_min(int N, int x[]){               // Fungsi 

    int Bil_besar = 0, Bil_kecil = 99999;       // Variabel Untuk mengecek besar dan kecil bilangan

    for (int i = 0; i < N; i++){
        if(x[i] >= Bil_besar){                  // Pengecekan Bilangan
            Bil_besar = x[i];
        }
        if (x[i] <= Bil_kecil){                 // Pengecekan Bilangan
            Bil_kecil = x[i];
        }
    }
    printf("max: %d\n", Bil_besar);             // Cetak Bilangan Terbesar
    printf("min: %d\n", Bil_kecil);             // Cetak Bilangan Terkecil

    return;

}

