/*
Kini Taki menjadi ketua pelaksana pada kegiatan lomba di sekolahnya. Untuk membantu pembuat papan skor, urutkanlah data skor peserta sesuai dengan urutan sebagai berikut: total skor, skor cabang perlombaan A, B, C, nama tim.

Input Format

Sebuah baris yang berisi bilangan N yang menyatakan banyak tim. diikuti dengan N baris yang berisi string nama dan 3 bilangan bulat yang menyatakan skor tiap-tiap cabang perlombaan A, B, C. Nama tim dijamin tidak memiliki spasi.

Constraints

2 ≤ N ≤ 100

5 ≤ |nama tim| ≤ 31

0 ≤ A, B, C ≤ 20.000

Output Format

N baris yang berisi string nama tim, skor cabang perlombaan A, B, C dan total skor.

Sample Input 0

3
bangJago 900 1000 900
doaIbu 1000 1050 1000
semogaJuara 950 1100 800
Sample Output 0

doaIbu 1000 1050 1000 3050
semogaJuara 950 1100 800 2850
bangJago 900 1000 900 2800
Sample Input 1

4
timSatu 400 300 400
timDua 400 400 300
timTiga 300 400 400
timEmpat 400 400 400
Sample Output 1

timEmpat 400 400 400 1200
timDua 400 400 300 1100
timSatu 400 300 400 1100
timTiga 300 400 400 1100
*/
#include <stdio.h>
#include <string.h>

struct TIM
{
    char nama[50];
    int Nilai_1, Nilai_2, Nilai_3;
    long int total_nilai;
};

int main()
{
    int N;
    scanf("%d", &N);
    struct TIM data[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%s %d %d %d", data[i].nama, &data[i].Nilai_1, &data[i].Nilai_2, &data[i].Nilai_3);
        data[i].total_nilai = data[i].Nilai_1 + data[i].Nilai_2 + data[i].Nilai_3;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            char temp[50];
            int nilai_1, nilai_2, nilai_3, total_nilai;

            if (data[i].total_nilai < data[j].total_nilai)
            {
                strcpy(temp, data[i].nama);
                nilai_1 = data[i].Nilai_1;
                nilai_2 = data[i].Nilai_2;
                nilai_3 = data[i].Nilai_3;
                total_nilai = data[i].total_nilai;

                strcpy(data[i].nama, data[j].nama);
                data[i].Nilai_1 = data[j].Nilai_1;
                data[i].Nilai_2 = data[j].Nilai_2;
                data[i].Nilai_3 = data[j].Nilai_3;
                data[i].total_nilai = data[j].total_nilai;

                strcpy(data[j].nama, temp);
                data[j].Nilai_1 = nilai_1;
                data[j].Nilai_2 = nilai_2;
                data[j].Nilai_3 = nilai_3;
                data[j].total_nilai = total_nilai;
            }

            if (data[i].total_nilai == data[j].total_nilai)
            {
                int nilai_1, nilai_2, nilai_3, total_nilai;

                if (data[i].nama[0] > data[0].nama[0])
                {
                    strcpy(temp, data[i].nama);
                    nilai_1 = data[i].Nilai_1;
                    nilai_2 = data[i].Nilai_2;
                    nilai_3 = data[i].Nilai_3;
                    total_nilai = data[i].total_nilai;

                    strcpy(data[i].nama, data[j].nama);
                    data[i].Nilai_1 = data[j].Nilai_1;
                    data[i].Nilai_2 = data[j].Nilai_2;
                    data[i].Nilai_3 = data[j].Nilai_3;
                    data[i].total_nilai = data[j].total_nilai;

                    strcpy(data[j].nama, temp);
                    data[j].Nilai_1 = nilai_1;
                    data[j].Nilai_2 = nilai_2;
                    data[j].Nilai_3 = nilai_3;
                    data[j].total_nilai = total_nilai;
                }
                if (data[i].nama[0] == data[j].nama[0] && data[i].nama[1] > data[j].nama[1])
                {
                    strcpy(temp, data[i].nama);
                    nilai_1 = data[i].Nilai_1;
                    nilai_2 = data[i].Nilai_2;
                    nilai_3 = data[i].Nilai_3;
                    total_nilai = data[i].total_nilai;

                    strcpy(data[i].nama, data[j].nama);
                    data[i].Nilai_1 = data[j].Nilai_1;
                    data[i].Nilai_2 = data[j].Nilai_2;
                    data[i].Nilai_3 = data[j].Nilai_3;
                    data[i].total_nilai = data[j].total_nilai;

                    strcpy(data[j].nama, temp);
                    data[j].Nilai_1 = nilai_1;
                    data[j].Nilai_2 = nilai_2;
                    data[j].Nilai_3 = nilai_3;
                    data[j].total_nilai = total_nilai;
                }

                if (data[i].nama[0] == data[j].nama[0] && data[i].nama[1] == data[j].nama[1] && data[i].nama[2] > data[j].nama[2])
                {
                    strcpy(temp, data[i].nama);
                    nilai_1 = data[i].Nilai_1;
                    nilai_2 = data[i].Nilai_2;
                    nilai_3 = data[i].Nilai_3;
                    total_nilai = data[i].total_nilai;

                    strcpy(data[i].nama, data[j].nama);
                    data[i].Nilai_1 = data[j].Nilai_1;
                    data[i].Nilai_2 = data[j].Nilai_2;
                    data[i].Nilai_3 = data[j].Nilai_3;
                    data[i].total_nilai = data[j].total_nilai;

                    strcpy(data[j].nama, temp);
                    data[j].Nilai_1 = nilai_1;
                    data[j].Nilai_2 = nilai_2;
                    data[j].Nilai_3 = nilai_3;
                    data[j].total_nilai = total_nilai;
                }

                if (data[i].nama[0] == data[j].nama[0] && data[i].nama[1] == data[j].nama[1] && data[i].nama[2] == data[j].nama[2] && data[i].nama[3] > data[j].nama[3])
                {
                    strcpy(temp, data[i].nama);
                    nilai_1 = data[i].Nilai_1;
                    nilai_2 = data[i].Nilai_2;
                    nilai_3 = data[i].Nilai_3;
                    total_nilai = data[i].total_nilai;

                    strcpy(data[i].nama, data[j].nama);
                    data[i].Nilai_1 = data[j].Nilai_1;
                    data[i].Nilai_2 = data[j].Nilai_2;
                    data[i].Nilai_3 = data[j].Nilai_3;
                    data[i].total_nilai = data[j].total_nilai;

                    strcpy(data[j].nama, temp);
                    data[j].Nilai_1 = nilai_1;
                    data[j].Nilai_2 = nilai_2;
                    data[j].Nilai_3 = nilai_3;
                    data[j].total_nilai = total_nilai;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%s %d %d %d %ld\n", data[i].nama, data[i].Nilai_1, data[i].Nilai_2, data[i].Nilai_3, data[i].total_nilai);
    }
}