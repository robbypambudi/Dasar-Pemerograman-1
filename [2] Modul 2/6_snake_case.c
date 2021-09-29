/*
Diberikan sebuah nama variabel dalam bentuk snake_case. 
Buatlah program untuk mengubah nama variabel tersebut menjadi bentuk camelCase. 
Nama variabel hanya terdiri dari huruf lowercase, uppercase, dan simbol underscore.
*/

#include <stdio.h>
#include <string.h>         

int main (){
    char b[1000];
    gets(b);                                       // *Ingat Bilangan ASCII 
    int panjang_string = strlen(b);         

    for (int i =0; i < panjang_string; i++){        
        if (b[i] <= 90 && b[i] >= 65){                      // Jika Bilangan ASCII berada di 65 <= x <= 90 Maka huruf Capital
            b[i] += 32;                                     // huruf ditambah dengan 32 agar menjadi kecil
        }
        if (b[i] == 95){                                      // Jika huruf underscore/ 95
            //memmove(&b[i] , &b[i+1], panjang_string-i);     // Dapat Mengunakan ini manipulasi memori

            for (int j = i; j < panjang_string; j++){   // Atau Ini
                b[j] = b[j+1];
            }
            if(b[i] > 90){                              // Membuat Huruf Besar Setelah _ 
                b[i] -= 32;
            }
        }
    }
    printf("%s\n", b);                                          // Cetak Hasil
}
