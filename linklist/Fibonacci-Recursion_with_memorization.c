#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int F[51];
int fib(int n);

int main(void)
{
    int i;
    for (i = 0; i < 51; i++)
    {
        F[i] = - 1;
    }
    F[0] = 0; F[1] = 1;
    int n ;
    printf("give me n\n");
    scanf("%d", &n);
    int result = fib(n);
    printf("%d\n", result);


}
    
int fib(int n)
{
    if(F[n]!= -1) 
    {return F[n];}

    F[n] = fib(n-1) + fib(n-2);
    return F[n];
}