#include <stdio.h>
#include "a7Defs.h"

void printGender(GenderType *g, char *gender) {
	switch(*g) {
		case MALE: strcpy(gender, "male"); break;
		case FEMALE: strcpy(gender, "female"); break;
	}
}

void printList(CatListType *cats) {
	NodeType *currNode, *prevNode;
	
	printf("--CATS--\n");
	printf("--forward--\n");
	for (currNode = cats->head, prevNode = NULL;
		currNode != NULL;
		prevNode = currNode, currNode = currNode->next) {
			printCat(currNode->data);
	}
	printf("--backward--\n");
	for (currNode = prevNode; currNode != NULL; 
		currNode = currNode->prev) {
			printCat(currNode->data);
	}
}

void printCat(CatType *cat) {
	char g[MAX_STR];
	printGender(&(cat->gender), g);
	printf("Name: %s\tId: %d\tGender: %s\n", cat->name, cat->id, g);
}