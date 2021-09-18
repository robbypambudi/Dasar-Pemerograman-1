//  https://ideone.com/7qUUHm

#include <stdio.h>

int main (){
    int X;
    scanf("%d", &X);
                                    // Untuk mempercepat perhitungan saya bagi menjadi 5 Blok yaitu blok 1-20, 21-40, 41-60, 61-80, 80-100;
    if (X <= 20){                   // 1 - 20
        switch (X)
        {
        case 1:
            printf("Satu\n");
            break;
        case 2:
            printf("Dua\n");        
            break;
        case 3:
            printf("Tiga\n");
            break;
        case 4:
            printf("Empat\n");
            break;    
        case 5:
            printf("Lima\n");
            break;
        case 6:
            printf("Enam\n");
            break;
        case 7:
            printf("Tujuh\n");
            break;    
        case 8:
            printf("Delapan\n");
            break;
        case 9:
            printf("Sembilan\n");
            break;
        case 10:
            printf("Sepuluh\n");
            break;
        case 11:
            printf("Sebelas\n");
            break;
        case 12:
            printf("Dua belas\n");
            break;
        case 13:
            printf("Tiga belas\n");
            break;
        case 14:
            printf("Empat belas\n");
            break;
        case 15:
            printf("Lima belas\n");
            break;    
        case 16:
            printf("Enam belas\n");
            break;
        case 17:
            printf("Tujuh belas\n");
            break;
        case 18:
            printf("Delapan belas\n");
            break;
        case 19:
            printf("Sembilan belas\n");
            break;
        case 20:
            printf("Dua puluh\n");
            break;
        }
        
    }
    else if ((X > 20) && (X <= 40)){                      // 21 - 40 
        switch (X)
        {
        case 21:
            printf("Dua Puluh satu\n");
            break;
        case 22:
            printf("Dua Puluh Dua\n");
            break;
        case 23:
            printf("Dua Puluh tiga\n");
            break;
        case 24:
            printf("Dua Puluh empat\n");
            break;    
        case 25:
            printf("Dua Puluh lima\n");
            break;
        case 26:
            printf("Dua Puluh enam\n");
            break;
        case 27:
            printf("Dua Puluh tujuh\n");
            break;    
        case 28:
            printf("Dua Puluh delapan\n");
            break;
        case 29:
            printf("Dua Puluh sembilan\n");
            break;
        case 30:
            printf("Tiga Puluh \n");
            break;
        case 31:
            printf("Tiga Puluh Satu\n");
            break;
        case 32:
            printf("Tiga Puluh Dua\n");
            break;
        case 33:
            printf("Tiga Puluh tiga\n");
            break;
        case 34:
            printf("Tiga Puluh empat\n");
            break;    
        case 35:
            printf("Tiga Puluh lima\n");
            break;
        case 36:
            printf("Tiga Puluh enam\n");
            break;
        case 37:
            printf("Tiga Puluh tujuh\n");
            break;    
        case 38:
            printf("Tiga Puluh delapan\n");
            break;
        case 39:
            printf("Tiga Puluh sembilan\n");
            break;
        case 40:
            printf("Empat Puluh \n");
            break;  
        }      
    }
    else if ((X > 40) && (X <= 60)){
        switch (X)
        {
        
            case 41:
                printf("Empat puluh Satu\n");
                break;
            case 42:
                printf("Empat puluh Dua\n");
                break;
            case 43:
                printf("Empat puluh tiga\n");
                break;
            case 44:
                printf("Empat puluh empat\n");
                break;    
            case 45:
                printf("Empat puluh lima\n");
                break;
            case 46:
                printf("Empat puluh enam\n");
                break;
            case 47:
                printf("Empat puluh tujuh\n");
                break;    
            case 48:
                printf("Empat puluh delapan\n");
                break;
            case 49:
                printf("Empat puluh sembilan\n");
                break;
            case 50:
                printf("Lima Puluh\n");
                break;

            case 51:
                printf("Lima Puluh Satu\n");
                break;
            case 52:
                printf("Lima Puluh Dua\n");
                break;
            case 53:
                printf("Lima Puluh tiga\n");
                break;
            case 54:
                printf("Lima Puluh empat\n");
                break;    
            case 55:
                printf("Lima Puluh lima\n");
                break;
            case 56:
                printf("Lima Puluh enam\n");
                break;
            case 57:
                printf("Lima Puluh tujuh\n");
                break;    
            case 58:
                printf("Lima Puluh delapan\n");
                break;
            case 59:
                printf("Lima Puluh sembilan\n");
                break;  
            case 60:
                printf("Enam Puluh\n");
                break;
        }  
        
    }
    else if ((X > 60) && (X <= 80)){                   // 61 - 80
        switch (X)
        {
            case 61:
                printf("Enam Puluh Satu\n");
                break;
            case 62:
                printf("Enam Puluh Dua\n");
                break;
            case 63:
                printf("Enam Puluh tiga\n");
                break;
            case 64:
                printf("Enam Puluh empat\n");
                break;    
            case 65:
                printf("Enam Puluh lima\n");
                break;
            case 66:
                printf("Enam Puluh enam\n");
                break;
            case 67:
                printf("Enam Puluh tujuh\n");
                break;    
            case 68:
                printf("Enam Puluh delapan\n");
                break;
            case 69:
                printf("Enam Puluh sembilan\n");
                break;
            case 70:
                printf("Tujuh Puluh");
                break;
            case 71:
                printf("Tujuh Puluh Satu\n");
                break;
            case 72:
                printf("Tujuh Puluh Dua\n");
                break;
            case 73:
                printf("Tujuh Puluh tiga\n");
                break;
            case 74:
                printf("Tujuh Puluh empat\n");
                break;    
            case 75:
                printf("Tujuh Puluh lima\n");
                break;
            case 76:
                printf("Tujuh Puluh enam\n");
                break;
            case 77:
                printf("Tujuh Puluh tujuh\n");
                break;    
            case 78:
                printf("Tujuh Puluh delapan\n");
                break;
            case 79:
                printf("Tujuh Puluh sembilan\n");
                break;   
            case 80:
                printf("Delapan Puluh");
                break;
        }
    }
    else if (X > 80 && X <=100){                   // 81 - 100
        switch (X)
        {
            case 81:
                printf("Delapan Puluh Satu\n");
                break;
            case 82:
                printf("Delapan Puluh Dua\n");
                break;
            case 83:
                printf("Delapan Puluh tiga\n");
                break;
            case 84:
                printf("Delapan Puluh empat\n");
                break;    
            case 85:
                printf("Delapan Puluh lima\n");
                break;
            case 86:
                printf("Delapan Puluh enam\n");
                break;
            case 87:
                printf("Delapan Puluh tujuh\n");
                break;    
            case 88:
                printf("Delapan Puluh delapan\n");
                break;
            case 89:
                printf("Delapan Puluh sembilan\n");
                break;
            case 90:
                printf("Sembilan Puluh\n");
                break;

            case 91:
                printf("Tujuh Puluh Satu\n");
                break;
            case 92:
                printf("Tujuh Puluh Dua\n");
                break;
            case 93:
                printf("Tujuh Puluh tiga\n");
                break;
            case 94:
                printf("Tujuh Puluh empat\n");
                break;    
            case 95:
                printf("Tujuh Puluh lima\n");
                break;
            case 96:
                printf("Tujuh Puluh enam\n");
                break;
            case 97:
                printf("Tujuh Puluh tujuh\n");
                break;    
            case 98:
                printf("Tujuh Puluh delapan\n");
                break;
            case 99:
                printf("Tujuh Puluh sembilan\n");
                break;    
            case 100:
                printf("Seratus");
                break;

            
        }
    }
    else{
        printf("Lebih dari 100 :)\n");
    }

}
