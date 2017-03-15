#include <stdio.h>
#include "a6Defs.h"

int main() {
	CatArrType catArr;
	catArr.size = 0;
	
	initArray(&catArr);
	for (int i=0; i<catArr.size; i++) {
		printCat(catArr.elements[i]);
	}
	cleanup(&catArr); 

	return 0;
} 
/*   Function:	initArray
      Purpose: 	collect cat data from the user and initialize CatArrType
       in/out: 	catArr
*/
void initArray(CatArrType *catArr) {
	int i, rc, id, year, month;
	char name[MAX_STR];
	char g[MAX_STR];
	GenderType gender;
	i = 0; //keeps track of position

	while(catArr->size < MAX_ARR) {
		printf("Enter cat's name: ");
		scanf("%s", name);
		if (strcmp(name, "-1") == 0) break;	//stop adding cats if -1 entered
		printf("Enter cat's id (XXX): ");
		scanf("%d", &id);
		rc = checkId(id, catArr);	
		if(id < 100 || id > 999) {	//checks if id within given range
			printf("Please enter valid id (3 digits)\n");
			continue;
		}
		if(rc == -1) {			//check if id already in use
			printf("Id already in use\n");
			continue;
		}
		printf("Enter cat's gender (male/female): ");
		scanf("%s", g);
		rc = getGender(g, &gender);		
		if (rc < 0) {			//checks if valid gender entered
			printf("Please enter a valid gender\n");
			continue;
		}		
		printf("Enter cat's date of birth: \n");
		printf("\tYear (1900-2016): ");
		scanf("%d", &year);
		if (year < 1900 || year > 2016) {	//checks if valid year entered
			printf("Please enter a valid year\n");
			continue;
		}
		printf("\tMonth (1-12): ");
		scanf("%d", &month);
		if (month < 0 || month > 12) {		//checks if valid month entered
			printf("Please enter a valid month\n");
			continue;
		}
		
		initCat(id, name, gender, year, month, (catArr->elements+i));	//adds CatType to current postion in array
		i++;	//increments position
		catArr->size++;
	}
}
/*   Function: 	checkId
      Purpose: 	check id already exists for a cat in the given array
           in: 	id
           in: 	catArr
      Returns: 	C_NOK if is already exists, C_OK if it does not
*/
int checkId(int id, CatArrType *catArr) {
	for(int i=0; i<catArr->size; i++) {	//iterate through list
		if (id == catArr->elements[i]->id) {	//check if id already in use
			return C_NOK;
		}
	}
	return C_OK;
}
/*   Function: 	toLower
      Purpose: 	set all characters in a string to lower-case
       in/out: 	str
*/
void toLower(char *str) {
	int i = 0;
	while (str[i] != '\0') {	//loop until null reached
		if (str[i] >= 65 && str[i] <= 90) { //if character upper-case
			str[i] += 32; //change to lower-case
		}
		i++;
	}
}
/*   Function: 	getGender
      Purpose: 	get the appropriate GenderType value for given gender string
	   in: 	g
          out: 	gender
      Returns: 	C_NOK if string is not eqivalent to a gender value, C_OK if it is 
*/
int getGender(char *g, GenderType *gender) {
	toLower(g);
	if (strcmp(g, "male") == 0) {
		*gender = MALE;
		return C_OK;
	}
	if (strcmp(g, "female") == 0) {
		*gender = FEMALE;	
		return C_OK;
	}else{
		return C_NOK;
	}
}
/*   Function: 	printGender
      Purpose: 	get the appropriate string for the given GenderType
           in: 	g
          out: 	gender
*/
void printGender(GenderType *g, char *gender) {
	switch(*g) {
		case MALE: strcpy(gender, "male"); break;
		case FEMALE: strcpy(gender, "female"); break;
	}
}
/*   Function: 	getDOB
      Purpose: 	initialize DOBType with given year and month
           in: 	y
           in: 	m
          out: 	dob
*/
void getDOB(int y, int m, DOBType *dob) {
	dob->month = m;
	dob->year = y;	
}
/*   Function: 	initCat
      Purpose: 	initialize CatType with given id, name, gender, year, and month
	   in: 	id
	   in: 	n
	   in: 	g
	   in: 	y
	   in: 	m
	  out: 	cat
*/
void initCat(int id, char *n, GenderType g, int y, int m, CatType **cat) {
	*cat = (CatType *) malloc(sizeof(CatType)); //dynamically allocate memory for CatType
	DOBType dob;
	getDOB(y, m, &dob);
	(*cat)->id = id;
	strcpy((*cat)->name, n);
	(*cat)->gender = g;
	(*cat)->dob = dob;
}
/*   Function: 	printCat
      Purpose: 	print out contents of given CatType
           in: 	cat
*/
void printCat(CatType *cat) {
	char g[MAX_STR];
	printGender(&(cat->gender), g);
	printf("\n");
	printf("Name: %s\tId: %d\n", cat->name, cat->id);
	printf("\tGender: %s\n\tDate of Birth (mm-yyyy): %02d-%04d\n", 
		g, cat->dob.month, cat->dob.year);
} 
/*   Function: 	cleanup
      Purpose: 	free dynamically allocated memory
           in: 	catArr
*/
void cleanup(CatArrType *catArr) {
	for (int i=0; i<catArr->size; i++) {
		free(catArr->elements[i]);
	}
}  	
