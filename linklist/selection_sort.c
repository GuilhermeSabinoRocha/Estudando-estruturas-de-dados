#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

main()
{
    char A[] = {5,8,2,3,7,6,1};
    int n = strlen(A);
    printf("%d\n", n);
    int i;
    int j;
    
    for (i = 0; i < n - 1; i++)
    {
        int imin = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[imin])
            {
               imin = j;
                
            }

        }
        int temp = A[i];
        A[i] = A[imin];
        A[imin] = temp;

    }

    int k;
    for (k = 0; k < n; k++)
    {
        printf("%d ", A[k]);
    }
        
}