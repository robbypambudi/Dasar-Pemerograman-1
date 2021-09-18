# Selamat Datang
Silahkan Dibaca dan dipahami code-code dibawah ini :

1.  Buatlah program yang mengimplementasikan fungsi rekursif untuk menentukan nilai dari N! (N faktorial).
```
#include <stdio.h>
 
int faktorial(int x)
{
    if (x == 0) return 1;                   // Jika x = 0 return 1; atau base case

    return(x * faktorial(x -1));            // Jika x = 3 maka akan terbentuk seperti return (3 * 2 * 1)
}
 
int main()
{
    int x; 
    scanf("%d", &x);

    printf("%d\n", faktorial(x));

    return 0;
}

```

2. Diberikan sebuah baris bilangan 1, 5, 14, 30, ... dst. Buatlah sebuah program yang mengimplementasikan fungsi rekursif untuk menentukan 
bilangan ke-n dari pola tersebut.

```
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
```

3. Buatlah program yang mengimplementasikan fungsi untuk menentukan bilangan terbesar dan terkecil dari array A dengan N bilangan.
Contoh Input
```
5
1 2 3 4 5
```
Contoh Output
```
max: 5
min: 1
```

```
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

```
