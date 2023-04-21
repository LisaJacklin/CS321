#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int totalSum;
    for(int i=1;i<1000;++i)
    {
        totalSum += i;
    }
    printf("Total Sum: %d\n", totalSum);
    return 0;
}
