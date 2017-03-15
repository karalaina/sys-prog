#include <stdio.h>
#include <string.h>

#define MAX_ARR  64
#define MAX_STR  32

typedef struct {
  char  code[MAX_STR];
  int   grade;
} CourseType;

typedef struct {
  CourseType elements[MAX_ARR];
  int size;
} CourseArrType;

typedef struct {
  char name[MAX_STR];
  char id[MAX_STR];
  CourseArrType courses;
  float gpa;
} StudentType;

void readString(char*);
void readInt(int*);
void initStudent(char*, char*, CourseArrType*, float, StudentType*);
void initCourse(char*, int, CourseType*);     
int getStuInfo(StudentType*);
void getCourseInfo(CourseArrType*);
float calcGPA(CourseArrType*); 
void printStudents(StudentType*, int);

int main() {
	int size;	//keeps track of number of students
	StudentType students[MAX_ARR];
	size = getStuInfo(students);
	printStudents(students, size);

  	return 0;
}

/*  Function:	getStuInfo
     Purpose: 	collect student info from user, create StudentType structures, add to given StudentType array
      in/out: 	students
         out: 	size
      Return: 	number of students added to student array
*/
int getStuInfo(StudentType *students) {
	char name[MAX_STR];
	char id[MAX_STR];
	CourseArrType courses;
	float gpa;
	int size = 0;
	int i = 0;

	while(1) {  //continuously asks for student info
		printf("Student Name: ");
		readString(name);
		if (strcmp(name, "-1") == 0) break; //until -1 entered
		printf("Student Id: ");
		readString(id);
		getCourseInfo(&courses);	//collect course info
		gpa = calcGPA(&courses); //get GPA
		initStudent(name, id, &courses, gpa, &students[i++]); // create StudentType structure  
		size++;
	}
	return size;	
}

/*  Function: 	calcGPA
     Purpose: 	calculate average grade of courses in CourseArrType given
      in/out: 	c
         out: 	gpa
     Returns: 	average grade of courses 
*/
float calcGPA(CourseArrType *c) {
	float total = 0;
	float gpa;
	if (c->size == 0)
		return 0;
	for (int i=0; i< c->size; i++) {
		total += (c->elements)[i].grade;
	}
	return gpa = total/(c->size);
}

/*   Function: 	getCourseInfo
      Purpose: 	collects course info from the user, creates a CourseType structure and adds it to CourseArrType given
       in/out: 	courses 
*/		
void getCourseInfo(CourseArrType *courses) {
	char code[MAX_STR];
	courses->size = 0;
	int g;
	int i = 0;

	while(1) {  //continuously asks for course info
		printf("\tCourse Code: ");
		readString(code);
		if (strcmp(code, "-1") == 0) break; //until -1 entered
		printf("\tCourse Grade: ");
		readInt(&g);
		if (g < 0 || g > 100) { //checks grade format 
			printf("Please enter a grade between 0 and 100\n");
			continue;
		}
		initCourse(code, g, &(courses->elements)[i++]); //creates CourseType stucture
		courses->size++;  
	}
}

/*   Function: 	initCourse
      Purpose: 	Creates CourseType structure from info given
           in: 	c
           in: 	g
       in/out: 	course
*/
void initCourse(char* c, int g, CourseType *course) {
	strcpy(course->code, c);
	course->grade = g;
}

/*   Function: 	initStudent
      Purpose: 	creates a StudentType structure with info given
           in: 	n
           in: 	i
           in: 	c
           in: 	g
       in/out: 	s 
*/
void initStudent(char *n, char* i, CourseArrType *c, float g, StudentType *s) {
	strcpy(s->name, n);
	strcpy(s->id, i);
	s->courses = *c;
	s->gpa = g;
}

/*  Function: 	printStudents
     Purpose: 	prints array of StudentType structures
          in: 	s
          in: 	size
*/
void printStudents(StudentType *s, int size) {
	printf("\n--STUDENTS--\n");
	for (int i=0; i<size; i++) {
		printf("Name: %s\nId: %s\n", s[i].name, s[i].id);
		printf("\tCourses:\n");
		for (int j=0; j<(s[i].courses.size); j++) {
			printf("\t\tCode: %s\tGrade: %d\n", s[i].courses.elements[j].code, s[i].courses.elements[j].grade);
		}
		printf("GPA: %.2f\n", s[i].gpa); 
	}

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

