#include "baboons.h"

void *baboon(void *side)
{
  start_crawl(*(int *)side);
  sleep(random());
  end_crawl(*(int *)side);
  return 0;
}

int main()
{
  printf("hello");
}
