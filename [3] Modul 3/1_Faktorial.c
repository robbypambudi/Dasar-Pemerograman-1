// Buatlah program yang mengimplementasikan fungsi rekursif untuk menentukan nilai dari N! (N faktorial).

#include <stdio.h>
 
int faktorial(int x)
{
    if (x == 0) return 1;                   // Jika x = 0 return 1; atau base case

    return(x * faktorial(x -1));            // Jika x = 3 maka akan terbentuk seperti return (3 * 2 * 1)
}
 
int main()
{
    int x; 
    scanf("%d", &x);

    printf("%d\n", faktorial(x));

    return 0;
}
