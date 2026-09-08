#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, i, n, m;
    printf("Enter the number of terms:\n");
    scanf("%d", &x);
    int array[x];
    printf("First %d terms of the Fibonacci numbers are:\n", x);
    m=0;
    n=0;
    for(i=0; i<x; i++)
    {
        array[0]=0;
        array[1]=1;
        if(i>1)
        {
            array[i]=array[i-2]+array[i-1];
        }
        printf("%d\n", array[i]);
    }
    printf("The sum value of the above sequence is:\n");
    for(i=0; i<x; i++)
    {
        n=array[i];
        m=m+n;
    }
    printf("%d", m);
    return 0;
}
