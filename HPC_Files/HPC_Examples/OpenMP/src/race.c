#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int snum=10;
    int* inputArr = (int*) malloc(sizeof(int)*snum);
    int i;
    int sum = 0;
    for(i=0;i<snum;++i)
    {
        inputArr[i] = i+1;
    }
    #pragma omp parallel for schedule(static)
    for (i = 0; i < snum; ++i)
    {
        int* tmpsum = inputArr+i;
        sum += *tmpsum;
    }
    printf("test: %d\n", sum);
    return 0;
}
