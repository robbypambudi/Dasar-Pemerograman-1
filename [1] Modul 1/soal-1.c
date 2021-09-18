//  https://ideone.com/4BOn1P

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

    else{
        int result = 0;                             // Sebagai Variabel yang menyimpan data hasil
        temp    = X;                                    // Mengunakan kembali variabel sementara
        for (int i = 1; i <= panjang; i++){             // Perulangan dari 1 sampai panjang
            temp = X%10;                            // Untuk menampilkan hasil digit akhir 
            result += pow(temp,panjang);
            X/=10;                                  // dibagi 10 untuk menghilangkan digit terakhir
        }

        if (result == nilai_awal){                  // Jika amstrong true maka merupakan bil amstrong 
            amstrong = true;
        }
    }


    printf(amstrong == true ? "Merupakan Bilangan Armstrong\n" : "Bukan Merupakan Bilangan Armstrong\n");

}