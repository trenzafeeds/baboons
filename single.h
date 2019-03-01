#include <stdio.h>
#include <pthread.h>

#ifndef SINGLEHEAD
#define SINGLEHEAD

void start_crawl(int side);
void end_crawl(int side);

#endif
