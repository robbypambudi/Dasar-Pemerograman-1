/*
At Kenjeran Crossroad there is a traffic light with below specifications:

Red light will be turned on for 20s

Yellow light for 5s, after red light

Green light for 60s, after yellow light

You are at the street, with M cars to your front and N cars behind you. To fill time, you create a program that can tell you whether or not you're able to pass the traffic light and how many cars are left at the road after T seconds. For every 5s in green light, one car is able to pass the traffic light.

Input Format

There are three integers M, N, and T, as explained in the problem statement.

Constraints

1 ≤ M ≤ 100 1 ≤ N ≤ 100 1 ≤ T ≤ 1000

Output Format

Display "YES!" if you are able to pass the traffic light, "NO!" otherwise.

Display the number of cars left behind on the same line. If all cars pass the traffic light, display 0 instead.

Sample Input 0

45 12 200
Sample Output 0

NO! 33
Sample Input 1

45 48 630
Sample Output 1

YES! 8
Sample Input 2

12 12 200
Sample Output 2

YES! 0
*/
#include <stdio.h>
#include <math.h>

int main()
{

    int M, N, T, Mobil, A, B, Mobil_Lewat;
    scanf("%d %d %d", &M, &N, &T);

    Mobil = M + N + 1;

    if (T > 85)
    {
        A = floor(T / 85);
        B = T % 85;
        A = A * 12;

        if (B > 25)
        {
            B -= 25;
            B = floor(B / 5);
            Mobil_Lewat = A + B;
            printf(Mobil_Lewat > M ? "YES! " : "NO! ");

            if (Mobil - Mobil_Lewat <= 0)
                printf("0\n");

            else
                printf("%d\n", Mobil - Mobil_Lewat);
        }
        else if (B <= 25)
        {
            printf(A > M ? "YES! " : "NO! ");

            if (Mobil - A <= 0)
                printf("0\n");

            else
                printf("%d\n", Mobil - A);
        }
    }

    else if (T <= 85 && T > 25)
    {
        A = floor((T - 25) / 5);
        printf(A > M ? "YES! " : "NO! ");

        if (Mobil - A <= 0)
            printf("0\n");

        else
            printf("%d\n", Mobil - A);
    }

    else if (T <= 25)
        printf("NO! %d\n", Mobil);

    return 0;
}
