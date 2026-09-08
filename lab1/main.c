#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, i, j, k, l, m, n, array[10];
    printf("Input a number: ");
    scanf("%d", &x);
    for(i=0; i<sizeof(array)/sizeof(int); i++)
    {
        printf("Enter number %d: ", i+1);
        scanf("%d", &array[i]);
    }
    k=0;
    n=1;
    for(i=0; i<10; i++)
    {
        m=0;
        for(k=1; k<=i; k++)
        {
            if(array[i-k]==array[i])
            {
                m=1;
            }
        }
        if(m)
        {
            continue;
        }
        for(j=i+1; j<10; j++)
        {
            m=0;
            for(k=1; k<=j; k++)
            {
                if(array[j-k]==array[j])
                {
                    m=1;
                }
            }
            if(m)
            {
                continue;
            }
            l=((array[i]*array[i])+(array[j]*array[j]));
            if(l==(x*x))
            {
                printf("(%d, %d)\n", array[i], array[j]);
                n=0;
            }
        }
    }
    if(n)
    {
        printf("There are no such pairs");
    }

    return 0;
}
