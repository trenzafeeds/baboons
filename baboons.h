#include "baboons.h"
#include <pthread.h>
#include <stdio.h>

#ifdef SINGLE
#include "single.h"
#else
#include "multi.h"
#endif

#ifndef BABOONS
#define BABOONS 1

#define TRUE 1
#define FALSE 0

#define EAST 2
#define WEST 3

int baboon(int side);




#endif
