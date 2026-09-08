#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, tmp, arrA[18], arrB[5];

    printf("Input numbers in ascending order for first array: \n");
    for(i=0; i<13; i++)
    {
        scanf("%d", &arrA[i]);
    }
    printf("Input numbers in ascending order for second array: \n");
    for(i=0; i<5; i++)
    {
        scanf("%d", &arrB[i]);
    }
    for(i=0; i<5; i++)
    {
        arrA[13+i]=arrB[i];
    }

    for(i=0;i<17;i++)
    {
        for(j=0;j<17-i;j++)
        {
            if(arrA[j]>arrA[j+1])
            {
                tmp=arrA[j];
                arrA[j]=arrA[j+1];
                arrA[j+1]=tmp;
            }
        }
    }
    printf("Finally after merging A and B, A becomes: \n");
    for(i=0; i<18; i++)
    {
        printf("%d\n", arrA[i]);
    }

    return 0;
}
