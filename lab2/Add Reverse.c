#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z, n, i;
    printf("Enter a number: ");
    scanf("%d", &x);
    y=0;
    n=x;
    while(n>0)
    {
        y=(y*10)+(n%10);
        n=n/10;
    }
    z=x+y;

    printf("Sum %d + %d = %d\n", x, y, z);

    return 0;
}
