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

#define EAST 1
#define WEST -1

void *baboon(void *side);



#endif
