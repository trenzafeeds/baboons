#include "baboons.h"

void *baboon(void *side)
{
  start_crawl(*(int *)side);
  sleep(rand() % 3);
  end_crawl(*(int *)side);
  return NULL;
}

int main()
{
  pthread_mutex_init(&condition_mutex, NULL);
  pthread_cond_init(&condition_var, NULL);
  
  int pass[2] = {WEST, EAST};
  pthread_t test_thread;
  pthread_create(&test_thread, NULL, baboon, &pass[0]);
  pthread_join(test_thread, NULL);
  return 0;
}
