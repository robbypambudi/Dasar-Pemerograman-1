
## Soal Modul 1

1. Buatlah program yang dapat menentukan apakah suatu input bilangan dari 0 sampai 999 merupakan bilangan Armstrong

```
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main (){
    int X;                          // Variabel nilai
    bool amstrong = false;          // Kondisi Apakah Amstrong atau tidak
    scanf("%d", &X);                // Input 
    int nilai_awal = X;             // Nilai awal
    int panjang = 1, temp = X;      // Membuat var panjang awal 1 dan variabel temp sebagai penyimpan data sementara;

    while (temp != 0 && temp >= 10){       // Menghitung panjang bilangan
        panjang++;
        temp /=10;
    }
    
    if (panjang == 1){                      // Karena semua bilangan digit nya 1 adalah amstrong maka langsung bernilai true
        amstrong = true;
    }
....
```

2. Buatlah program yang hanya menerima inputan 0 sampai 999 dan 
mengeluarkan hasil berupa kalimat terbilang dari angka yang dimasukan.

```
Simple
```

3. Buatlah program yang menerima input I1, I2, I3, I4 dan keluarkan 
output berupa nilai dari ketujuh input sinyal (1 menyala, 0 mati).
(Input I1, I2, I3, I4 bertindak sebagai notasi biner. Contoh 1 0 0 0 
bernilai 8)

```
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
    
    ....
    
```

