
#include "stdio.h"
#include "stdlib.h"

int fact(int n) {
if (n < 0)
return 0;
else if (n == 0)
return 1;
else if (n == 1)
return 1;
else
return n * fact(n - 1);
}
int main(void)
{
    int x = fact(4);
    printf("%d\n", x);
}