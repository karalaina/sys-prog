#include <stdio.h>
#include <stdlib.h>
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
  StudentType *comp2401A;
  int numStu, i;
  char str1[MAX_STR];
  char str2[MAX_STR];
  char str3[MAX_STR];
  int  tmpInt;
  float tmpFloat;

  printf("How many students? ");
  scanf("%d", &numStu);

  comp2401A = calloc(numStu, sizeof(StudentType));

  for (i=0; i<numStu; i++) {
    printf("Enter first name: ");
    scanf("%s", str1);
    printf("Enter last name: ");
    scanf("%s", str2);
    printf("Enter age: ");
    scanf("%d", &tmpInt);
    printf("Enter stu number: ");
    scanf("%s", str3);
    printf("Enter gpa: ");
    scanf("%f", &tmpFloat);

    initStudent(str1, str2, tmpInt, str3, tmpFloat, comp2401A + i);
//    initStudent(str1, str2, tmpInt, str3, tmpFloat, &(comp2401A[i]));
  }


  for (i=0; i<numStu; i++) {
    printStudent(comp2401A + i);
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

