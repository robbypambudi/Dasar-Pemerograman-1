// Buatlah program untuk mencetak asterisk *, untuk bilangan genap dan 
// bilangan aslinya untuk bilangan ganjil

#include <stdio.h>

int main (){
    int x;
    while (1)
    {
        scanf("%d", &x);
        for(int i = 1; i<=x;i++){
            if(i%2==0){
                printf(" * ");
            }
            else{
                printf("%d", i);
            }
        }
        printf("\n");
    }
    
}
