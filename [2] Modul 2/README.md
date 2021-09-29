# Latian Soal Daspro Modul 2

## Soal 1
1. Buat program yang mencetak kata Ganjil untuk bilangan ganjil, dan kata Genap untuk bilangan genap dari sebuah input
```
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


```

2. Buat program untuk mencetak asterisk, *, untuk bilangan genap, dan bilangan aslinya untuk bilangan ganjil, dari n buah bilangan mulai 1 s.d n.
```
#include <stdio.h>

int main (){
    int x;
    scanf("%d", &x);
    for(int i = 1; i<=x;i++)
      {
        if(i%2==0){             // Jika Genap
            printf(" * ");
        }
        else{
            printf("%d", i);    // Jika Ganjil
        }
    }
    printf("\n");
}
```

3. Buat program untuk mencetak asterisk, *, untuk bilangan prima, dan angka asli untuk bilangan non-prima dari n buah bilangan mulai 2 s.d n.
```
#include <stdio.h>

int main (){
    int x;                                               // Inisialisasi Variabel

    
    scanf("%d", &x);
    for (int i = 2; i <= x; i++){                       // Perhitungan dimulai

        if (i == 2 || i == 3 || i == 5 || i == 7){      // Bilangan prima dasar
            printf("* ");
        }
        else if (i%2==0){                               // Deteksi Bilangan genap
            printf("%d ", i);
        }
        else{
            int dapat_dibagi_sebanyak = 1;            // memori untuk bantak pembagian
            for (int j = 2; j <= i; j++)                // Jika Bilangan Ganjil dan Terindikasi Bil Prima 
            {
                if (i%j==0){                            
                    dapat_dibagi_sebanyak++;          // Jika hasil mod = 0 maka memorinya akan bertambah 1
                }
            }
            if (dapat_dibagi_sebanyak < 3){         // Jika hanya dapat dibagi oleh 2 bilangan maka prima
                printf("* ");
            }
            else{
                printf("%d ", i);                   // Jika Tidak Maka Bilangan ganjil
            }
            
        }
    }    
    printf("\n");
}
```

4. Buatlah program untuk mencetak N buah angka yang diinput secara terbalik. Input baris pertama adalah N yang merupakan banyaknya angka 
yang akan diinput. Baris berikutnya terdapat N buah angka (dipisahkan 
spasi).
```
#include <stdio.h>

int main (){
    int x;
    scanf("%d", &x);                    // Menerima Masuka

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
```

5. Buatlah sebuah program untuk menghitung jumlah huruf vokal yang terdapat pada sebuah string S. Panjang string S tidak melebihi 100 
karakter dan terdiri dari huruf lowercase, uppercase dan spasi.
```
#include <stdio.h>
#include <string.h>

int main (){
    char kata[1000];
    gets(kata);                                                  // mendatkan banyak kata
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

```

6. Diberikan sebuah nama variabel dalam bentuk snake_case. Buatlah program untuk mengubah nama variabel tersebut menjadi bentuk camelCase.Nama variabel hanya terdiri dari huruf lowercase, uppercase, dan simbol underscore.
```
#include <stdio.h>
#include <string.h>         

int main (){
    char b[1000];
    gets(b);                                       // *Ingat Bilangan ASCII 
    int panjang_string = strlen(b);         

    for (int i =0; i < panjang_string; i++){        
        if (b[i] <= 90 && b[i] >= 65){                      // Jika Bilangan ASCII berada di 65 <= x <= 90 Maka huruf Capital
            b[i] += 32;                                     // huruf ditambah dengan 32 agar menjadi kecil
        }
        if (b[i] == 95){                                      // Jika huruf underscore/ 95
            //memmove(&b[i] , &b[i+1], panjang_string-i);     // Dapat Mengunakan ini manipulasi memori

            for (int j = i; j < panjang_string; j++){   // Atau Ini
                b[j] = b[j+1];
            }
            if(b[i] > 90){                              // Membuat Huruf Besar Setelah _ 
                b[i] -= 32;
            }
        }
    }
    printf("%s\n", b);                                          // Cetak Hasil
}

```

# Terimakasih Telah Datang Di Github Saya
## Jangan Lupa Follow github saya.
### Apabila ada kesalahan bisa Kontak di IG @robby.pambudi
