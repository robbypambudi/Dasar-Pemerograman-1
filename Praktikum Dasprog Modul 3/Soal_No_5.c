#include <stdio.h>
#include <stdbool.h>

int x, y, ai, aj, bi, bj, min = 999999;
char bambang[20][20];
bool printed = false;

void minimofroute(int P, int O, int jml_perulangan)
{
    if (bambang[P][O] == '#')
        return;
    if (P == bi && O == bj)
    {
        min = jml_perulangan < min ? jml_perulangan : min;
        return;
    }
    // printf("%d %d", P, O);
    bambang[P][O] = '#';
    minimofroute(P + 1, O, jml_perulangan + 1);
    minimofroute(P - 1, O, jml_perulangan + 1); // // // // // //
    minimofroute(P, O + 1, jml_perulangan + 1);
    minimofroute(P, O - 1, jml_perulangan + 1);
    bambang[P][O] = '.';

    return;
}

void cetakroute(int P, int O, int jml_perulangan)
{
    if (printed)
    {
        return;
    }
    if (P == bi && O == bj)
    {
        if (min != jml_perulangan)
            return;
        printed = true;
        return;
    }

    if (bambang[P][O] == '#')
        return;
    if (bambang[P][O] == 'x')
        return;

    bambang[P][O] = 'x';
    cetakroute(P + 1, O, jml_perulangan + 1);
    cetakroute(P - 1, O, jml_perulangan + 1);
    cetakroute(P, O + 1, jml_perulangan + 1);
    cetakroute(P, O - 1, jml_perulangan + 1); // 21 // 22 retrun selesai

    if (printed)
        return;
    bambang[P][O] = '.';

    return;
}

void cetakroute2()
{

    for (int i = 1; i <= y; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (i == ai && j == aj)
            {
                printf("A");
            }
            else if (i == bi && j == bj)
            {
                printf("B");
            }
            else
            {
                printf("%c", bambang[i][j]);
            }
        }
        printed = true;
        printf("\n");
    }
    return;
}

int main()
{

    scanf("%d %d", &x, &y);
    for (int i = 0; i <= x + 1; i++)
    {
        for (int j = 0; j <= y + 1; j++)
        {
            bambang[i][j] = '#';
        }
    }
    for (int i = 1; i <= y; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            scanf(" %c", &bambang[i][j]);
            if (bambang[i][j] == 'A')
            {
                ai = i;
                aj = j;
            }
            else if (bambang[i][j] == 'B')
            {
                bi = i;
                bj = j;
            }
        }
    }
    minimofroute(ai, aj, 0);
    cetakroute(ai, aj, 0);
    cetakroute2();

    return 0;
}