#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z, i, j, m, n;
    printf("Enter a number: ");
    scanf("%d", &x);
    z=x;
    m=x;
    y=0;
    while(x)
    {
        x/=10;
        y++;
    }

    int arr1[y];
    int arr2[y];
    for(i=0; i<y; i++)
    {
        arr1[y-i-1]=z%10;
        z/=10;
    }
    for(i=0; i<y; i++)
    {
     arr2[i]=arr1[i];
    }
    for(i=0; i<y; i++)
    {
        for(j=0; j<y-1; j++)
        {
            arr2[i]=arr1[i]*arr2[i];
        }
    }
    n=0;
    for(i=0; i<y; i++)
    {
        n=n+arr2[i];
    }
    if(m==n)
    {
        printf("Armstrong number");
    }
    else
    {
        printf("Not an Armstrong number");
    }
    return 0;
}
