/*
Kiki sedang berada di casino untuk bermain judi kartu, sekarang di sedang memegang N kartu yang tidak urut ia ingin mengurutkan kartu dari angka terkecil hingga terbesar. Ia akan melakukan pertukaran posisi 2 kartu di tangannya agar kartunya urut. Tentukan berapa minimal pertukaran yang dapat dilakukan.

note : bisa aja ada kartu yang angkanya sama..

Input Format

Baris pertama berisi N

Baris berikutnya berisi kartu di tangan Kiki belum urut

input berhenti jika N = 0

Constraints

N < 1000

Output Format

baris berisi "minimal pertukaran : x "

Sample Input 0

3
1 2 3
3
2 3 1
0
Sample Output 0

minimal pertukaran : 0
minimal pertukaran : 2
*/

#include <stdio.h>

int Urut(int arr[], int n, int *sum);

int main()
{
    int Nilai, Data[1100];
    while (scanf("%d", &Nilai) != EOF)
    {
        int Result = 0;
        if (Nilai == 0)
            return 0;

        for (int i = 0; i < Nilai; i++)
            scanf("%d", &Data[i]);

        Urut(Data, Nilai, &Result);
        printf("minimal pertukaran : %d\n", Result);
    }
    return 0;
}
int Urut(int arr[], int n, int *sum)
{
    int x, y, tmp;
    for (x = 0; x < n; x++)
    {
        for (y = 0; y < n - x - 1; y++)
        {
            if (arr[y] > arr[y + 1])
            {
                tmp = arr[y];
                arr[y] = arr[y + 1];
                arr[y + 1] = tmp;
                *sum += 1;
            }
        }
    }
    return *sum;
}
