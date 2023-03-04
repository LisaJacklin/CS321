//Lisa Jacklin
//CS 321 Lab 2 Hands on Exercise
//2/27/2023
/*---------------------------------------------

objective:
1. write a parent program to spawn child using fork
2. terminate w control c
3. uses sighandler 1and 2

4. child process repeated




*/
#include <cstdio>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

//a sighandler is required
void sig_handler (int signum) {
//terminate upon control-c
	if (signum == SIGINT) {
		printf("signal kill");
		_exit ;
	};
	//and because we are using SIGUSR1/SIGUSR2
	if (signum == SIGUSR1) {
		printf("SIGUSR1 recieved\n");
	}
	if (signum == SIGUSR2) {
		printf("SIGUSR2 recieved\n");
	}
}

int main(void) {
//first begin a parent program to spawn childen using fork
int pid = fork(); //should create a child process using a fork
	//gives a way to check and make sure that the child was created.
	if (pid >0) {
		printf("parent process created a child\n"); 
		return 0;
		};
	//I want to send a signal to the parent from the process
	sleep(3);	//I want to wait a random amount of time...so 3 clock cycles
	if (pid == 0) {
		kill (pid, SIGKILL); 
	};

//now the two signals SIGUSR1/SIGUSR2 must be installed...?

//terminate upon control-c
//note that this will be placed within the signal handler based on SIGKILL
	
//graceful exit
return 0;	
}
