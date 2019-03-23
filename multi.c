/*************************************
 * multi.c
 * See baboons.c for full doc info.
 *************************************/

#include "multi.h"

pthread_mutex_t gate = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t direction_mutex[2] = {PTHREAD_MUTEX_INITIALIZER,
				      PTHREAD_MUTEX_INITIALIZER};
sem_t get_rope;
volatile int bound[2] = {0, 0};

void setup()
{
  pthread_mutex_init(&gate, NULL);
  pthread_mutex_init(&direction_mutex[0], NULL);
  pthread_mutex_init(&direction_mutex[1], NULL);
  sem_init(&get_rope, 0, 1);
}

void start_crawl(int side)
{
  int index = (side + 2) % 3; /* Turns side into an index
			       * -1 --> 1
			       *  1 --> 0 */
  pthread_mutex_lock(&gate);  // Only ONE baboon can be "in" the gate at a time
  pthread_mutex_lock(&direction_mutex[index]); // Lock for bound array (side-specific)
  bound[index]++;  
  if (bound[index] == 1) {  // If this  baboon is the first in its direction, it has to get the rope
    sem_wait(&get_rope);
  }
  printf("Starting crawl: %d\n", side);
  pthread_mutex_unlock(&direction_mutex[index]);
  pthread_mutex_unlock(&gate);
}

void end_crawl(int side)
{
  int index = (side + 2) % 3;
  pthread_mutex_lock(&direction_mutex[index]); // Needs to access bound array again
  bound[index]--;
  printf("Finished crawl: %d\n", side);
  if (bound[index] == 0) {            // If this baboon is the last off the rope, it gives up the rope
    sem_post(&get_rope);
  }
  pthread_mutex_unlock(&direction_mutex[index]);
}

