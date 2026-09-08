#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, m, n, x, y, tmp;
    printf("Enter size of array: ");
    x=0;
    while(x<=0)
    {
        scanf("%d", &x);
        if(x<=0)
        {
            printf("Cannot enter %d\n", x);
        }
    }
    int array[x];
    printf("Enter elements into array: \n");
    for(i=0; i<x; i++)
    {
        scanf("%d", &array[i]);
    }
    for(i=0;i<x;i++)
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
    if(x>1)
    {
    printf("Second largest element: %d\n", array[x-2]);
    printf("Second smallest element: %d\n", array[1]);
    }
    else
    {
        printf("The only element is %d\n", array[0]);
    }

    return 0;
}
