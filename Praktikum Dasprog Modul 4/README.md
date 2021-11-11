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

## Soal No 6

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
