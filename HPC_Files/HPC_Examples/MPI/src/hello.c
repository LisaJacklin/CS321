#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
   int task;
   
   MPI_Init(&argc,&argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &task);
     
   printf("Hello World from task %d\n",task);
            
   MPI_Finalize();
}
