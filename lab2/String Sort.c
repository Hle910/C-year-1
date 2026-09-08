#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j;
    char tmp[1][5];
    char array[5][5];
    printf("Enter 4 letters in any order: \n");
    for(i=0; i<5; i++)
    {
        scanf("%s", array[i]);
    }
    printf("Sorted strings: \n");
    for(i=0; i<5; i++)
    {
        for(j=0; j<5-i; j++)
        {
            if(strcmp(array[j], array[j+1])>0)
            {
                strcpy(tmp, array[j]);
                strcpy(array[j], array[j+1]);
                strcpy(array[j+1], tmp);
            }
        }
    }
    for(i=0; i<5; i++)
    {
        printf("%s\n", array[i]);
    }

    return 0;
}
