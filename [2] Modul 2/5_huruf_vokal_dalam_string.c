/*
Menerima masukan string
kemudian dihitung berapa banyak bilangan vokal yang terdapat pada string tersebut.
*/

#include <stdio.h>
#include <string.h>

int main (){
    char kata[1000];
    gets(kata);
    int banyak_huruf, panjang_kata = strlen(kata);
    
    int vokal[5]    = {'a', 'i', 'u', 'e', 'o'},
        vokal_2[5]  = {'A', 'I', 'U', 'E', 'O'};

    for (int i = 0; i < 5; i++){
        int banyak_kata = 0;

        for (int j = 0; j < panjang_kata; j++){
            if((vokal[i]==kata[j]) || (vokal_2[i] == kata[j])){
                banyak_kata+=1;
            }
        }

        switch (i)
        {
        case 0:
            printf("A/a : %d\n", banyak_kata);
            break;
        case 1:
            printf("I/i : %d\n", banyak_kata);
            break;
        case 2:
            printf("U/u : %d\n", banyak_kata);
            break;
        case 3:
            printf("E/e : %d\n", banyak_kata);
            break;
        case 4:
            printf("O/o : %d\n", banyak_kata);
            break;
        
        default:
            break;
        }


    }

}