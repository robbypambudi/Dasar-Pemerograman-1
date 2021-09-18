/*
Diberikan sebuah nama variabel dalam bentuk snake_case. 
Buatlah program untuk mengubah nama variabel tersebut menjadi bentuk camelCase. 
Nama variabel hanya terdiri dari huruf lowercase, uppercase, dan simbol underscore.
*/

#include <stdio.h>
#include <string.h>

int main (){
    char b[1000];
    gets(b);
    int panjang_string = strlen(b);

    for (int i =0; i < panjang_string; i++){
        if (b[i] <= 90 && b[i] >= 65){
            b[i] += 32;
        }
        if (b[i] == 95){
            memmove(&b[i] , &b[i+1], panjang_string-i);
            panjang_string -=1;
            i--;
        }
    }
    printf("%s\n", b);

}