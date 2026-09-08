#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, x, y, m, n, t, p;
    printf("Enter size of array: ");
    scanf("%d", &x);
    int array[x];
    printf("Enter elements into array: \n");
    for(i=0; i<x; i++)
    {
        scanf("%d", &array[i]);
    }
    m=0;
    n=0;
    for(i=0; i<x; i++)
    {
        y=array[i];
        if(y%2==0)
        {
            m++;
        }
        else
        {
            n++;
        }
    }
    if(m>0)
    {
        int even[m];
        t=0;
        for(i=0; i<m; i++)
        {
            y=array[i];
            if(y%2==0)
            {
                even[t]=y;
                t++;
            }
        }
        printf("Even integers are:\n");
        for(i=0; i<m; i++)
            {
                printf("%d\n", even[i]);
            }
    }
    else
    {
        printf("There are no even numbers.\n");
    }
    if(n>0)
    {
        int odd[n];
        p=0;
        for(i=0; i<n; i++)
        {
            y=array[i];
            if(y%2!=0)
            {
                odd[p]=y;
            }
        }
        printf("Odd integers are:\n");
        for(i=0; i<n; i++)
            {
                printf("%d\n", odd[i]);
            }
    }
    else
    {
        printf("There are no odd numbers.\n");
    }

    return 0;
}
