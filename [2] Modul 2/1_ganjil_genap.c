#include <stdio.h>

int main (){
    int x;

    scanf("%d", &x);    

    if (x%2 == 0){                  // Jika di Mod 2 = 0 maka bilangan tersebut bilangan ganjil
        printf("Genap\n");
    }
    else{
        printf("Ganjil\n");
    }
}