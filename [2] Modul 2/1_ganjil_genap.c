#include <stdio.h>


int main (){
    int x;
    while(1){
        scanf("%d", &x);    

        if (x%2 == 0){
            printf("Genap\n");
        }
        else{
            printf("Ganjil\n");
        }
    }
}