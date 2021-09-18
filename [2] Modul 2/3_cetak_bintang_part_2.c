/* 
Membuat program apabila bertemu dengan bilangan prima akan mencetak *
dan untuk bilangan non prima akan mencetak angka
*/

#include <stdio.h>

int main (){
    int x;                      // Inisialisasi Variabel

    
    scanf("%d", &x);
    for (int i = 2; i <= x; i++){           // Perhitungan dimulai

        if (i == 2 || i == 3 || i == 5 || i == 7){
            printf("* ");
        }
        else if (i%2==0){
            printf("%d ", i);
        }
        else{
            int memori_banyak_pembagian = 1;      // memori untuk bantak pembagian
            for (int j = 2; j <= i; j++)
            {
                if (i%j==0){
                    memori_banyak_pembagian++;
                }
            }
            if (memori_banyak_pembagian < 3){
                printf("* ");
            }
            else{
                printf("%d ", i);
            }
            
        }
    }    
    printf("\n");
}