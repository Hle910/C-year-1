#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, i, j, tmp;
    printf("Enter size of array\n");
    scanf("%d", &x);
    int array[x+1];
    printf("Enter numbers:\n");
    for(i=0;i<x;i++)
    {
        printf("Number %d: ", i+1);
        scanf("%d", &array[i]);
    }
    printf("Enter number to be inserted: ");
    scanf("%d", &array[x]);
    for(i=0;i<x+1;i++)
    {
        for(j=0;j<x-i;j++)
        {
            if(array[j]>array[j+1])
            {
                tmp=array[j];
                array[j]=array[j+1];
                array[j+1]=tmp;
            }
        }
    }
    for(i=0;i<x+1;i++)
    {
        printf("%d\n", array[i]);

    }

    return 0;
}
