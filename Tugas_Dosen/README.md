# Tugas Cuy :v

## Tugas 1

### Tgl Tugas : 02 November 2021

### Deadline : 09 November 2021

### Deskripsi Tugas :

**Buatlah Program dengan fungsi utama sebagai berikut :**
**Input:** Nama Depan, Nama Belakangm Kelahiran ( Tanggal, Bulan dan Tahun)

-   Bulan ditulis dengan string
    **Proses**
-   Validasi Inputan (+)
-   Menggabungkan nama depan dan nama belakang menjadi nama lengkap, dipisahkan dengan spasi
-   Mengkonversi setiap huruf pada nama lengkap, setiap huruf di urutan ganjil adalah huruf besar sedangkan huruf di urutan genap adalah huruf kecil
-   Menghitung Usia dalam hari bulan dan tahun
-   Menampilkan nama lengkap hasil konversi dan hasil perhitungan usia di layar

## Code

```
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Global Variabel
int DAY = 2,
    MONTH = 11,
    YEAR = 2021;
char list_bulan[][15] = {"januari", "februari", "maret", "april", "mei", "juni", "juli", "augustus", "september", "november",
                         "oktober", "desember"};
int list_day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Bulan Check
void BulanBerapa(int *bulan_num, char bulan[])
{
    for (int i = 0; i < strlen(bulan); i++) // Menjadikan lowercase bulan agar mudah dicek
    {
        if (bulan[i] < 'a')
            bulan[i] += 32;
    }
    for (int i = 0; i <= 12; i++) // Cek Bulan
    {
        if (strcmp(bulan, list_bulan[i]) == 0)
        {
            *bulan_num = i + 1;
            return;
        }
        *bulan_num = -1;
    }
    return;
}

// Validasi Data
bool validation(char nama_depan[], char nama_belakang[], int tanggal, char bulan[], int tahun, int *bulan_num)
{
    printf("\n");
    int temp;
    // Cek Nama Depanya
    temp = strlen(nama_depan);
    for (int i = 0; i < temp; i++)
    {
        if (!((nama_depan[i] >= 'A' && nama_depan[i] <= 'Z') || (nama_depan[i] >= 'a' && nama_depan[i] <= 'z')))
        {
            printf("[*] Nama Depan Tidak Valid\n");
            return false;
        }
    }
    // Cek Nama Belakang
    temp = strlen(nama_belakang);
    for (int i = 0; i < temp; i++)
    {
        if (!((nama_belakang[i] >= 'A' && nama_belakang[i] <= 'Z') || (nama_belakang[i] >= 'a' && nama_belakang[i] <= 'z')))
        {
            printf("[*] Nama Belakang Tidak Valid\n");
            return false;
        }
    }
    // Cek Tanggal
    if (!(tanggal >= 1 && tanggal <= 31))
    {
        printf("[*] Tanggal Tidak Valid\n");
        return false;
    }
    // Cek Bulan
    temp = strlen(bulan);
    for (int i = 0; i < temp; i++)
    {
        if (!((bulan[i] >= 'A' && bulan[i] <= 'Z') || (bulan[i] >= 'a' && bulan[i] <= 'z')))
        {
            printf("[*] Bulan Tidak Valid\n");
            return false;
        }
    }
    // Cek Anggka Bulan
    BulanBerapa(bulan_num, bulan);
    if (*bulan_num == -1)
    {
        printf("[*] Tidak ada bulan : %s", bulan);
        return false;
    }
    // Cek Tahun
    if (tahun > 2021)
    {
        printf("[*] Tahun Tidak Valid\n");
        return false;
    }

    // Data Valid
    return true;
}

void combinestring(char nama_depan[], char nama_belakang[], char nama_dep_bel[])
{
    strcat(nama_dep_bel, nama_depan);    // Membuat var nama_dep_bel = nama_depan
    strcat(nama_dep_bel, " ");           // Menambahkan Spasi
    strcat(nama_dep_bel, nama_belakang); // Mengabungkan Kedua String
    return;
}

void Low_Upper(char nama_dep_bel[])
{
    for (int i = 0; i <= strlen(nama_dep_bel); i++)
    {
        if (nama_dep_bel[i] == ' ')
            continue;

        else if ((i) % 2 == 0)
        {
            if (nama_dep_bel[i] > 'Z')
                nama_dep_bel[i] -= 32;
        }
        else
        {
            if (nama_dep_bel[i] <= 'Z')
                nama_dep_bel[i] += 32;
        }
    }
    return;
}

void HappyBirthday(int tanggal, int bulan, int tahun)
{
    int jml_tahun, jml_bulan, jml_hari;

    if (tanggal > DAY)
    {
        DAY = DAY + list_day[bulan - 1];
        MONTH = MONTH - 1;
    }
    if (bulan > MONTH)
    {
        YEAR = YEAR - 1;
        MONTH = MONTH + 12;
    }
    jml_hari = DAY - tanggal;
    jml_bulan = MONTH - bulan;
    jml_tahun = YEAR - tahun;

    printf("[*] Usia \t\t: %d Tahun %d Bulan %d Hari\n", jml_tahun, jml_bulan, jml_hari);
    return;
}

int main()
{
    char nama_depan[30],
        nama_belakang[30],
        bulan[20],
        nama_dep_bel[60];

    int tanggal, tahun;
    int bulan_num;

    printf("Masukan Nama Depan Anda \t: ");
    scanf("%s", nama_depan);
    printf("Masukan Nama Belakang Anda \t: ");
    scanf("%s", nama_belakang);
    printf("Masukan Tanggal Lahir Anda *Tanggal(Angka) *Bulan(Text) *Tahun(angka) : ");
    scanf("%d%s%d", &tanggal, bulan, &tahun);

    // Validasi Data
    if (!validation(nama_depan, nama_belakang, tanggal, bulan, tahun, &bulan_num))
        return 0;

    // Cetak Hasil
    combinestring(nama_depan, nama_belakang, nama_dep_bel);
    printf("[*] Input is Valid\n");
    printf("[*] Nama \t\t: %s\n", nama_dep_bel);
    Low_Upper(nama_dep_bel);
    printf("[*] Nama Konversi \t: %s\n", nama_dep_bel);
    HappyBirthday(tanggal, bulan_num, tahun);
    return 0;
}
```

# Thank You
