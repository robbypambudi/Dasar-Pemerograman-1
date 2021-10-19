# SOAL DAN PEMBAHASAN

## Soal No 1 Mencari maksimal area dari lingkaran yang dibagi-bagi

**Sumber Penyelesaian**
- https://en.wikipedia.org/wiki/Dividing_a_circle_into_areas

 SYZi merupakan perusahan yang berfokus pada bidang minimarket. Pada tahun 2042 perusahaan SYZi berencana untuk menguasai perekonomian Benua Asia dengan cara membangun minimarket di berbagai lahan Benua Asia.

 Strategi yang perusahaan SYZi lakukan yaitu dengan menggunakan sistem lahan lingkaran. Penerapan sistem lahan lingkaran adalah dengan membangun minimarket pada titik di sekeliling lingkaran. Setelah itu ditarik garis yang menghubungkan setiap minimarket dengan minimarket lainnya. Agar sistem lahan lingkaran dapat bekerja dengan efektif maka tidak boleh ada 3 garis yang saling berpotongan pada satu titik. Banyak ruang yang terbentuk dalam lahan lingkaran menentukan banyaknya pembagian lahan penjualan.

 Jika perusahaan SYZi membangun n minimarket yang tidak saling berhimpit pada sekeliling lingkaran, tentukan berapa banyak pembagian lahan penjualan per sistem!

**Input Format**

 Baris pertama berupa bilangan bulat q yang menunjukkan banyaknya sistem. Untuk setiap sistem, diberikan n yaitu banyak minimarket yang dibangun pada suatu sistem.

**Constraints**
 - 0 < q < 69
 - 0 < n < 2^63 + 1

**Output Format**

 Untuk setiap sistem/kasus uji, keluarkan banyaknya lahan penjualan. Namun, karena sistem yang dibuat oleh perusahaan SYZi masih dalam tahap uji coba, maka keluarkan banyaknya lahan penjualan yang dihasilkan dimodulo 10^9 + 7. 

**Sample Input 0**
```
5
1 2 3 4 5
```
**Sample Output 0**
```
1
2
4
8
16
```

**Sample Input 1**
```
3
16 12 2003
```

**Sample Output 0**
```
1941
562
670500828
```
**Source Code**
```
#include <stdio.h>
#define MODD 1000000007

int main(){
    int angka;
    unsigned long long bil, x, data[5];
    scanf("%d", &angka);
    
    while(angka--){
        x = 0; 
        scanf("%llu", &bil);
        for(int i = 0; i<5; i++){
            data[i] = 0;
        }
        data[0]=1;     
        for(int i = 2;i<=bil;i++){
            data[4] = (data[4] % MODD + data[3] % MODD) % MODD; 
            data[3] = (data[3] % MODD + data[2] % MODD) % MODD;   
            data[2] = (data[2] % MODD + data[1] % MODD) % MODD;
            data[1] = (data[1] % MODD + data[0] % MODD) % MODD;
            data[0] = 1; 
        }
        for(int i= 0; i < 5; i++){
            x = (x + data[i] % MODD) % MODD; 
        }
    printf("%lld\n", x);
    }
return 0;
}
```

## Soal No 2 Enkripsi dan Dekripsi

Bambang Sumanto adalah seorang detektif, ia mendapatkan sebuah pesan dari Sherlock Holmes yang harus dipecahkan, cara mecahinnya gimana? Kalo kalian bisa baca ini, harusnya udah bisa ya. Nah si Bambang ini mau buat program buat membaca pesan dari Sherlock Holmes, dan ngirim pesan ke Sherlock dengan cara yang sama. Untuk membedakan input, bambang memiliki input code dan key, code 1 untuk decrypt dan code 2 untuk encrypt. Selanjutnya key itu yang bakal dipake buat jadi kunci shift caesarnya. Yang diproses hanya huruf saja ya! Selain huruf di print tanpa diproses. Bantuin si bambang ya, plis. 

**Input Format**
Baris pertama adalah T, yaitu menyatakan jumlah kasus uji

**Output Format**
Setiap kasus uji memiliki 2 baris, baris pertama berisi C yaitu code dan K yaitu key, baris kedua merupakan kalimat yang ingin di encrypt/decrypt

**Constraints**
0 ≤ T ≤ 100
0 < C ≤ 2
0 ≤ K ≤ 26
kalimat tidak lebih dari 100 character

**Output Format**
Tiap baris uji kasus berisi kalimat yang telah di proses

**Sample Input 0**
```
2
1 1
bambang suka makan
2 5
wvhwvib npfv hvfvi
```

**Sample output 0**

```
azlazmf rtjz lzjzm
bambang suka makan
```

**Source Code**
```
#include <stdio.h>
#include <string.h>

int main (){
    unsigned int T;
    char kata[110];
    char sandi[110];
    unsigned int C;
    int K;

    scanf("%u\n", &T);

    for (int i = 0; i< T; i++){
        scanf("%u %d\n", &C, &K);

        if(C == 1  && K <= 26 && K >= 0){
            scanf("%[^\n]", kata);
            if (strlen(kata) <= 100){
            
            for (int j = 0; j<= strlen(kata); j++){
                if (kata[j] == 32 || kata[j] <= 64 || (kata[j] == 91 || kata[j] == 92 || kata[j] == 93 || kata[j] == 94 || kata[j] == 95 || kata[j] == 96) || kata[j] >= 123){
                    continue;
                }
                else if (kata[j] < 91 && kata[j] >= 65){
                    if ((kata[j] - K) <= 64){
                        int temp = 65 - kata[j] + K;
                        kata[j] = 91;
                        kata[j] -= temp;
                    }
                    else {
                        kata[j] -= K;
                    }
                }
                else if ((kata[j] - K) < 97){
                    int temp = 97 - kata[j] + K;
                    kata[j] = 123;
                    kata[j] -= temp;
                }
                    else {
                    kata[j] -= K;
                }
            }
                
            }
        } else if (C == 2 && K <= 26 && K >= 0){
            scanf("%[^\n]", sandi);
            if (strlen(sandi) <= 100){
              
            for (int a = 0; a <= strlen(sandi); a++){
                if (sandi[a] == 32 || sandi[a] <= 64 || (sandi[a] == 91 || sandi[a] == 92 || sandi[a] == 93 || sandi[a] == 94 || sandi[a] == 95 || sandi[a] == 96) || sandi[a] >= 123){
                    continue;
                }
                else if (sandi[a] < 91 && sandi[a] >= 65){
                    if ((sandi[a] + K) > 90){
                        int temp = sandi[a] + K;
                        temp    -= 91;
                        sandi[a] = 65 + temp;
                    }
                    else {
                        sandi[a] += K;
                    }
                }
                else if (sandi[a]+K > 122){
                    int temp = sandi[a] +K;
                    temp -= 122;
                    sandi[a] = 96 + temp;
                }
                else {
                    sandi[a] += K;
                
                }
            }
            }
        }

        if (C == 1 && K <= 26 && K >= 0){
            printf("%s\n", kata);
        }
        else if ( C == 2 && K <= 26 && K >= 0) {
            printf("%s\n", sandi);
        }
    }
}
```

## Soal No 3 Menentukan Polindrome atau tidak.
Bambang Sumanto adalah seorang masinis, pada suatu hari, Bambang diminta untuk membuat sistem penomoran gerbong kereta. Karena kereta tidak bisa memutar balik, maka kereta bisa jalan 2 arah maju atau mundur. Oleh karena itu, Bambang memiliki ide untuk menomori gerbong kereta sehingga nomor itu akan sama jika dibaca dari depan, maupun dari belakang.

Misalnya, 5435345, jika dibaca dari depan dan dari belakang, angkanya akan sama. Karena Bambang tidak memiliki kecerdasan untuk mengecek jika angka yang dibuatnya sesuai dengan peraturan, bantulah Bambang untuk mengecek urutan gerbong tersebut.

nah, karena Bambang adalah Bang Gerbong, dia anti banget pake string dan array, cuma maunya pake perulangan aja.

Maka, DILARANG PAKE ARRAY & STRING.H :), emang Bambang suka ngerepotin maaf ya temen".

**Input Format**
1 baris angka bilangan bulat N yaitu urutan gerbong kereta

**Constraints**
0 <= N <= 2^64 -1

**Output Format**
Jika sesuai dengan peraturan, maka outputkan "YAK BISA"

Jika tidak sesuai dengan peraturan, maka outputkan "SALAH BAMBANG"

**Sample Input 0**
```
4214554124
```

**Sample Ouput 0**
```
YAK BISA
```

**Source Code**
```
#include <stdio.h>

int main (){
    unsigned long long int x, modd, hasil = 0;
    scanf("%llu",&x);
    unsigned long long int temp = x;
    
    while (x > 0){
        modd = x%10;
        hasil = hasil *10 + modd;
        x /= 10;
    }
    

    if (temp == hasil){
        printf("YAK BISA\n");
    }
    else {
        printf("SALAH BAMBANG\n");
    }
}
```

