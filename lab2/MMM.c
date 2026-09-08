#include <stdio.h>
#include <stdlib.h>

int median(int array[]);
int mode(int array[]);
int mean(int array[]);

int main()
{
    int x, i;
    int arrA[7];
    int arrB[7];

    i=0;
    printf("Enter values for how many hours you play each day of the week: \n");
    while(i!=7)
    {
        scanf("%d", &x);
        if(x>24)
        {
            printf("Wrong value\n");
        }
        else
        {
            arrA[i]=x;
            i++;
        }
    }
    i=0;
    printf("Enter values for how many hours you study each day of the week: \n");
    while(i!=7)
    {
        scanf("%d", &x);
        if(x>24)
        {
            printf("Wrong value\n");
        }
        else
        {
            arrB[i]=x;
            i++;
        }
    }

    printf("Mean of A: %d\n", mean(arrA));
    printf("Median of A: %d\n", median(arrA));
    printf("Mode of A: %d\n", mode(arrA));
    printf("Mean of B: %d\n", mean(arrB));
    printf("Median of B: %d\n", median(arrB));
    printf("Mode of B: %d\n", mode(arrB));

    if((mean(arrA)>mean(arrB))&&(median(arrA)>median(arrB))&&(mode(arrA)>mode(arrB)))
    {
        printf("You're playing more video games than you have spent studying.");
    }
    if((mean(arrA)<mean(arrB))&&(median(arrA)<median(arrB))&&(mode(arrA)<mode(arrB)))
    {
        printf("Good you're spending considerable time studying.");
    }
    if((mean(arrA)==mean(arrB))&&(median(arrA)==median(arrB))&&(mode(arrA)==mode(arrB)))
    {
        printf("You are well balanced.");
    }
    else
    {
        printf("Sorry, can't come to an outcome.");
    }

    return 0;
}

int mean(int array[])
{
    int a=0;
    int i;
    for(i=0; i<7; i++)
    {
        a=a+array[i];
    }
    a=a/7;
    return a;
}

int mode(int array[])
{
    int i, j, m, n, x;
    m=0;
    for(i=0; i<7; i++)
    {
        n=0;
        for(j=0; j<7; j++)
        {
            if(array[j]==array[i])
            {
                ++n;
            }
        }
        if(n>m)
        {
            m=n;
            x=array[i];
        }
    }
    return x;
}

int median(int array[])
{
    int i, j, tmp;
    for(i=0;i<7;i++)
    {
        for(j=0;j<7-i;j++)
        {
            if(array[j]>array[j+1])
            {
                tmp=array[j];
                array[j]=array[j+1];
                array[j+1]=tmp;
            }
        }
    }
    return array[3];
}
