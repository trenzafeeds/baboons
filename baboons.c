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
  pthread_t baboons[HOW_MANY];
  for (int i = 0; i < HOW_MANY; i++) {
    pthread_create(&baboons[i], NULL, baboon, &pass[rand() % 2]);
    sleep(rand() % 2);
  }
  for (int i = 0; i < HOW_MANY; i++) {
    pthread_join(baboons[i], NULL);
  }
  return 0;
}
