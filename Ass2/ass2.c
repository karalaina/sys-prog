#include <stdio.h>

#define MAX_VAL 	16

int fillArray(float*);
int addToArray(float*, int, float);
float sumArray(float*, int);
float evalGrade(float*, float*, int);

int main() {
	float scheme[MAX_VAL];
	float grades[MAX_VAL];
	int s, g;	//size of scheme and grades respectively 		
	float sum;

	printf("Enter grading scheme:\n");
	s = fillArray(scheme);
	sum = sumArray(scheme, s);
	while(sum != 100) {	//continue collecting sets of numbers until sum of elements in scheme = 100. 
		printf("Grading scheme must add to 100%%.\n");
		printf("Enter grading scheme:\n");
		s = fillArray(scheme);
		sum = sumArray(scheme, s);
	}

	printf("Enter grades:\n");
	g = fillArray(grades);
	while(s != g) {		//continue collecting sets of numbers until total numbers in grades = total numbers in scheme. 
		printf("Invalid amount of grades entered.\n");
		printf("Enter grades:\n");
		g = fillArray(grades);
	}
	printf("Final grade: %.1f%%\n", evalGrade(scheme, grades,s));	
	return 0;
}
/*  Function: 	fillArray
     Purpose: 	collect numbers from the user and append to the given array
      in/out:  	arr
         out: 	size
      Return: 	new size of array after numbers added
*/
int fillArray(float* arr) {
	float num;
	int size = 0; 
	while(1) {	//continue collecting numbers and adding them to array until negative number entered 
		printf(">");
		scanf("%f", &num);
		if (num >= 0 && size<MAX_VAL) {
			size = addToArray(arr, size, num);
		}else{
			break;
		}
	}
	return size;
}
/*  Function: 	addToArray
     Purpose: 	append given number to given array
      in/out: 	arr
      in/out: 	size
          in: 	num
      Return: 	new size of array after number added
*/
int addToArray(float* arr, int size, float num) {
	arr[size++] = num;
	return size;
}
/*  Function: 	sumArray
     Purpose: 	find the sum of all values in the given array
          in: 	arr
          in: 	size
         out: 	sum
      Return: 	sum of all values in the given array
*/
float sumArray(float* arr, int size) {
	float sum = 0;
	for (int i=0; i<size; i++) {	//add each value of array to running sum
		sum += arr[i];
	}
	return sum;
}
/*  Function: 	evalGrade
     Purpose: 	evaluate the final grade from the given grading scheme and grades
          in: 	scheme
          in: 	grades
          in: 	size
         out: 	grade
      Return: 	the final grade 
*/
float evalGrade(float* scheme, float* grades, int size) {
	float grade = 0;
	for (int i=0; i<size; i++) {	//add weighted grade for each value in grades to running sum 
		grade += grades[i]*(scheme[i]/100);
	}
	return grade;
} 		 
