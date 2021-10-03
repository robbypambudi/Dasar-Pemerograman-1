/*
Menerima masukan string
kemudian dihitung berapa banyak bilangan vokal yang terdapat pada string tersebut.
*/

#include <stdio.h>
#include <string.h>

int main (){
    char kata[1000];
    scanf("%[^\n]", kata);                                                  // mendatkan banyak kata
    int banyak_huruf, panjang_kata = strlen(kata);
    
    int vokal[5]    = {'a', 'i', 'u', 'e', 'o'},                 // Huruf Vokal biasa
        vokal_2[5]  = {'A', 'I', 'U', 'E', 'O'};                 // Huruf Vokal Kapital

    for (int i = 0; i < 5; i++){        
        int banyak_vokal = 0;                                    // Variabel Banya

        for (int j = 0; j < panjang_kata; j++){     
            if((vokal[i]==kata[j]) || (vokal_2[i] == kata[j])){     // Mengambil data di array
                banyak_vokal+=1;                                    // Jika memenuhi nilanya akan bertambah
            }
        }

        switch (i)                                                  // Selesai
        {
        case 0:
            printf("A/a : %d\n", banyak_vokal);
            break;
        case 1:
            printf("I/i : %d\n", banyak_vokal);
            break;
        case 2:
            printf("U/u : %d\n", banyak_vokal);
            break;
        case 3:
            printf("E/e : %d\n", banyak_vokal);
            break;
        case 4:
            printf("O/o : %d\n", banyak_vokal);
            break;
        
        default:
            break;
        }


    }

}