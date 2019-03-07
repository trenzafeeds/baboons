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
  int index = (side + 2) % 3; /* -1 --> 1
			       *  1 --> 0 */
  pthread_mutex_lock(&gate);
  pthread_mutex_lock(&direction_mutex[index]);
  bound[index]++;
  if (bound[index] == 1) {
    sem_wait(&get_rope);
  }
  printf("Starting crawl: %d\n", side);
  pthread_mutex_unlock(&direction_mutex[index]);
  pthread_mutex_unlock(&gate);
}

void end_crawl(int side)
{
  int index = (side + 2) % 3;
  pthread_mutex_lock(&direction_mutex[index]);
  bound[index]--;
  printf("Finished crawl: %d\n", side);
  if (bound[index] == 0) {
    sem_post(&get_rope);
  }
  pthread_mutex_unlock(&direction_mutex[index]);
}

