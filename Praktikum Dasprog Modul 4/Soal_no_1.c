#include <stdio.h>

void swap(float *p, float *q)
{
    float t;
    t = *p;
    *p = *q;
    *q = t;
}

void median(float hasil_median[], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            swap(&hasil_median[j], &hasil_median[j]);
        }
    }
}

void mean(float hasil_mean_arr[], int n, float *hasil_mean)
{
    float hasil = 0;
    for (int i = 0; i < n; i++)
    {
        hasil += hasil_mean_arr[i];
    }
    *hasil_mean = hasil / n;
}

void modus(float hasil_modus_arr[], int n, float *hasil)
{
    int max = 0, maxcounting = 0;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count = 0;

        for (int j = 0; j < n; ++j)
        {
            if (hasil_modus_arr[j] == hasil_modus_arr[i])
                ++count;
        }
        if (count > maxcounting)
        {
            maxcounting = count;
            max = hasil_modus_arr[i];
        }
    }
    if (count == 0)
    {
        *hasil = hasil_modus_arr[0];
    }
    *hasil = max;
}

int main()
{
    int T,
        N;

    float hasil_median;
    float hasil_mean;
    float hasil_modus;

    scanf("%d", &T);
    if (T < 1)
    {
        return 0;
    }
    for (int a = 0; a < T; a++)
    {
        scanf("%d", &N);
        if (N < 1)
        {
            return 0;
        }
        float Ni[N];
        for (int i = 0; i < N; i++)
        {
            scanf("%f", &Ni[i]);
            if (Ni[i] < 1)
            {
                return 0;
            }
        }

        // Menentukan Median
        median(Ni, N);
        if (N % 2 == 1)
        {

            hasil_median = Ni[(N + 1) / 2 - 1];
        }
        else
        {

            hasil_median = (Ni[(N + 1) / 2 - 1] + Ni[(N + 1) / 2]) / 2;
        }

        mean(Ni, N, &hasil_mean);
        modus(Ni, N, &hasil_modus);

        printf("%.2f ", hasil_median);
        printf("%.2f ", hasil_mean);
        printf("%.0f", hasil_modus);
        printf("\n");
    }
}