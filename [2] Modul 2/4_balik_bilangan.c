/*
Program untuk mencetak N buah angka yang diinput secara terbalik
Input N baris pertama adalah N, baris berikutnya N buah angka
*/
#include <stdio.h>

int main (){
    int x;
    scanf("%d", &x);

    // Input Bilangan ke Array
    int arr[100];
    for (int i = 0; i< x; i++){
        scanf("%d", &arr[i]);
    }

    // Balik Bilangan
    for (int i = x-1; i >= 0; i--){
        printf("%d\n", arr[i]);
    }

    return 0;

}