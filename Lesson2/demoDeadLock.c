//Compile using: g++ demoDeadLock.c -lpthread -lrt

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
void *function1(void *ptr);
void *function2(void *ptr);

sem_t first_mutex; //mutex lock
sem_t second_mutex;

void *function1(void *ptr) {
  sem_wait(&first_mutex); //Here thread-ONE is waiting for first_mutex. Since no one is using it thread-ONE locks the first_mutex
  printf("Thread ONE acquired first_mutex\n");
  sleep(1); //This is the critical section of thread-ONE. Once thread-ONE is inside this critical section, thread-TWO cannot use it
  sem_wait(&second_mutex); //Here thread-ONE is waiting on first_mutex. But, it is already locked by thread-TWO
  printf("Thread ONE acquired second_mutex\n");
  sem_post(&second_mutex);//release mutex lock
  printf("Thread ONE released second_mutex\n");
  sem_post(&first_mutex);
  printf("Thread ONE released first_mutex\n");
}

void *function2(void *ptr) {
  sem_wait(&second_mutex); //Here thread-TWO is waiting for second_mutex. Since no one is using is thread-TWO locks the second_mutex
  printf("Thread TWO acquired second_mutex\n");
  sleep(1); //This is the critical section of thread-TWO. Once thread-TWO is inside this critical section, thread-ONE cannot use it
  sem_wait(&first_mutex); //Here thread-TWO is waiting on first_mutex. But, it is already locked by thread-ONE
  printf("Thread TWO acquired first_mutex\n");
  sem_post(&first_mutex);
  printf("Thread TWO released first_mutex\n");
  sem_post(&second_mutex);
  printf("Thread TWO released second_mutex\n");
}


int main() {
 sem_init(&first_mutex, 0, 1);
 sem_init(&second_mutex, 0, 1);
 pthread_t one, two;  
 pthread_create(&one, NULL, function1, NULL);  // create thread
 pthread_create(&two, NULL, function2, NULL);
 pthread_join(one, NULL);
 pthread_join(two, NULL);
 printf("Thread joined\n");
}

//Try with a different sequence of lock and release (i.e., wait and post). Is the program going into deadlock?
