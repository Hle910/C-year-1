#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, tmp, array[10];
    printf("Enter numbers:\n");
    for(i=0;i<10;i++)
    {
        printf("Number %d: ", i+1);
        scanf("%d", &array[i]);
    }
    for(i=0;i<10;i++)
    {
        for(j=0;j<10-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                tmp=array[j];
                array[j]=array[j+1];
                array[j+1]=tmp;
            }
        }
    }
    printf("Sorted list: {");
    for(i=0;i<10;i++)
    {
        printf("%d", array[i]);
        if(i+1<10)
        {
            printf(", ");
        }
    }
    printf("}");

    return 0;
}
