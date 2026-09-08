#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, i, d;
    printf("So you want two numbers factored.\n");
    printf("Give them to me one by one and I will do the factoring.\n\n");

    for(int j=0; j<2; j++)
    {
        printf("Number? ");
        scanf("%d", &x);
        i=2;
        printf("The prime factorization of %d is 2", x);
        while(x>1)
            {
                if(x==1)
                    {
                        break;
                    }
                else if((x%i)==0)
                    {
                        printf("*%d", i);
                        x=x/i;
                    }
                else
                    {
                        i++;
                    }
            }
        printf("\n\n");
    }
    return 0;
}
