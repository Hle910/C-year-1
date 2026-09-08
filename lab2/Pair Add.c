#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, i, j, tmp, arr[20];
    printf("Enter target value: ");
    scanf("%d", &x);
    printf("Enter array values: \n");
    for(i=0; i<20; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i=0;i<19;i++)
    {
        for(j=0;j<19-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
    y=1;
    for(i=0; i<19; i++)
    {
        if(i>0)
        {
            if(arr[i-1]==arr[i+1])
            {
                continue;
            }
        }
        if(arr[i]+arr[i+1]==x)
        {
            printf("(%d, %d)\n", arr[i], arr[i+1]);
            y=0;
        }
    }
    if(y)
    {
        printf("No pairs of integers in the given array can be summed to the target value.\n");
    }



    return 0;
}
