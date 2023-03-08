//Thread demo: g++ demoThread.c -lpthread -lrt

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>

// This C function will execute as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp)
{
  sleep(1);
  printf("Printing from Thread \n");
  return NULL;
}

int main()
{
  pthread_t thread_id;
  printf("Before Thread\n");
  pthread_create(&thread_id, NULL, myThreadFun, NULL);//myThreadFun will start executing
  pthread_join(thread_id, NULL); //Terminate the thread
  printf("After Thread\n");
  exit(0);
}

