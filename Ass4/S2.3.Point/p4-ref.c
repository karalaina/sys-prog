#include <stdio.h>
#include <string.h>

#define MAX_STR  32

typedef struct {
  char first[MAX_STR];
  char last[MAX_STR];
  int  age;
} PersonType;

typedef struct {
  PersonType basicInfo;
  char   stuNumber[12];
  float  gpa;
} StudentType;

void printStudent(const StudentType*);
void initStudent(char*, char*, int, char*, float, StudentType*);

int main()
{
  PersonType gertrude;
  StudentType comp2401A[200];
  StudentType *stuPtr;
  int i;

  strcpy(gertrude.first, "Gertrude");
  strcpy(gertrude.last,  "Kardashian");
  gertrude.age   = 99;

  StudentType stuGert;
  stuGert.basicInfo = gertrude;
  strcpy(stuGert.stuNumber, "1007654444");
  stuGert.gpa = 11.0;

// Initializing Matilda
  initStudent("Matilda", "Moore", 22, "100777666", 9.2, comp2401A);
  initStudent("Matilda", "Moore", 22, "100777666", 9.2, &(comp2401A[0]));

// Initializing Joe
  initStudent("Joe", "Physics", 24, "100222333", 5.2, &(comp2401A[1]));
  initStudent("Joe", "Physics", 24, "100222333", 5.2, comp2401A + 1);

  comp2401A[2] = stuGert;

  for (i=0; i<3; i++) {
    printStudent(comp2401A + i);
    printStudent(&(comp2401A[i]));
  }

  return 0;
}

void initStudent(char *f, char *l, int a, char *n, float g, StudentType *stu)
{
  strcpy(stu->basicInfo.first, f);
  strcpy(stu->basicInfo.last, l);
  stu->basicInfo.age = a;
  strcpy(stu->stuNumber, n);
  stu->gpa = g;
}

void printStudent(const StudentType *stu)
{
  printf("Student #%s:  %s %s, age %d, gpa %.1f\n",
         stu->stuNumber, stu->basicInfo.first,
         stu->basicInfo.last, stu->basicInfo.age,
         stu->gpa); 
//  stu->gpa = 12;

}

