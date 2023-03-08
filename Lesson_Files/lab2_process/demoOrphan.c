//A process whose parent process no more exists i.e. either finished or terminated without waiting for its child process to terminate is called an orphan process.

//In the following code, parent finishes execution and exits while the child process is still executing and is called an orphan process now.

//However, the orphan process is soon adopted by init process, once its parent process dies.

// A C program to demonstrate Orphan Process.
// Parent process finishes execution while the
// child process is running. The child process
// becomes orphan.
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    // Create a child process
    int pid = fork();

    if (pid > 0){
        printf("in parent process");
	exit(0);
    }

    // Note that pid is 0 in child process
    // and negative if fork() fails
    else if (pid == 0)
    {
        sleep(50);
        printf("in child process");
    }

    return 0;
}
