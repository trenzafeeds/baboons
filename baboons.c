#include "baboons.h"

void *baboon(void *side)
{
  start_crawl(*(int *)side);   // Get on the rope
  sleep(rand() % 3);           // Time to climb across the rope
  end_crawl(*(int *)side);     // Get off the rope
  return NULL;
}

int main()
{ 
  int pass[2] = {WEST, EAST};
  pthread_t baboons[HOW_MANY];

  setup();
  
  /* Create and run new Baboon threads at random intervals with random
   * direction.
   */
  for (int i = 0; i < HOW_MANY; i++) {
    pthread_create(&baboons[i], NULL, baboon, &pass[rand() % 2]);
    sleep(rand() % 2);
  }

  // Join all baboon threads.
  for (int i = 0; i < HOW_MANY; i++) {
    pthread_join(baboons[i], NULL);
  }
  
  return 0;
}
