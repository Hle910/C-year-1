#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, i, y, j, m, n;
    printf("Enter number: ");
    scanf("%d", &x);
    printf("Enter another number: ");
    scanf("%d", &y);
    j=x-y;
    if(j<0)
    {
        j=-j;
    }
    int arr1[x];
    int arr2[j];
    for(i=0; i<x; i++)
    {
        arr1[i]=x-i;
    }
    n=1;
    for(i=0; i<x; i++)
    {
        n=n*arr1[i];
    }
    for(i=0; i<j; i++)
    {
        arr2[i]=j-i;
    }
    m=1;
    for(i=0; i<j; i++)
    {
        m=m*arr2[i];
    }
    printf("%d", n/m);

    return 0;
}
