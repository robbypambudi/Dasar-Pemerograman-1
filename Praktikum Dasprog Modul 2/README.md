# SOAL DAN PEMBAHASAN

## Soal No 1 Mencari maksimal area dari lingkaran yang dibagi-bagi

**Sumber Penyelesaian**

-   https://en.wikipedia.org/wiki/Dividing_a_circle_into_areas

SYZi merupakan perusahan yang berfokus pada bidang minimarket. Pada tahun 2042 perusahaan SYZi berencana untuk menguasai perekonomian Benua Asia dengan cara membangun minimarket di berbagai lahan Benua Asia.

Strategi yang perusahaan SYZi lakukan yaitu dengan menggunakan sistem lahan lingkaran. Penerapan sistem lahan lingkaran adalah dengan membangun minimarket pada titik di sekeliling lingkaran. Setelah itu ditarik garis yang menghubungkan setiap minimarket dengan minimarket lainnya. Agar sistem lahan lingkaran dapat bekerja dengan efektif maka tidak boleh ada 3 garis yang saling berpotongan pada satu titik. Banyak ruang yang terbentuk dalam lahan lingkaran menentukan banyaknya pembagian lahan penjualan.

Jika perusahaan SYZi membangun n minimarket yang tidak saling berhimpit pada sekeliling lingkaran, tentukan berapa banyak pembagian lahan penjualan per sistem!

**Input Format**

Baris pertama berupa bilangan bulat q yang menunjukkan banyaknya sistem. Untuk setiap sistem, diberikan n yaitu banyak minimarket yang dibangun pada suatu sistem.

**Constraints**

```
0 < q < 69
0 < n < 2^63 + 1
```

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

**Input Format** <br>
Baris pertama adalah T, yaitu menyatakan jumlah kasus uji

**Output Format**<br>
Setiap kasus uji memiliki 2 baris, baris pertama berisi C yaitu code dan K yaitu key, baris kedua merupakan kalimat yang ingin di encrypt/decrypt

**Constraints**

```
 0 ≤ T ≤ 100
 0 < C ≤ 2
 0 ≤ K ≤ 26
 kalimat tidak lebih dari 100 character
```

**Output Format** <br>
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

**Input Format**<br>
1 baris angka bilangan bulat N yaitu urutan gerbong kereta

**Constraints**

```
0 <= N <= 2^64 -1
```

**Output Format**<br>
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

## Soal No 4 Prima -> Polindrome -> Hasil

Pada suatu hari, Anton sedang putus asa karena perjalanan Anton utuk mencari jodoh masih belum berhasil. Akhirnya Anton pun mempunyai sebuah ide, ia mengunduh sebuah aplikasi bernama Biro Jodoh Online dan dalam aplikasi tersebut setiap akun wanita memiliki id akun di sebelah nama mereka. Anton pun akhirnya memutuskan untuk meng-gacha akun-akun wanita yang akan dikontak olehnya yang dimana wanita tersebut harus memiliki id akun yang berupa bilangan bulat positif mulai dari 1 dan unik. Id akun yang unik tersebut merupakan suatu id yang jika dibaca dari belakang memiliki kesamaan jika dibaca dari depan. Id tersebut juga harus hanya bisa dibagi oleh bilangan 1 dan bilangan itu sendiri. Biro Jodoh Online telah diunduh oleh kurang dari 1000000 wanita. Urutan Anton memilih id yang akan dipilih adalah dengan mengacak sebuah angka dan mengambil angka setelahnya yang memenuhi syarat id unik. Tapi, Anton sangat pusing karena dibebani oleh rasa putus asanya, maka dia meminta bantuan kamu untuk membuatkan program dalam mencari id akun wanita yang sesuai dengan permintaan Anton.

Note : Jangan dikuli ya ges :)

**Input Format** <br>
Beberapa baris, masing-masing berisi sebuah bilangan bulat.

**Constraints**

```
Time Limtis : 1 Seconds
Memory Limtis : 256 MB
```

**Output Format** <br>
Beberapa baris, masing-masing keluarkan "#i : " dimana i merupakan urutan gacha, lalu diikuti angka sesuai dengan permintaan Anton, tetapi jika bilangan yang diinputkan merupakan bilangan unik itu sendiri, keluarkan bilangan tersebut.

**Sample Input 0** <br>

```
9
95
131
```

**Sample Output 0** <br>

```
#1 : 11
#2 : 101
#3 : 131
```

**Source Code** <br>

```
#include <stdio.h>
#include <stdbool.h>
#define max 1000000
int main (){
    int awal = 0;
    int prima[max];
    bool isprime[max];

    for (int i = 0; i <= max; i++){
        isprime[i] = 1;
    }

    // Membuat Bilangan Prima
    for (int i = 2; i <= max; i++){
        if(isprime[i]){
            prima[awal++] = i;

            for (int j = i *2; j<= max; j+=i) isprime[j] = 0;
        }
    }

    int temp, evl , poli = 0, pal[max];

    // Cek apakah Polianderm
    for (int i = 0; i < awal; i++){
        temp = prima[i];
        evl = 0;
        while (temp >0){
            evl = evl*10 + (temp%10);
            temp /=10;
        }
        if (evl == prima[i]){
            pal[poli++] = evl;
        }
    }

    int n;
    long long int gacha = 1;

    while(scanf("%d", &n) != EOF){
    //for (int i = 1; i <800; i++){
      //  n = i;
        if (n <= 2) printf("#%lld : 2\n", gacha++);
        else if (n > pal[poli-1]) printf("#%lld : 1003001\n", gacha++);
        else {
            for (int i = 0; i < poli; i++){
                if (n <= pal[i]){
                    printf("#%lld : %d\n", gacha++, pal[i]);
                    break;
                }
            }
        }
    }
    return 0;
}
```

## Soal No 5 Cek Koin Yang sama

Malur ingin membeli kartu remi untuk main nanti. Dia mempunyai jumlah uang yang tidak terbatas, sayangnya dia hanya mempunyai uang itu dalam 2 jenis koin saja. 2 nilai koin tersebut berbeda. Sambil menunggu Malur antri beli, Malur ingin mengetahui berapa jumlah cara untuk membayar kartu ini.

**Input Format** <br>
baris pertama berisi bilangan bulat positif T yang merupakan jumlah testcase T baris berikutnya berisi 3 bilangan bulat positif yaitu A, B dan X. A merupakan nilai nominal koin pertama, B merupakan nilai nominal koin kedua, dan X merupakan harga dari kartu yang ingin dibeli.

**Sample Input 0**

```
2
3 2 10
2 3 20
```

**Constraints**

```
1 ≤ T ≤ 100
1 ≤ A, B ≤ 100
A ≠ B
1 ≤ X ≤ 2000000
```

**Output Format** <br>

```
2
4
```

**Explanation** Testcase 1 : 3 2 10 <br>

```
untuk harga 10 dapat dibeli dengan cara :

    5 koin 2 + 0 koin 3
    2 koin 2 + 2 koin 3
```

**Sample Input 0**

```
2
3 2 10
2 3 20
```

**Sample Output 0**

```
2
4
```

**Source Code**

```
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int data[n][3];
    for(int x=0; x<n; x++){
        scanf("%d%d%d", &data[x][0], &data[x][1], &data[x][2]);
    }
    for(int x= 0; x<n; x++){
        int temp=0;

        for(int i= 0; i<=data[x][2]; i++){
            int j=0;

            while((data[x][0]*i)+
                        (data[x][1]*j)<=data[x][2]){

                if((data[x][0]*i)+(data[x][1]*j)
                        ==data[x][2]){
                    temp++;
                }
                j++;
            }
        }
        printf("%d\n", temp);
    }
    return 0;
}
```

### Soal No 6 Scaning Area Tanah

Malur mempunyai tambang aluminium PT. Sukses. Seperti nama perusahaannya, Malur ingin melakukan penggalian dengan baik dan menjadi sukses. Sebelum dilakukan penggalian dilakukan scanning pada tanah berukuran x * y yang akan digali. Dalam penggalian digunakan sebuah alat dimana menggali petak berukuran s*s

**input format** <br>
baris pertama berisi x dan y. y baris berikutnya berisi x jumlah alluminium bernilai m. baris terakhir berisi s ukuran alat

```
3 3
1 1 1
2 1 1
1 1 1
2
```

**Constraints**

```
1 ≤ x ≤ 100
1 ≤ y ≤ 100
0 < m < 2^31
0 < s ≤ 10
```

**Output format** <br>
outputkan jumlah maksimum alluminium dalam sekali gali

```
5
```

**Sample Input 0**

```
3 3
1 1 1
2 1 1
1 1 1
2
```

**Sample Output 0**

```
5
```

**Source Code**

```
#include <stdio.h>

int main (){
    int x, y;
    int s;
    scanf("%d %d", &x, &y);
    int A[y][x];

    for (int i = 0; i <y; i++){
        for (int j=0; j<x; j++){
            scanf("%d", &A[i][j]);
        }
    }
    scanf("%d", &s);
    int terbeser = 0;
    int hasil = 0;
    if (s != 0 && x != 0 && y != 0){
        for (int i = 0; i <= y -s; i++){
            for (int j = 0; j <= x - s; j++){
                hasil = 0;
                for (int  a = i; a < i + s; a++){
                    for (int b = j; b < j + s; b++){
                        hasil += A[a][b];
                        // printf("%d %d\n", a, b);
                    }
                }
            if (hasil > terbeser){
                terbeser = hasil;
                }
            }
        }
        printf("%d\n", terbeser);
    }
}
```

## SUMBER SOAL

-   Praktikum Dasar Pemrograman ITS Modul 2

Berdasarkan hasil penelitian mengenai stres mahasiswa tingkat awal Institut Teknologi Sepuluh Nopember, didapatkan bahwa sebagian besar mahasiswa berada di kategori tingkat stres parah yaitu sebanyak 38.71% (12 orang), dilanjutkan dengan sebanyak 19,35% (6 orang) yang mengalami tingkat stres normal, 25,81% (8 orang) mengalami tingkat stres sedang, dan sebanyak 16,13% (5 orang) yang mengalami tingkat stres parah. Faktor stres yang paling banyak disebut oleh responden adalah banyaknya tugas yang disertai deadline yang singkat. Hal ini mungkin merupakan kasus yang wajar dikarenakan mahasiswa tingkat awal masih melalui proses perpindahan dari tingkat SMA ke tingkat kuliah. Ada juga beberapa faktor lain yang merupakan akibat dari kuliah daring. Faktor-faktor tersebut adalah membantu anggota keluarga, dan kurangnya interaksi sosial.

### Input Format
