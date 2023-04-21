#include <omp.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        printf("Hello world(%d)\n", ID);
    }
    return 0;
}
