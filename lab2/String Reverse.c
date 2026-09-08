#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j, size;
    char tmp;
    char str[50];
    fgets(str, 50, stdin);
    char *token=strtok(str, "");
    size=strlen(token)-1;
    for(i=size; i>=0; i--)
    {
        printf("%c", token[i]);
    }
    return 0;
}
