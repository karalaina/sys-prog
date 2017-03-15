#include <stdio.h>
#include "a7Defs.h"

/*   Function: 	initAllCats
      Purpose: 	get data from user to initiate CatType structures and add them to a CatListType 
       in/out:	cats
*/
void initAllCats(CatListType **cats) {
	*cats = malloc(sizeof(CatListType));
	(*cats)->head = NULL;
	(*cats)->tail = NULL;	
	
	int id, rc;
	char name[MAX_STR];
	char gender[MAX_STR];
	GenderType g;
	CatType *newCat;

	while(1) {
		printf("Enter cat's name: ");
		scanf("%s", name);
		if(strcmp(name, "-1") == 0) break;
		printf("Enter cat's id (3-digits): ");
		scanf("%d", &id);
		while (id < 100 || id > 999) {	//check for valid id input
			printf("Please enter a valid id: ");
			scanf("%d", &id);
		}
		printf("Enter cat's gender (male/female): ");
		scanf("%s", gender);
		rc = getGender(gender, &g);
		while (rc < 0) {		//check for valid gender input
			printf("Please enter a valid gender: ");
			scanf("%s", gender);
		}
		initCat(id, name, g, &newCat);	//init CatType struc		
		addCat(cats, newCat);		//add to CatListType struc
	}
}

/*   Function: 	initCat
      Purpose: 	initialize a CatType structure with given data
           in: 	id, n, g
          out: 	cat
*/
void initCat(int id, char *n, GenderType g, CatType **cat) {
	*cat = (CatType *) malloc(sizeof(CatType));
	(*cat)->id = id;
	strcpy((*cat)->name, n);
	(*cat)->gender = g;
}
