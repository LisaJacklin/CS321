/* Understanding signals */
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
  if (signo == SIGINT)
    printf(" Received SIGINT\n");
  //if (signo == SIGKILL)
  //  printf(" Received SIGKILL\n");
  if (signo == SIGUSR1)
    printf(" Received SIGUSR1\n");
  if (signo == SIGSTOP)
    printf(" Received SIGSTOP\n");

}

int main(void)
{
  if (signal(SIGINT, sig_handler) == SIG_ERR)
    printf("\ncan't catch SIGINT\n");
  if (signal(SIGKILL, sig_handler) == SIG_ERR)
    printf("\ncan't catch SIGKILL\n");
  if (signal(SIGUSR1, sig_handler) == SIG_ERR)
    printf("\ncan't catch SIGUSR1\n");
  if (signal(SIGSTOP, sig_handler) == SIG_ERR)
    printf("\ncan't catch SIGSTOP\n");
  // A long long wait so that we can easily issue a signal to this 
  // process
  while(1) 
    sleep(1);
  return 0;
}

/*Code explanation for SIGKILL: SIGINT is a signal generated when a user presses Control-C. This will terminate the program from the terminal. In the code above, we have simulated a long running process using an infinite while loop.

A function sig_handler is used as a signal handler. This function is "registered" to the kernel by passing it as the second argument of the system call signal in the main() function. The first argument to the function signal is the signal we intend the signal handler to handle which is SIGINT in this case.

On a side note, the use of function sleep(1) has a reason behind. This function has been used in the while loop so that while loop executes after some time (i.e. one second in this case). This becomes important because otherwise an infinite while loop running wildly may consume most of the CPU making the computer very very slow.

Anyway, coming back, when the process is run and we try to terminate the process using Control-C, we get: 
$ ./sigfunc
^Creceived SIGINT
^Creceived SIGINT
^Creceived SIGINT
^Creceived SIGINT
^Creceived SIGINT
^Creceived SIGINT
^Creceived SIGINT
*/
