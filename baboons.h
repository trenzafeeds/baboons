/*************************************
 * baboons.h
 * See baboons.c for full doc info.
 *************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef SINGLE
  #include "single.h"
#else
  #include "multi.h"
#endif /* SINGLE */

#ifndef BABOONS
#define BABOONS

#define HOW_MANY 10

#define TRUE 1
#define FALSE 0

#define EAST 1
#define WEST -1

void *baboon(void *side);

int main();

#endif /* BABOONS */
