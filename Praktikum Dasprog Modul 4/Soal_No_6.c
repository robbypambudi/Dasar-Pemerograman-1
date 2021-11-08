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