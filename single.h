#include <stdio.h>
#include <pthread.h>

#ifndef SINGLEHEAD
#define SINGLEHEAD

int start_crawl(int side);
int end_crawl(int side);

#endif
