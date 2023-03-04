//lab 2
//sample program 1
///----

#include <cstdio>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sigHandler (int); //initializing the function below


int main() {
	signal(SIGINT, sigHandler);
	//signal (SIGINT,sigHandler);
	printf("waiting...\n");
	pause();
	return 0;
}

void sigHandler (int sigNum) {
   //if (sigNum == SIGINT)
	printf("received an interrupt signal through Ctrl-c. \n");
	
	printf("going to sleep.\n nottice the process is not exiting immmediately");
	//this is where shutdown code would be inserted
	sleep(1);
	printf("ouut of here.\n");
	
	printf ("now the process will termmmmminate with the exit system call\n");
	exit(0);
}
