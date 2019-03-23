/*************************************
 * multi.h
 * See baboons.c for full doc info.
 *************************************/

#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

#ifndef MULTIHEAD
#define MULTIHEAD

extern pthread_mutex_t gate;
extern pthread_mutex_t direction_mutex[2];
extern sem_t get_rope;

volatile int bound[2];

void setup();
void start_crawl(int side);
void end_crawl(int side);

#endif
