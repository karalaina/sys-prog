#include <stdio.h>
#include <stdlib.h>

int main()
{
  int numInts = 5;
  int *ptr;
  int i;

  ptr = malloc(numInts * sizeof(int));

  ptr[0] = 10;
  ptr[1] = 20;
  ptr[2] = 30;
  *(ptr + 3) = 40;
  *(ptr + 4) = 50;

  for (i=0; i<numInts; i++)
    printf("%d ", ptr[i]);

  printf("\n");

  for (i=0; i<numInts; i++, ptr++)
    printf("%d ", *ptr);

  printf("\n");


  return 0;
}

