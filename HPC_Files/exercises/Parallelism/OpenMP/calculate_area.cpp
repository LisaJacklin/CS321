#include <omp.h>
#include <iostream>
#include <ctime>
#include <utility>
#include <random>

int main()
{
    std::srand(time(NULL));
    int size = 100000;
    int plots[size][2];
    int totalPlotSize = 0;
    // Initialize plots
    for(int i=0;i<size;++i)
    {
        plots[i][0] = std::rand() % 100;
        plots[i][1] = std::rand() % 100;
    }
    // Calculate area of each plot, and sum up
    int partialPlotSize = 0;
    
    //OpenMP Here
    for(int i=0;i<size;++i)
    {
        partialPlotSize = plots[i][0] * plots[i][1];
        totalPlotSize+=partialPlotSize;
    }
    std::cout << totalPlotSize << std::endl;
    return 0;
}
