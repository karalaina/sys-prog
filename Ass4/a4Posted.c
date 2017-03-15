#include <stdio.h>
#include <string.h>

#define MAX_ARR  64
#define MAX_STR  32

typedef enum { COMEDY, DRAMA, HORROR, SCIFI 
} GenreType;

typedef struct {
  char title[MAX_STR];
  char director[MAX_STR];
  int  year;
  GenreType genre;
} MovieType;

void initMovie(char*, char*, int, GenreType, MovieType*);
void printMovies(MovieType*, int);
void readString(char*);
void readInt(int*);


int main()
{

  return 0;
}


/*
    Function:  readString
    Purpose:   reads a string from standard input
        out:   string read in from the user
               (must be allocated in calling function)
*/
void readString(char *str)
{
  char tmpStr[MAX_STR];

  fgets(tmpStr, sizeof(tmpStr), stdin);
  tmpStr[strlen(tmpStr)-1] = '\0';
  strcpy(str, tmpStr);
}

/*
    Function:  readInt
    Purpose:   reads an integer from standard input
        out:   integer read in from the user
               (must be allocated in calling function)
*/
void readInt(int *x)
{
  char str[MAX_STR];

  readString(str);
  sscanf(str, "%d", x);
}

