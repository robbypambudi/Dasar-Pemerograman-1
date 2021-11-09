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
        else if (i >= N)
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
            Delete(data, angka - 1, n);
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