#include <stdio.h>

int main (){
    int x, y;
    int s;
    scanf("%d %d", &x, &y);
    int A[y][x];

    for (int i = 0; i <y; i++){
        for (int j=0; j<x; j++){
            scanf("%d", &A[i][j]);
        }
    }
    scanf("%d", &s);
    int terbeser = 0;
    int hasil = 0;
    if (s != 0 && x != 0 && y != 0){
        for (int i = 0; i <= y -s; i++){
            for (int j = 0; j <= x - s; j++){
                hasil = 0;
                for (int  a = i; a < i + s; a++){
                    for (int b = j; b < j + s; b++){
                        hasil += A[a][b];
                        // printf("%d %d\n", a, b);
                    }
                }
            if (hasil > terbeser){
                terbeser = hasil;
                }
            }
        }
        printf("%d\n", terbeser);
    }
}