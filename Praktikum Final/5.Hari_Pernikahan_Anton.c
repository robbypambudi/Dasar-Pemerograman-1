#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    double P, H;
    scanf("%lf %lf", &H, &P);

    double result = H - (3.0 * P * P) / (16.0 * H);

    if (result > 0)
    {
        printf("Jembatan dapat dibangun pada ketinggian %.10lf", result);
    }
    else
    {
        printf("Impossible ton :(");
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
