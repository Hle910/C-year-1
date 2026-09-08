#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void f(int num, int init, int prev);

int main()
{
    int n, m;
    m=1;
    printf("Enter a number of terms you would like to print: \n");
    scanf("%d", &n);
    f(n, m, 0);

    return 0;
}

void f(int num, int init, int prev)
{

    int x;
    x=(prev*prev)+1;
    printf("%d\n", x);
    if(init<num)
    {
        f(num, init+1, x);
    }
}
