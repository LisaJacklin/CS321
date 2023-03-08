// C program to demonstrate working of Semaphores
// Compile using: g++ demoPosixSemaphore.c -lpthread -lrt

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

void* aFunction(void *ptr);

sem_t mutex; //A semaphore variable. Whenever a thread lock (call wait) on this variable it gets an exclusive lock on the critical section. No other threads can enter the critical section that time. The other thread can enter only after the lock is released (call signal) by the first thread. 

void* aFunction(void* ptr)
{
	//wait
	//sem_wait(&mutex);
	printf("\nEntered..\n");//Thread acquired lock and entering critical section

	//critical section
	sleep(8);
	
	//signal
	printf("\nJust Exiting...\n"); //exiting and releasing the lock
	//sem_post(&mutex);
}


int main()
{
	sem_init(&mutex, 0, 1);
	pthread_t t1,t2;
	pthread_create(&t1,NULL,aFunction,NULL);//a thread is created and executing aFunction
	sleep(2);
	pthread_create(&t2,NULL,aFunction,NULL);//another thread is created after 2 seconds of the first one
	pthread_join(t1,NULL);//These joins will ensure that each thread is waiting until all threads complete
	pthread_join(t2,NULL);
	sem_destroy(&mutex);
	return 0;
}


/*
 * 2 threads are being created, one 2 seconds after the first one.
But the first thread will sleep for 8 seconds after acquiring the lock.
Thus the second thread will not enter immediately after it is called, it will enter 8 – 2 = 6 secs after it is called.*/

//Try commenting out the semaphore part. sem_wait(&mutex); and sem_post(&mutex);Then, observe the sequence of the print msg. You will see that both the threads enter the critical section simultaneously which should not happen.
