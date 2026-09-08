#include <stdio.h>
#include <stdlib.h>

int CheckPrime(int n);

int main()
{
    int i, j, x, y, m, n;
    printf("Enter a number: ");
    scanf("%d", &x);
    m=0;
    for(i=0; i+1<x; i++)
    {
        if(CheckPrime(i+1))
        {
            m++;
        }
    }
    int prime[m];
    n=0;
    for(i=0; i+1<x; i++)
    {
        if(CheckPrime(i+1))
        {
            prime[n]=i+1;
            n++;
        }
    }
    for(i=0; i<m; i++)
    {
        for(j=i; j<m; j++)
        {
            y=prime[i]+prime[j];
            if(y==x)
            {
                printf("%d + %d\n", prime[i], prime[j]);
            }
        }
    }



    return 0;
}

int CheckPrime(int n)
{
    int i;
    for(i=2; i<n; i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}
