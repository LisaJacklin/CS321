#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int partialSum, totalSum;
    #pragma omp parallel private(partialSum) shared(totalSum)
    {
        #pragma omp for
        for(int i=1;i<10000;++i)
        {
            partialSum += i;
        }
        #pragma omp critical
        {
            totalSum += partialSum;
        }
    }
    printf("Total Sum: %d\n", totalSum);
    return 0;
}
