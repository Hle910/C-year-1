#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j, n, m, t;
    char phrase[11];
    printf("Enter phrase with max length: 10\n");
    fgets(phrase, 11, stdin);
    m=0;
    for(i=0; phrase[i]!='\0'; i++)
    {
        n=0;
        if(i>0)
        {
            t=0;
            for(j=0; j<i; j++)
            {
                if(phrase[j]==phrase[i])
                {
                    t=1;
                    break;
                }
            }
            if(t)
            {
                continue;
            }
        }
        for(j=i+1; j<11; j++)
        {
            if(phrase[i]==phrase[j])
            {
                n++;
            }
        }
        if(n>0)
        {
            m++;
        }
    }
    printf("Number of characters repeated: %d\n", m);
    printf("Characters repeated: \n");
        for(i=0; phrase[i]!='\0'; i++)
    {
        n=0;
        if(i>0)
        {
            t=0;
            for(j=0; j<i; j++)
            {
                if(phrase[j]==phrase[i])
                {
                    t=1;
                    break;
                }
            }
            if(t)
            {
                continue;
            }
        }
        for(j=i; j<10; j++)
        {
            if(phrase[i]==phrase[j+1])
            {
                n++;
            }
        }
        if(n>0)
        {
            printf("%c\n", phrase[i]);
        }
    }




    return 0;
}
