/***************************************************
 * Baboons.c
 * 
 * Two solutions to the Baboons
 * semaphore problem in Andrew
 * Tanenbaum's Minix Book.
 *
 * Make with:
 * $ make single
 * for a starved, single-mutex solution.
 * Code for this solution in single.c
 *
 * Make with:
 * $ make multi
 * for a no-starvation, turnstyle-mutex solution.
 * Code for this solution in multi.c
 *
 * Kat Cannon-MacMartin | 3-20-19 | Marlboro College
 ***************************************************/

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
  int pass[2] = {WEST, EAST};  // Array for passing directionals to baboon threads 
  pthread_t baboons[HOW_MANY]; // HOW_MANY defined in baboons.h

  setup(); // Initializes semaphores for the specific solution
  
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
