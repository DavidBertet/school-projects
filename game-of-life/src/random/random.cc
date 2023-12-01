#include "random.hh"

static unsigned long    next;

int
my_rand ()
{
  next = next * 1103515245 + 12345;

  return (next >> 16) & 32767;
}

void
my_srand (unsigned int seed)
{
  next = seed;
}
