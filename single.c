/*************************************
 * single.c
 * See baboons.c for full doc info.
 *************************************/

#include "single.h"

pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;
volatile int count = 0;

void setup()
{
  pthread_mutex_init(&condition_mutex, NULL);
  pthread_cond_init(&condition_var, NULL);
}

void start_crawl(int side)
{
  pthread_mutex_lock(&condition_mutex);
  while ((count * side) < 0) {         // checks if count is 0 OR has same sign (neg/pos) as side 
    pthread_cond_wait(&condition_var, &condition_mutex); // condition_mutex UNLOCKED while waiting
  }
  printf("Starting crawl: %d\n", side);
  count = count + side;                  // count will be incremented or decremented depending on side
  pthread_mutex_unlock(&condition_mutex);
}

void end_crawl(int side)
{
  pthread_mutex_lock(&condition_mutex);
  count = count - side;
  printf("Finished crawl: %d\n", side);
  pthread_cond_broadcast(&condition_var); // Wake up all waiting threads so they each check count
  pthread_mutex_unlock(&condition_mutex); // One of the awoken threads will take this mutex on release
}
