#include <stdio.h>
#include "a7Defs.h"

void addCat(CatListType **cats, CatType *cat) {
	NodeType *currNode, *prevNode, *newNode;
	currNode = (*cats)->head;
	prevNode = NULL;
	
	newNode = malloc(sizeof(NodeType)); 
	newNode->data = cat;
	newNode->next = NULL;
	newNode->prev = NULL;
  	if((*cats)->head == NULL) {
		(*cats)->head = newNode;
		(*cats)->tail = newNode;
	}else{
		while (currNode != NULL) {
			if(strcmp(currNode->data->name, cat->name) > 0) break;
			if(strcmp(currNode->data->name, cat->name) < 0) {
				prevNode = currNode;
				currNode = currNode->next;
			}
		} 
		if (prevNode == NULL) {
			currNode->prev = newNode;
			newNode->next = currNode;
			(*cats)->head = newNode;
		}
		if (currNode == NULL) {
			prevNode->next = newNode;
			newNode->prev = prevNode;
			(*cats)->tail = newNode;
		}
		if (currNode != NULL && prevNode != NULL) {
			prevNode->next = newNode;
			newNode->next = currNode;
			newNode->prev = prevNode;
			currNode->prev = newNode;		 
		}
	}	
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


