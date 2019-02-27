#include <stdio.h>
#include <pthread.h>

#include "which.h"

#ifndef WHICH
  #error WHICH is not defined
#endif

#include WHICH

#ifndef BABOONS
#define BABOONS 1

#define TRUE 1
#define FALSE 0

#define EAST 2
#define WEST 3

int baboon(int side);


#endif
