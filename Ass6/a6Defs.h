#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARR  64
#define MAX_STR  32
#define C_OK	0
#define C_NOK	-1

typedef enum { MALE, FEMALE } GenderType;

typedef struct {
  int month;
  int year;
} DOBType;

typedef struct {
  int  id;
  char name[MAX_STR];
  GenderType gender;
  DOBType dob;
} CatType;

typedef struct {
  CatType *elements[MAX_ARR];
  int size;
} CatArrType;

void initArray(CatArrType*);
void initCat(int, char*, GenderType, int, int, CatType**);
int checkId(int, CatArrType*);
int getGender(char*, GenderType*);
void printGender(GenderType*, char*);
void getDOB(int, int, DOBType*);
void toLower(char*);
void printCat(CatType*);
void cleanup(CatArrType*);
