#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char array[21];
    printf("Enter anything of length <=20: ");
    gets(array);
    int i=0;
    int j=0;
    for(i=0; array[i]!='\0'; ++i)
    {
        while(!((array[i]>='a'&&array[i]<='z')||(array[i]>='A'&&array[i]<='Z')||array[i]=='\0'))
        {
            for(j=i; array[j]!='\0'; ++j)
            {
                array[j] = array[j+1];
            }
            array[j]='\0';
        }
    }
    puts(array);
    return 0;
}
