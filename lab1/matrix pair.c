#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r, c, i, j, n, m;
    printf("Enter number of rows: ");
    scanf("%d", &r);
    printf("Enter number of columns: ");
    scanf("%d", &c);

    int arr1[r][c];
    int arr2[r][c];
    int arr3[r][c];

    printf("Enter value for matrix 1\n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("Enter value for matrix 2\n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }
    printf("Sum of 2 matrices is:\n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("%d ", arr1[i][j]+arr2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
