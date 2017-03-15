#include <stdio.h>
#include <stdlib.h>

void doAlloc(int*);

int main()
{
  int numInts = 2;
  int *ptr1, *ptr2;

  ptr1 = malloc(numInts * sizeof(int));
  ptr1[0] = 10;
  ptr1[1] = 20;
  free(ptr1);

  doAlloc(ptr2);

  printf("ptr2 contains %d\n", *ptr2);

  return 0;
}

void doAlloc(int *p)
{
  p = malloc(sizeof(int));

  *p = 80;
}


