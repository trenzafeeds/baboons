#include "single.h"

pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;
volatile int count = 0;

void start_crawl(int side)
{
  pthread_mutex_lock(&condition_mutex);
  while ((count * side) < 0) {
    pthread_cond_wait(&condition_var, &condition_mutex);
  }
  printf("Starting crawl: %d\n", side);
  count = count + side;
  pthread_mutex_unlock(&condition_mutex);
}

void end_crawl(int side)
{
  pthread_mutex_lock(&condition_mutex);
  count = count - side;
  printf("Finished crawl: %d\n", side);
  pthread_cond_broadcast(&condition_var);
  pthread_mutex_unlock(&condition_mutex);
}
