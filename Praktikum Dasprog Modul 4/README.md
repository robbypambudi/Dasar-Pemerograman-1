# Soal dan Pembahasan Praktikum Dasar Pemrograman Modul 4

## Soal No 1 : Anton Semakin Dekat

Anton akhirnya sudah menemukan wanita yang sesuai dengan kriterianya dan dia ingin memberikan hadiah yang terbaik untuknya supaya dia dapat menjadi pasangan wanita tersebut. Namun, ia memiliki banyak pilihan yang membuatnya kebingungan sehingga kamu diminta membuatkan program untuk membantunya memilih hadiah sesuai dengan boneka hewan,warna,dan nomor favorit wanita tersebut.

**Program tersebut haruslah menerapkan prinsip struct.**

### Input Format

Baris pertama berisi bilangan n yang merupakan banyak pilihan hadiah yang tersedia.

n+1 baris selanjutnya terdiri dari boneka hewan s,warna w,dan bilangan x dengan baris terakhir merupakan kriteria hadiah yang sesuai dengan favorit si wanita.

### Constraints

```
1 ≤ t ≤ 30
1 ≤ |s| ≤ 30, |s| merupakan panjang s
1 ≤ |w| ≤ 20, |w| merupakan panjang w
1 ≤ n ≤ 100
```

### Output Format

Cek apakah hadiah favorit wanita tersebut ada pada pilihan hadiah yang tersedia. Jika tersedia maka cetak "Asik hadiahnya ada^^", tetapi jika tidak tersedia maka cetak "Bantu aku langit :(". Cetak hasil tanpa tanda kutip("").

### Sample Input 0

```
2
singa hijau 10
paus merah 5
singa hijau 10
```

### Sample Output 0

```
Asik hadiahnya ada^^
```

### Sample Input 1

```
3
Landak coklat 15
Lumba-lumba merah 47
macan jingga 58
babi merah 47
```

### Sample Output 1

```
Bantu aku langit :(
```

### Langkah Penyelesaian

-   Membuat Struct
-   Membandingkan dengan strcmp
-   Selesai

### Code

```
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct HADIAH
{
    char hewan[50];
    char warna[50];
    int x;
};

int main()
{
    int N;
    char hewan_dicari[50], warna_dicari[50];
    int angka;

    scanf("%d", &N);
    struct HADIAH hadiah[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%s %s %d", hadiah[i].hewan, hadiah[i].warna, &hadiah[i].x);
    }

    scanf("%s, %s, %d", hewan_dicari, warna_dicari, &angka);

    bool apakahadahewan = false, apakahadawarna = false, apakahdanomer = false;
    for (int i = 0; i < N; i++)
    {
        if ((strcmp(hadiah[i].hewan, hewan_dicari) == 0))
        { // Jika Hewan tidak ada
            apakahadahewan = true;
        }
    }
    for (int i = 0; i < N; i++)
        if ((strcmp(hadiah[i].warna, warna_dicari) == 0)) // Jika warna tidak ada
        {
            apakahadawarna = true;
        }

    for (int i = 0; i < N; i++)
        if (!(hadiah[i].x == angka)) // Jika warna tidak ada
        {
            apakahdanomer = true;
        }

    if (apakahdanomer && apakahadahewan && apakahdanomer)
        printf("Asik hadiahnya ada^^");
    else
        printf("Bantu aku langit :(");

    return 0;
}
```

## Soal No 2 : Data Management

Soalnya gampang aja, kamu diminta untuk membuat sistem CRUD (Create, Read, Update, Delete) untuk mengatur data. Data yang dimasukkan berupa nama orang(name), nomor id(nid), jumlah mobil yang dimiliki(a), jumlah motor yang dimiliki(b), dan jumlah sepeda yang dimiliki(c). Agar program terlihat lebih rapi, masing-masing perintah dibuat satu function tersendiri dan data ditempatkan pada sebuah struct. Setiap selesai suatu perintah berikan newline.

-   Create(name,nid,a,b,c) -> akan memasukkan data-data ke dalam sistem dan keluarkan "Data telah ditambahkan" tanpa tanda kutip("").
-   Read(i,j) -> membaca dan mengeluarkan data ke-i hingga data ke-j dimana masing-masing kategori data dipisahkan dengan spasi. Jika data yang diminta melebihi batas, maka keluarkan "Data tidak ditemukan" tanpa tanda kutip(""). Jika terdapat data yang hilang(sudah didelete) tampilkan saja "Data telah dihapus" tanpa tanda kutip(""). Setiap selesai membaca suatu data berikan newline.

**Kasus khusus untuk Read All berarti membaca semua data yang ada.**

-   Update(name,nid,+/-a,+/-b,+/-c) -> memperbarui data dengan nid yang diberikan jika ada. Jika data ditemukan, maka perbarui data dan keluarkan "Data telah diperbarui" tanpa tanda kutip(""). Jika sebaliknya, maka keluarkan "Data tidak ditemukan" tanpa tanda kutip("").

**Tanda +/- berarti update dapat menambah kendaraan maupun mengurangi kendaraan, misalnya +3 akan bertambah 3, sedangkan -2 akan berkurang 2.**

-   Delete(i) -> menghapus data ke-i jika data masih ada. Jika data yang ingin dihapus melebihi batas, maka keluarkan "Data tidak ditemukan" tanpa tanda kutip(""). Jika data masih ada, maka hapus data dan keluarkan "Data telah dihapus" tanpa tanda kutip(""), tetapi jika data sudah terhapus keluarkan "Data sudah kosong" tanpa tanda kutip("").

**Note : Parameter fungsi dapat bervariasi tidak harus seperti contoh.**

### Input Format

Baris pertama berisi bilangan n dan t yang menyatakan jumlah data yang dicreate dan jumlah perintah yang diberikan.

n baris berikutnya berisi data-data yang akan dicreate.

t baris berikutnya berisi perintah-perintah yang harus dijalankan.

### Constraints

```
1 ≤ n ≤ 50
1 ≤ t ≤ 25
1 ≤ |nama orang| ≤ 20, |nama orang| merupakan panjang nama orang dan nama orang hanya terdiri dari 1 kata
|nomor id| = 5, |nomor id| merupakan banyak digit nomor id
0 ≤ jumlah masing-masing kendaraan ≤ 1000
nama orang bisa sama tetapi id pasti berbeda dan tidak pernah berubah
```

### Output Format

Eksekusi perintah yang diberikan dan tampilkan pada layar.

### Sample Input 0

```
5 5
Adi 00001 10 5 6
Budi 00002 4 7 8
Cani 00003 15 8 3
Dedi 00004 18 3 2
Eni 00005 17 18 3
Read All
Delete 2
Update Eni 00005 -11 -5 +2
Create Fani 00006 10 6 9
Read 2 6
```

### Sample Output 0

```
Adi 00001 10 5 6
Budi 00002 4 7 8
Cani 00003 15 8 3
Dedi 00004 18 3 2
Eni 00005 17 18 3

Data telah dihapus

Data telah diperbarui

Data telah ditambahkan

Data telah dihapus
Cani 00003 15 8 3
Dedi 00004 18 3 2
Eni 00005 6 13 5
Fani 00006 10 6 9
```

### Sample Input 1

```
8 6
Andi 10005 8 6 7
Boni 10006 3 6 4
Zeta 10007 10 2 0
Caca 10008 4 3 1
Sun 10009 5 0 3
Flin 10010 7 9 3
Gio 10011 8 5 1
Vey 10012 9 6 3
Delete 4
Update Zela 10007 +0 +3 +2
Delete 10
Read 1 10
Delete 4
Read All
```

### Sample Output 1

```
Data telah dihapus

Data telah diperbarui

Data tidak ditemukan

Andi 10005 8 6 7
Boni 10006 3 6 4
Zela 10007 10 5 2
Data telah dihapus
Sun 10009 5 0 3
Flin 10010 7 9 3
Gio 10011 8 5 1
Vey 10012 9 6 3
Data tidak ditemukan
Data tidak ditemukan

Data sudah kosong

Andi 10005 8 6 7
Boni 10006 3 6 4
Zela 10007 10 5 2
Data telah dihapus
Sun 10009 5 0 3
Flin 10010 7 9 3
Gio 10011 8 5 1
Vey 10012 9 6 3
```

### Langkah Penyelesaian

-   Membuat Sebuah Fungsi Create Read and Read All Delete Update
-   Membuat Struct dengan Tambahan variabel kondisi untuk menandai apakah valid atau tidak
-   Pertama kali dibuat struct kondisi akan bernilai true
-   Jika dihapus maka akan bernilai false
-   kemudian dijalankan
-   Selesai

### Code

```
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Data
{
    char nama[150];
    int id;
    int jumlah_mobil;
    int jumlah_motor;
    int jumlah_speda;
    bool status;
};

void ReadAll(struct Data *data, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (data[i].status == true)
        {
            printf("%s %05d %d %d %d\n", data[i].nama, data[i].id, data[i].jumlah_mobil, data[i].jumlah_motor, data[i].jumlah_speda);
        }
        else
        {
            printf("Data telah dihapus\n");
        }
    }
    printf("\n");
}

void Delete(struct Data *data, int angka, int n)
{
    if (angka < 0)
    {
        printf("Data tidak ditemukan\n");
    }
    else if (n < angka)
    {
        printf("Data tidak ditemukan\n");
    }
    else if ((n >= angka) && (data[angka].status == true))
    {
        data[angka].status = false;
        printf("Data telah dihapus\n");
    }
    else if ((n >= angka) && (data[angka].status == false))
    {
        printf("Data sudah kosong\n");
    }
    else if (n < angka)
    {
        printf("Data tidak ditemukan\n");
    }
    printf("\n");
}

void Perbarui(struct Data *data, char nama[], int data_1, int data_2, int data_3, int alamat)
{
    strcpy(data[alamat].nama, nama);
    data[alamat].jumlah_mobil += data_1;
    data[alamat].jumlah_motor += data_2;
    data[alamat].jumlah_speda += data_3;

    if (data[alamat].jumlah_mobil < 0)
        data[alamat].jumlah_mobil = 0;
    if (data[alamat].jumlah_motor < 0)
        data[alamat].jumlah_motor = 0;
    if (data[alamat].jumlah_speda < 0)
        data[alamat].jumlah_speda = 0;

    printf("Data telah diperbarui\n");
    printf("\n");
}

void Read(struct Data *data, int X, int Y, int N)
{
    for (int i = X - 1; i < Y; i++)
    {
        if (i < 0)
        {
            printf("Data tidak ditemukan\n");
        }
        else if ((i < N) && (data[i].status == true))
        {
            printf("%s %05d %d %d %d\n", data[i].nama, data[i].id, data[i].jumlah_mobil, data[i].jumlah_motor, data[i].jumlah_speda);
        }
        else if ((i < N) && (data[i].status == false))
        {
            printf("Data telah dihapus\n");
        }
        else if (i >= N)
        {
            printf("Data tidak ditemukan\n");
        }
    }
    printf("\n");
}

void Create(struct Data *data, int *N, char nama[], int id, int data1, int data2, int data3)
{
    // Cek apakah sudah ada

    strcpy(data[*N].nama, nama);
    data[*N].id = id;
    data[*N].jumlah_mobil = data1;
    data[*N].jumlah_motor = data2;
    data[*N].jumlah_speda = data3;
    data[*N].status = true;
    *N += 1;
    printf("Data telah ditambahkan\n");
}
int main()
{
    int n, t;
    scanf("%d %d", &n, &t);
    struct Data data[60];
    if (n < 1 && t < 1)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d %d\n", data[i].nama, &data[i].id, &data[i].jumlah_mobil, &data[i].jumlah_motor, &data[i].jumlah_speda);
        data[i].status = true;
    }

    // Perintah
    char Perintah[20], nama[30];
    char nama_perintah[10];
    int angka, data1, data2, data3, id;

    for (int i = 0; i < t; i++)
    {
        angka = 0;
        scanf("%s", Perintah);

        // Untuk Read
        if (strcmp(Perintah, "Read") == 0)
        {
            scanf("%s", nama_perintah);

            if (strcmp(nama_perintah, "All") == 0)
            {
                ReadAll(data, n);
            }
            else
            {
                for (int j = 0; j < strlen(nama_perintah); j++)
                {
                    if (nama_perintah[j] >= '0' && nama_perintah[j] <= '9')
                    {
                        angka = angka * 10 + nama_perintah[j] - '0';
                    }
                }
                int angka2 = 0;
                scanf("%d", &angka2);
                Read(data, angka, angka2, n);
            }
        }
        // Untuk Delete
        else if (strcmp(Perintah, "Delete") == 0)
        {
            scanf("%d", &angka);
            Delete(data, angka-1, n-1);
        }
        // Untuk Update
        else if (strcmp(Perintah, "Update") == 0)
        {
            int alamat;
            scanf("%s %d %d %d %d", nama, &id, &data1, &data2, &data3);
            for (int i = 0; i < n; i++)
            {
                alamat = i;
                if ((id == data[i].id) && (data[i].status == true))
                {
                    Perbarui(data, nama, data1, data2, data3, alamat);
                    break;
                }
                else if ((id == data[i].id) && (data[i].status == false))
                {
                    printf("Data tidak ditemukan\n");
                    printf("\n");
                    break;
                }
                if ((i == n - 1) && (data[i].id != id))
                {
                    printf("Data tidak ditemukan\n");
                    printf("\n");
                    break;
                }
            }
        }
        // Untuk Create
        else if (strcmp(Perintah, "Create") == 0)
        {
            scanf("%s %d %d %d %d", nama, &id, &data1, &data2, &data3);
            data[n].status = true;
            Create(data, &n, nama, id, data1, data2, data3);
            printf("\n");
        }
    }
}
```

## Soal No 3 : bamBank™

Bambang Sumanto adalah pemilik bank bamBank™. Tetapi, dengan semakin banyaknya nasabah yang ingin menabung di bank bamBank™. Bambang Sumanto berminat untuk membuat sebuah aplikasi yang bisa mengelola bank bamBank milik Bambang.

Aplikasi bamBank™ menyimpan ID, nama pemilik, dan saldo dari nama-nama nasabah bamBank™. Saat membuka rekening, nasabah diwajibkan menyetor saldo sebanyak 100 untuk pengganti biaya pembukaan akun.

Aplikasi bamBank™ memiliki 2 fitur yaitu untuk menyetor atau menarik saldo yang ada. Peraturan bank bamBank™ milik Bambang adalah sebagai berikut:

1. Ketika saldo lebih dari 1000, maka setiap akun tersebut melakukan penyetoran uang, akan dikenakan biaya operasional sebesar 20. Peraturan ini berlaku secara immediate setelah kondisi terpenuhi
2. Jika jumlah uang yang ingin ditarik melebihi saldo, maka seluruh saldo akan ditarik, sehingga saldo menjadi 0

### Input Format

Baris pertama berisi bilangan bulat p, menandakan jumlah akun yang ingin dibuat

Kemudian, p baris berikutnya berisi ID serta nama pemilik

Selanjutnya akan ada 3 jenis input

-   jika input 1, maka 2 input berikutnya adalah ID dan j yaitu jumlah uang yang ingin disetor
-   jika input 2, maka 2 input berikutnya adalah ID dan j yaitu jumlah uang yang ingin ditarik
-   jika input 0, maka keluar dari program

### Constraints

```
1 ≤ p ≤ 100
1 ≤ j ≤ 100000, bilangan bulat
nama pemilik length is not more than 20
1 ≤ ID ≤ 100, setiap ID unik
```

### Output Format

```
Akun #
ID
nama
saldo akhir
# adalah urutan input
```

### Sample Input 0

```
2
1 Clarence
2 Bambang
1
1 500
1
2 2000
2
1 1000
0
```

### Sample Output 0

```
Akun 1
1
Clarence
0
Akun 2
2
Bambang
2080
```

### Explanation 0

```
saldo awal

1 → Clarence → 100

2 → Bambang → 100

--

Input awal 1 berarti akan menyetor yaitu menyetor 500 ke akun id = 1

Saldo Clarence → 100+500 = 600

--

input kedua kode 1 berarti akan menyetor yaitu menyetor 2000 ke akun id = 2

Saldo Bambang → 100 + 2000, karena saldo 2100, yaitu lebih dari 1000 maka dikenakan biaya operasional, Saldo Bambang → 2080

--

input ketiga kode 2 berarti menarik, yaitu menarik 1000 dari akun id = 1

karena saldo cuma 600, maka ditarik semua sisa 0.
```

### Langkah Penyelesaian

-   Menyimpan Data Kedalam Struct
-   Membuat perulangan dengan while
-   Ketika inputan 0
-   Cetak Data yang ada dalam struct

### Code

```
#include <stdio.h>
struct Bank
{
    int id;
    char nama[25];
    long int saldo;
};

int main()
{

    int p;
    scanf("%d", &p);
    struct Bank bank[p];
    for (int i = 0; i < p; i++)
    {
        scanf("%d %[^\n]", &bank[i].id, bank[i].nama);
        bank[i].saldo = 100;
    }
    int j, id;
    long int saldo_baru;
    while (scanf("%d", &j) != 0)
    {
        if (j == 0)
        {
            break;
        }
        if (j == 1)
        {
            scanf("%d %ld", &id, &saldo_baru);
            for (int i = 0; i < p; i++)
            {
                if (id == bank[i].id)
                {
                    bank[i].saldo += saldo_baru;
                    if (bank[i].saldo > 1000)
                    {
                        bank[i].saldo -= 20;
                    }
                }
            }
        }

        if (j == 2)
        {
            scanf("%d %ld", &id, &saldo_baru);
            for (int i = 0; i < p; i++)
            {
                if (id == bank[i].id)
                {
                    if (bank[i].saldo < saldo_baru)
                    {
                        bank[i].saldo = 0;
                    }
                    else
                    {
                        bank[i].saldo -= saldo_baru;
                    }
                }
            }
        }
    }
    for (int i = 0; i < p; i++)
    {
        printf("Akun %d\n", i + 1);
        printf("%d\n", bank[i].id);
        printf("%s\n", bank[i].nama);
        printf("%ld\n", bank[i].saldo);
    }
    return 0;
}
```

## Soal No 4 :

Malur sedang belajar hal baru yang sangat menyulitkan dia, yaitu pointer. Dia telah belajar sepanjang malam dan ingin mengaplikasikan apa yang telah ia buat. Problem yang ingin dia selesaikan sederhana namun harus diselesesaikan dengan pointer. Problemnya adalah sebagai berikut, diberikan sebuah matrix N x M. Setiap elemen terletak pada posisi baris i dan kolom j. Malur hanya ingin menghitung jumlah setiap elemen yang nilai i dan j nya tidak sama.

```
Pengerjaan hanya boleh menggunakan syntax pointer * tidak boleh menggunakan array [val1][val2], seperti saat scanf, printf, dan ketika mengakses elemen matrix. Untuk deklarasi variable array awal diperboleh kan menggunakan array[val1][val2].
```

### Input Format

Baris pertama berisi 2 nilai yaitu M dan N. M Baris berikutnya berisi N buah bilangan matrix.

```
3 3
1 2 3
4 5 6
7 8 9
```

### Constraints

```
2<=M<=15
2<=N<=15
2<=i<=M
2<=j<=N
2<=matrix[i][j]<=100
```

### Output Format

Output yang dihasilkan adalah semua elemen matrix yang berada pada posisi baris i dan kolom j yang berbeda.

```
2 3 4 6 7 8
30
```

### Sample Input

```
3 3
1 2 3
4 5 6
7 8 9
```

### Sample Output 0

```
2 3 4 6 7 8
30
```

### Langkah Penyelesaian

-   Cara mengakses array pada pointer adalah seperti gambar berikut
    <img src="https://i1.wp.com/aticleworld.com/wp-content/uploads/2018/04/2darray.jpg?resize=678%2C495&ssl=1" alt="Accses Array in Pointer">
-   Dari gambar tersebut maka dapat dibuat sebuah kode sebagai berikut

### Code

```
#include <stdio.h>

void fungsi(int *N, int *M, int array[20][20]);

int main()
{
    int N, M;

    scanf("%d %d", &N, &M);
    int array[20][20];

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", *(array + i) + j);
        }
    }
    fungsi(&N, &M, array);
}
void fungsi(int *N, int *M, int array[20][20])
{
    int hasil = 0;

    for (int x = 1; x <= *N; x++)
    {
        for (int y = 1; y <= *M; y++)
        {

            if (x != y)
            {
                hasil += *(*(array + x) + y);
                printf("%d ", *(*(array + x) + y));
            }
        }
    }
    printf("\n");
    printf("%d\n", hasil);
}
```

---

## Soal No 5

SYZi baru saja belajar pointer. Akan tetapi, SYZi masih belum begitu paham dengan pointer ini. Jadi SYZi memintamu untuk membuat program simulasi pointer. Program ini dapat menerima 3 jenis perintah : init, modify, print.

Perintah init digunakan untuk membuat suatu variable. variabel yang bisa dibuat ada 2 saja, yaitu integer dan pointer to integer. format perintah init adalah sebagai berikut :

<img src="https://s3.amazonaws.com/hr-assets/0/1636250707-ce26fcb314-poin1.jpeg" alt="Gambar 1"/>

Jika akan membuat variabel biasa maka pointer dikosong kan, apabila akan membuat variabel pointer maka pointer diisi . Saat perintah init diharuskan untuk mengisi variabel, dengan kata lain (value) tidak boleh kosong. Isi variabel tak dapat diisi oleh nama variabel lain, dengan kata lain variabel biasa harus diisi angka dan variabel pointer harus diisi alamat variable biasa. Penulisan seperti no 3, 4, dan 5 tidak bisa dilakukan.

Perintah modify digunakan untuk mengubah isi dari variabel yang sudah dibuat. format perintah modify adalah sebagai berikut :

<img src="https://s3.amazonaws.com/hr-assets/0/1636250746-fe19ff3c99-poin2.jpeg" alt="Gambar 2"/>

Jika akan merubah isi secara normal, maka pointer dikosongkan. Jika ingin merubah apa yang ditunjuk oleh sebuah pointer maka pointer diisi 1 pointer. value tidak dapat diisi nama variabel untuk mengisi variabel tersebut. Penulisan seperti no 4 dan 5 tidak bisa dilakukan.

Perintah print digunakan untuk mengeluarkan output berupa isi variabel. Format perintah print adalah sebagai berikut:

<img src="https://s3.amazonaws.com/hr-assets/0/1636251070-5ff359b024-poin3.jpeg" alt="Gambar 3"/>

Variabel yang dapat diprint hanyalah variabel biasa dan bukan variabel pointer. Penulisan seperti no 2, 3, dan 4 tidak bisa dilakukan.

### Input Format

Baris pertama merupakan bilangan bulat positif N yang merupakan banyak command masukan Input sesuai syntax diatas. Input yang dimasukkan tidak mungkin melanggar peraturan diatas.

### Constraints

```
0 < N < 20
0 < panjang nama variabel < 10
0 < jumlah variabel yang dibuat < 11
value yang dapat disimpan hanyalah sebatas besar int di C.
```

### Output Format

Program hanya akan mengeluarkan output saat ada perintah print.

### Sample Input 0

```
4
init var1 5
init var2 10
print var1
print var2
```

### Sample Output 0

```
5
10
```

### Langkah Penyelesaian

1. Membuat Fungsi Init, Modify dan Pointer
2. Fungsi dibuat sesuai dengan deskripsi diatas
3. Selesai

### Code

```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
struct Data
{
    char nama[50];
    int *nilai;
    bool ispointer;
};

// Deklarasi Fungsi prototipe
void init(struct Data *data, int N, int list);
void modify(struct Data *data, int N, int list);
void print(struct Data *data, int N);

int main()
{

    int N, X = 0;
    scanf("%d", &N);

    // Inisialisasi Variabel
    struct Data data[N];
    char perintah[20];

    for (int i = 0; i < N; i++)
    {
        scanf("%s", perintah);

        if (strcmp(perintah, "init") == 0)
        {
            init(data, N, X++);
        }

        if (strcmp(perintah, "modify") == 0)
        {
            modify(data, N, X);
        }

        if (strcmp(perintah, "print") == 0)
        {
            print(data, X);
        }
    }
    return 0;
}

// Fungsi init

void init(struct Data *data, int N, int list)

{
    // Inisialisasi Variabel
    char variabel_1[15], variabel_2[15], variabel_3[15], variabel_4[15];
    // printf("Init Jalan\n");
    scanf("%s", variabel_1);

    // Dengan *
    if (strcmp(variabel_1, "*") == 0)
    {
        // printf("* Jalan");
        data[list].nilai = malloc(sizeof(int));
        data[list].ispointer = true;

        scanf("%s %s", variabel_2, variabel_3);
        int panjang = strlen(variabel_2);
        char *temp = variabel_3 + 1;
        strncpy(variabel_4, temp, panjang - 1);

        for (int i = 0; i < list; i++)
        {
            if (strcmp(variabel_4, data[i].nama) == 0)
            {
                strcpy(data[list].nama, variabel_2);
                data[list].nilai = data[i].nilai;
                // printf("Berhasil Disi ke %s", data[list].nama);
            }
        }
    }
    else
    {
        // printf("Berhasil %d\n", list);
        data[list].nilai = malloc(sizeof(int));
        data[list].ispointer = false;
        int nilai = 0;
        scanf("%d", &nilai);
        strcpy(data[list].nama, variabel_1);
        *data[list].nilai = nilai;
        // printf("%s %d\n", data[list].nama, *data[list].nilai);
    }
}

void modify(struct Data *data, int N, int list)

{

    char variabel_1[15], variabel_2[15], variabel_3[15];

    scanf("%s", variabel_1);
    // printf("%s\n",variabel_1);

    if (strcmp(variabel_1, "*") == 0)
    {
        // printf("Jalan\n");
        int nilai;
        scanf("%s %d", variabel_2, &nilai);

        for (int i = 0; i < N; i++)
        {
            if (strcmp(variabel_2, data[i].nama) == 0)
            {
                *data[i].nilai = nilai;
            }
        }
    }

    else
    {
        // printf("modify Jalan\n");
        scanf(" %s", variabel_2);
        // printf("2 %s \n", variabel_2);

        if (variabel_2[0] >= '0' && variabel_2[0] <= '9')
        {
            // printf("angka terdeteksi %s\n", variabel_2);

            int angka = 0;
            int panjang = strlen(variabel_2);
            for (int i = 0; i < panjang; i++)
            {
                angka = angka * 10 + variabel_2[i] - '0';
            }

            for (int i = 0; i < N; i++)
            {
                if (strcmp(variabel_1, data[i].nama) == 0)
                {
                    // printf("Data %d", angka);
                    *data[i].nilai = angka;
                    break;
                }
            }
        }
        else if (variabel_2[0] == '&')
        {
            // printf("& Jalan\n");
            char *temp = variabel_2 + 1;
            int panjang = strlen(variabel_1);
            strncpy(variabel_3, temp, panjang - 1);
            // printf("Variabel 1 : %s, Vaiabel 2 : %s", variabel_1, variabel_3);
            int sudah = 0;
            for (int i = 0; i < N; i++)
            {
                if (strcmp(variabel_1, data[i].nama) == 0)
                {
                    for (int j = 0; j < N; j++)
                    {
                        if (strcmp(variabel_3, data[j].nama) == 0)
                        {
                            // printf("Berhasil\n");
                            *data[i].nilai = *data[j].nilai;
                            sudah = 1;
                            break;
                        }
                    }
                }
                if (sudah)
                    break;
            }
        }
    }
    return;
}

void print(struct Data *data, int N)
{
    char variabel[15];
    // printf("print jalan\n");
    scanf("%s", variabel);
    for (int i = 0; i < N; i++)
    {
        // printf("%d\n", i);
        if (strcmp(variabel, data[i].nama) == 0 && !data[i].ispointer)
        {
            printf("%d\n", *data[i].nilai);
        }
    }
    return;
}
```

---

## Soal No 6

Universitas SYZi mengadakan sebuah perlombaan bernama Schoomatics. Anda sebagai budak kepanitiaan diberi mandat untuk membuat program pemeringkatan peserta lomba dari data yang belum urut. Kolom dari data tersebut adalah nama, nilai 1, nilai 2, dan nilai 3. Anda diminta untuk mengurutkan data tersebut berdasarkan nilai 3. Jika terdapat nama dengan nilai 3 yang sama maka urutkan berdasarkan nilai 2. Jika terdapat nama dengan nilai 2 yang sama maka urutkan berdasarkan nilai 1. Jika masih ada yang sama juga maka urutkan berdasarkan nama. Nama diurutkan berdasarkat ASCII.

### Input Format

baris pertama adalah jumlah nama n n baris berikutnya ada 4 input yaitu nama dan 3 nilai nama n1 n2 n3

### Constraints

0 < nilai < 100

### Output Format

data yang sudah terurut

### Sample Input 0

```
4
clarence 100 99 1
dzikri 24 03 03
erki 86 96 2
frederick 69 69 69
```

### Sample Output 0

```
frederick 69 69 69
dzikri 24 3 3
erki 86 96 2
clarence 100 99 1
```

### Langkah Penyelesaian

1. Membuat Fungsi untuk menentukan rangking
2. Rangking diurutkan dari nilai ke 3 Jika sama ke nilai ke 2 dan jika masi sama ke nilai 1
3. Apabila masi sama maka diurutkan berdasarkan bilangan ASCII
4. Selesai

```
#include <stdio.h>
#include <string.h>

struct Mahasiswa
{
    char nama[50];
    int nilai_1;
    int nilai_2;
    int nilai_3;
    int total_nilai;
};

void sorting(int N, struct Mahasiswa *mhs)
{
    int a, nilai_1, nilai_2, nilai_3;
    char nama[50];
    // Mengurutkan Nama
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {

            if (mhs[i].nilai_3 < mhs[j].nilai_3)
            {
                a = mhs[i].total_nilai;
                strcpy(nama, mhs[i].nama);
                nilai_1 = mhs[i].nilai_1;
                nilai_2 = mhs[i].nilai_2;
                nilai_3 = mhs[i].nilai_3;

                mhs[i].total_nilai = mhs[j].total_nilai;
                mhs[i].nilai_1 = mhs[j].nilai_1;
                mhs[i].nilai_2 = mhs[j].nilai_2;
                mhs[i].nilai_3 = mhs[j].nilai_3;
                strcpy(mhs[i].nama, mhs[j].nama);

                mhs[j].total_nilai = a;
                mhs[j].nilai_1 = nilai_1;
                mhs[j].nilai_2 = nilai_2;
                mhs[j].nilai_3 = nilai_3;
                strcpy(mhs[j].nama, nama);
            }
            if ((mhs[i].nilai_2 < mhs[j].nilai_2) && (mhs[i].nilai_3 == mhs[j].nilai_3))
            {
                a = mhs[i].total_nilai;
                strcpy(nama, mhs[i].nama);
                nilai_1 = mhs[i].nilai_1;
                nilai_2 = mhs[i].nilai_2;
                nilai_3 = mhs[i].nilai_3;

                mhs[i].total_nilai = mhs[j].total_nilai;
                mhs[i].nilai_1 = mhs[j].nilai_1;
                mhs[i].nilai_2 = mhs[j].nilai_2;
                mhs[i].nilai_3 = mhs[j].nilai_3;
                strcpy(mhs[i].nama, mhs[j].nama);

                mhs[j].total_nilai = a;
                mhs[j].nilai_1 = nilai_1;
                mhs[j].nilai_2 = nilai_2;
                mhs[j].nilai_3 = nilai_3;
                strcpy(mhs[j].nama, nama);
            }
            if ((mhs[i].nilai_1 < mhs[j].nilai_1) && (mhs[i].nilai_3 == mhs[j].nilai_3) && (mhs[i].nilai_2 == mhs[j].nilai_2))
            {
                a = mhs[i].total_nilai;
                strcpy(nama, mhs[i].nama);
                nilai_1 = mhs[i].nilai_1;
                nilai_2 = mhs[i].nilai_2;
                nilai_3 = mhs[i].nilai_3;

                mhs[i].total_nilai = mhs[j].total_nilai;
                mhs[i].nilai_1 = mhs[j].nilai_1;
                mhs[i].nilai_2 = mhs[j].nilai_2;
                mhs[i].nilai_3 = mhs[j].nilai_3;
                strcpy(mhs[i].nama, mhs[j].nama);

                mhs[j].total_nilai = a;
                mhs[j].nilai_1 = nilai_1;
                mhs[j].nilai_2 = nilai_2;
                mhs[j].nilai_3 = nilai_3;
                strcpy(mhs[j].nama, nama);
            }
            if ((mhs[i].nilai_1 == mhs[j].nilai_1) && (mhs[i].nilai_3 == mhs[j].nilai_3) && (mhs[i].nilai_2 == mhs[j].nilai_2))
            {
                if (mhs[i].nama[0] < mhs[j].nama[0])
                {
                    a = mhs[i].total_nilai;
                    strcpy(nama, mhs[i].nama);
                    nilai_1 = mhs[i].nilai_1;
                    nilai_2 = mhs[i].nilai_2;
                    nilai_3 = mhs[i].nilai_3;

                    mhs[i].total_nilai = mhs[j].total_nilai;
                    mhs[i].nilai_1 = mhs[j].nilai_1;
                    mhs[i].nilai_2 = mhs[j].nilai_2;
                    mhs[i].nilai_3 = mhs[j].nilai_3;
                    strcpy(mhs[i].nama, mhs[j].nama);

                    mhs[j].total_nilai = a;
                    mhs[j].nilai_1 = nilai_1;
                    mhs[j].nilai_2 = nilai_2;
                    mhs[j].nilai_3 = nilai_3;
                    strcpy(mhs[j].nama, nama);
                }
                if ((mhs[i].nama[0] == mhs[j].nama[0]) && (mhs[i].nama[1] < mhs[j].nama[1]))
                {
                    a = mhs[i].total_nilai;
                    strcpy(nama, mhs[i].nama);
                    nilai_1 = mhs[i].nilai_1;
                    nilai_2 = mhs[i].nilai_2;
                    nilai_3 = mhs[i].nilai_3;

                    mhs[i].total_nilai = mhs[j].total_nilai;
                    mhs[i].nilai_1 = mhs[j].nilai_1;
                    mhs[i].nilai_2 = mhs[j].nilai_2;
                    mhs[i].nilai_3 = mhs[j].nilai_3;
                    strcpy(mhs[i].nama, mhs[j].nama);

                    mhs[j].total_nilai = a;
                    mhs[j].nilai_1 = nilai_1;
                    mhs[j].nilai_2 = nilai_2;
                    mhs[j].nilai_3 = nilai_3;
                    strcpy(mhs[j].nama, nama);
                }
            }
        }
    }
    // Apakah nama sudah sesuai
    for (int i = 1; i < N; i++)
    {
        if ((mhs[i].nilai_1 == mhs[i - 1].nilai_1) && (mhs[i].nilai_3 == mhs[i - 1].nilai_3) && (mhs[i].nilai_2 == mhs[i - 1].nilai_2))
        {
            if (mhs[i].nama[0] > mhs[i - 1].nama[0])
            {
                a = mhs[i].total_nilai;
                strcpy(nama, mhs[i].nama);
                nilai_1 = mhs[i].nilai_1;
                nilai_2 = mhs[i].nilai_2;
                nilai_3 = mhs[i].nilai_3;

                mhs[i].total_nilai = mhs[i - 1].total_nilai;
                mhs[i].nilai_1 = mhs[i - 1].nilai_1;
                mhs[i].nilai_2 = mhs[i - 1].nilai_2;
                mhs[i].nilai_3 = mhs[i - 1].nilai_3;
                strcpy(mhs[i].nama, mhs[i - 1].nama);

                mhs[i - 1].total_nilai = a;
                mhs[i - 1].nilai_1 = nilai_1;
                mhs[i - 1].nilai_2 = nilai_2;
                mhs[i - 1].nilai_3 = nilai_3;
                strcpy(mhs[i - 1].nama, nama);
            }
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    struct Mahasiswa mhs[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%s %d %d %d", mhs[i].nama, &mhs[i].nilai_1, &mhs[i].nilai_2, &mhs[i].nilai_3);
        mhs[i].total_nilai = mhs[i].nilai_1 + mhs[i].nilai_2 + mhs[i].nilai_3;
    }

    sorting(N, mhs);
    for (int i = 0; i < N; i++)
    {
        printf("%s %d %d %d\n", mhs[i].nama, mhs[i].nilai_1, mhs[i].nilai_2, mhs[i].nilai_3);
    }
}
```
