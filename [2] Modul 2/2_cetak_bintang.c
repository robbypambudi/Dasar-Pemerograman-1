// Buatlah program untuk mencetak asterisk *, untuk bilangan genap dan 
// bilangan aslinya untuk bilangan ganjil

#include <stdio.h>

int main (){
    int x;
    scanf("%d", &x);
    for(int i = 1; i<=x;i++){
        if(i%2==0){             // Jika Genap
            printf(" * ");
        }
        else{
            printf("%d", i);    // Jika Ganjil
        }
    }
    printf("\n");
}
