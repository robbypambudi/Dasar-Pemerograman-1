/* 
Membuat program apabila bertemu dengan bilangan prima akan mencetak *
dan untuk bilangan non prima akan mencetak angka

antara 2 - N
*/

#include <stdio.h>

int main (){
    int x;                                               // Inisialisasi Variabel

    
    scanf("%d", &x);
    for (int i = 2; i <= x; i++){                       // Perhitungan dimulai

        if (i == 2 || i == 3 || i == 5 || i == 7){      // Bilangan prima dasar
            printf("* ");
        }
        else if (i%2==0){                               // Deteksi Bilangan genap
            printf("%d ", i);
        }
        else{
            int dapat_dibagi_sebanyak = 1;            // memori untuk bantak pembagian
            for (int j = 2; j <= i; j++)                // Jika Bilangan Ganjil dan Terindikasi Bil Prima 
            {
                if (i%j==0){                            
                    dapat_dibagi_sebanyak++;          // Jika hasil mod = 0 maka memorinya akan bertambah 1
                }
            }
            if (dapat_dibagi_sebanyak < 3){         // Jika hanya dapat dibagi oleh 2 bilangan maka prima
                printf("* ");
            }
            else{
                printf("%d ", i);                   // Jika Tidak Maka Bilangan ganjil
            }
            
        }
    }    
    printf("\n");
}