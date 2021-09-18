//  

#include <stdio.h>
#include <math.h>

int main (){                                  
    int l1, l2, l3, l4;                     // 1  0  0  1      = 1 * 2^n 
    scanf("%d %d %d %d", &l1,&l2,&l3,&l4);
    int dec;                                // Variabel untuk bilangan desimal

    // perhitungan l4           n = 0
    if(l4%2==1){                // Jika Bilangan pada variabel L4 %2 bernilai 1 maka
        dec+=1;                 // Dec akan bertambah 1
    }
    // Perhitungan l3
    if(l3%2==1){                // n = 1
        dec+=2;                 // Dec akan bertambah 2    sesuai dengan rumus Binary 2^n
    }
    // Perhitungan l2
    if (l2%2==1){               // n = 2
        dec+=4;                 // Dec akan bertamabh 4 sesuai dengan rumus binary 2^n 
    }
    // Perhitungan untuk l1
    if (l1%2==1){               // n = 3
        dec+=8;                 // 2^n
    }   


// Kenapa dimod dengan 2 dikarenakan jika modulus bernilai 0 maka nilaibinary akan di skip/ diabaikkan
// Karena binary akan menghitunh 0 * 2^n
// Jika mod 2 maka binary = 1
// Yang menjadikan 1 * 2^n


    // Selesai
    switch (dec)            // Dec adalah nilai akhir
        {
        case 1:
            printf("0 1 1 0 0 0 0\n");          // nilai 1 hanya lambu b c yang menyalah
            break;
        case 2:
            printf("1 1 0 1 1 0 1\n");
            break;
        case 3:
            printf("1 1 1 1 0 0 1\n");
            break;    
        case 4:
            printf("0 1 1 0 0 1 1\n");
            break;
        case 5:
            printf("1 0 1 1 0 1 1\n");
            break;
        case 6:
            printf("1 0 1 1 1 1 1\n");
            break;
        case 7:
            printf("1 1 1 0 0 0 0\n");
            break;
        case 8:
            printf("1 1 1 1 1 1 1\n");
            break;
        case 9:
            printf("1 1 1 1 0 1 1\n");
            break;                
        case 0:
            printf("1 1 1 1 1 1 0\n");
            break;
        default:
            printf("0 0 0 0 0 0 0\n");
            break;
        }
}