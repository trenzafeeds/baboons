#include <stdio.h>
#include <pthread.h>

#ifndef SINGLEHEAD
#define SINGLEHEAD

extern pthread_mutex_t condition_mutex;
extern pthread_cond_t condition_var;
volatile int count;


void start_crawl(int side);
void end_crawl(int side);

#endif
