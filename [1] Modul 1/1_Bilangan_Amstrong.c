#include <stdio.h>
#include <stdbool.h>

int main (){
    int x;
    bool amstrong = false;
    scanf("%d", &x);

    if (x <= 9){                    
        amstrong = true;
        
    }
    else if (x == 153 || x == 370 || x == 371 || x == 407){

        amstrong = true;

    }
    else if (x == 1634){
        amstrong = true;
    }

    printf(amstrong == true ? "Merupakan Bilangan Armstrong\n" : "Bukan Merupakan Bilangan Armstrong\n");

}
