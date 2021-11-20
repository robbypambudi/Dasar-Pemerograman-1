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