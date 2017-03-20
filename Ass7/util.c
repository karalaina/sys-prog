#include <stdio.h>
#include "a7Defs.h"

int getGender(char *gender, GenderType *g) {
	toLower(gender);
	if (strcmp(gender, "male") == 0) {
		*g = MALE;
		return C_OK;
	}
	if (strcmp(gender, "female") == 0) {
		*g = FEMALE;
		return C_OK;
	}else{
		return C_NOK;
	}
}

void printGender(GenderType *g, char *gender) {
	switch(*g) {
		case MALE: strcpy(gender, "male"); break;
		case FEMALE: strcpy(gender, "female"); break;
	}
}

void toLower(char *str) {
	int i = 0;
	while (str[i] != '\0') {
		if(str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
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
		
void cleanup(CatListType *cats) {
	NodeType *currNode, *nextNode;
	currNode = cats->head;

	while(currNode != NULL) {
		nextNode = currNode->next;
		free(currNode->data);
		free(currNode);
		currNode = nextNode;
	}
	free(cats);
}


