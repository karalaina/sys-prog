#include <stdio.h>
#include "a7Defs.h"

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

/*   Function: 	printList
      Purpose: 	print the contents of a CatListType
           in: 	cats
*/
void printList(CatListType *cats) {
	NodeType *currNode, *prevNode;
	
	printf("--CATS--\n");
	printf("--forward--\n");
	for (currNode = cats->head, prevNode = NULL;	
		currNode != NULL;
		prevNode = currNode, currNode = currNode->next) {	//access each node in forward direction
			printCat(currNode->data); 
	}
	printf("--backward--\n");
	for (currNode = prevNode; currNode != NULL;  	
		currNode = currNode->prev) {		//access each node in backward direction
			printCat(currNode->data);
	}
}

/*   Function: 	printCat
      Purpose: 	print the contents of a CatType
           in: 	cat
*/
void printCat(CatType *cat) {
	char g[MAX_STR];
	printGender(&(cat->gender), g); //get string equiv to GenderType
	printf("Name: %s\tId: %d\tGender: %s\n", cat->name, cat->id, g);
}
