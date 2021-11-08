#include <stdio.h>
struct Bank
{
    int id;
    char nama[25];
    long int saldo;
};

int main()
{

    int p;
    scanf("%d", &p);
    struct Bank bank[p];
    for (int i = 0; i < p; i++)
    {
        scanf("%d %[^\n]", &bank[i].id, bank[i].nama);
        bank[i].saldo = 100;
    }
    int j, id;
    long int saldo_baru;
    while (scanf("%d", &j) != 0)
    {
        if (j == 0)
        {
            break;
        }
        if (j == 1)
        {
            scanf("%d %ld", &id, &saldo_baru);
            for (int i = 0; i < p; i++)
            {
                if (id == bank[i].id)
                {
                    bank[i].saldo += saldo_baru;
                    if (bank[i].saldo > 1000)
                    {
                        bank[i].saldo -= 20;
                    }
                }
            }
        }

        if (j == 2)
        {
            scanf("%d %ld", &id, &saldo_baru);
            for (int i = 0; i < p; i++)
            {
                if (id == bank[i].id)
                {
                    if (bank[i].saldo < saldo_baru)
                    {
                        bank[i].saldo = 0;
                    }
                    else
                    {
                        bank[i].saldo -= saldo_baru;
                    }
                }
            }
        }
    }
    for (int i = 0; i < p; i++)
    {
        printf("Akun %d\n", i + 1);
        printf("%d\n", bank[i].id);
        printf("%s\n", bank[i].nama);
        printf("%ld\n", bank[i].saldo);
    }
    return 0;
}
