#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

main()
{
    char A[] = {5,1,2,3,7,6,4};
    int n = strlen(A);
    printf("%d\n", n);
    int i;
    int j;
    
    for (j = 1; j < n ; j++)
    {
        for (i = 0; i < n - 1; i++)
        {
            if (A[i] > A[j])
            {
                int temp = A[j];
                A[j] = A[i];
                A[i] = temp;

            }
            
        }
        

    }

    int k;
    for (k = 0; k < n; k++)
    {
        printf("%d ", A[k]);
    }
        
}