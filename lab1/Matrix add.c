#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, r, c, i, j;
    printf("Number of rows: ");
    scanf("%d", &r);
    printf("Number of columns: ");
    scanf("%d", &c);
    int arr1[r][c];
    int arr2[r][c];

    printf("Enter Array 1\n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter Array 2\n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }
    x=1;

    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(!arr1[i][j]==arr2[i][c-j-1])
            {
                x=0;
                break;
            }
        }
    }
    if(x==1)
    {
        printf("Both are mirror matrices of each other");
    }
    else
    {
        printf("Both are not mirror matrices of each other");
    }

    return 0;
}
