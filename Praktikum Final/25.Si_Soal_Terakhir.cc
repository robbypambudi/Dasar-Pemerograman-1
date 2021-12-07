/*
Waktu kecil dulu, mereka menertawakan

Mereka panggilku gajah, ku marah

Kini baru ku tahu, puji didalam olokan

Mereka ingatku marah

Jabat tanganku panggil aku gajah

Gara gara tulus, SYZi sekarang menjadi pengusaha gajah binser. SYZi memiliki papan catur berukuran n x n. Di papan akan ditempatkan beberapa gajah binser. Sayangnya gajah-gajah tersebut menjadi gila dan menyerang semua kotak pada diagonal yang sama. SYZi bertanya tanya berapa banyak kotak yang diserang oleh gajah.

image

clue : Gajah Binser

Input Format

Baris pertama berisi dua bilangan bulat n dan m yang mewakili ukuran papan dan jumlah gajah. Baris m berikutnya sepasang bilangan bulat ai dan bi mewakili posisi baris dan kolom tempat gajah nomor i berada.

Constraints

1 <= m,n <= 10^6 1 <= a,b <= 10^6

Output Format

Cetak jumlah kotak yang diserang oleh para gajah.

Sample Input 0

3 1
2 2
Sample Output 0

5
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

#define LL long long int

LL n, m, r, c, a, b, kiri, kanan, ans;
LL a1[1000000], a2[1000000], b1[1000000], b2[1000000];

LL max(LL a, LL b){
    return( a > b ? a : b);
}

LL min(LL a, LL b){
    return( a < b ? a : b);
}

int compare(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

LL bs_upper_bound(LL a[], LL n, LL x)
{
    LL l = 0;
    LL h = n;
    while (l < h)
    {
        LL mid = (l + h) / 2;
        if (x >= a[mid]) l = mid + 1;
        else h = mid;
    }
    return l;
}

LL bs_lower_bound(LL a[], LL n, LL x) {
    LL l = 0;
    LL h = n;
    while (l < h)
    {
        LL mid = (l + h) / 2;
        if (x <= a[mid]) h = mid;
        else l = mid + 1;
    }
    return l;
}

LL removeDuplicates(LL arr[], LL n)
{
    if (n==0 || n==1) return n;
    LL temp[n];
    LL j = 0;
    for (LL i=0; i<n-1; i++) if (arr[i] != arr[i+1]) temp[j++] = arr[i];
    temp[j++] = arr[n-1];
    for (LL i=0; i<j; i++) arr[i] = temp[i];
    return j;
}

int main(){ 
    scanf("%lld %lld", &n, &m);
    LL _a1 = 0, _a2 = 0, _b1 = 0, _b2 = 0;
    for(int i=0; i<m; ++i)
    {
        scanf("%lld %lld", &r, &c);
        a = r + c;
        b = r - c;

        if(a & 1){
            a1[_a1] = a;
            ++_a1;
        }
        else{
            a2[_a2] = a;
            ++_a2;
        }

        if(b & 1){
            b1[_b1] = b;
            ++_b1;
        }
        else{
            b2[_b2] = b;
            ++_b2;
        }
    }
    qsort(a1, _a1, sizeof(LL), compare);
    qsort(a2, _a2, sizeof(LL), compare);
    qsort(b1, _b1, sizeof(LL), compare);
    qsort(b2, _b2, sizeof(LL), compare);
    _a1 = removeDuplicates(a1, _a1);
    _a2 = removeDuplicates(a2, _a2);
    _b1 = removeDuplicates(b1, _b1);
    _b2 = removeDuplicates(b2, _b2);
    for(int i=0; i<_a1; ++i){
        int val = a1[i];
        if(val <= n+1) ans += (val - 1);
        else ans += (2 * n + 1 - val);
        kiri = bs_lower_bound(b1, _b1, max(2 - val, val - 2 * n));
        kanan = bs_upper_bound(b1, _b1, min(2 * n - val, val - 2));
        ans -= (kanan - kiri);
    }
    for(int i=0; i<_a2; ++i)
    {
        int val = a2[i];
        if(val <= n+1) ans += (val - 1);
        else ans += (2 * n + 1 - val);
        kiri = bs_lower_bound(b2, _b2, max(2 - val, val - 2 * n));
        kanan = bs_upper_bound(b2, _b2, min(2 * n - val, val - 2));
        ans -= (kanan - kiri);
    }
    for(int i=0; i<_b1; ++i) ans += (n - abs(b1[i]));
    for(int i=0; i<_b2; ++i) ans += (n - abs(b2[i]));
    printf("%lld\n", ans);
}