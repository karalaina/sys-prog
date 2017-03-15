#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int i;

  for (i=0; i<argc; i++) {
    printf("Argument %d is %s\n", i, argv[i]);
  }

  if (argc > 4) {
    if (strcmp(argv[4], "dragon") == 0)
      printf("A queen, her nephew and her advisor\n");
  }

  return 0;
}

