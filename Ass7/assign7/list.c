#include <stdio.h>
#include "a7Defs.h"

/*   Function: 	addCat
      Purpose: 	add a CatType structure to the linked list in a CatListType structure
       in/out: 	cats
           in: 	cat 
*/
void addCat(CatListType **cats, CatType *cat) {
	NodeType *currNode, *prevNode, *newNode;
	currNode = (*cats)->head;
	prevNode = NULL;
	
	newNode = malloc(sizeof(NodeType)); 
	newNode->data = cat;
	newNode->next = NULL;
	newNode->prev = NULL;
	//if list is empty...
  	if((*cats)->head == NULL) {
		(*cats)->head = newNode;
		(*cats)->tail = newNode;
	}else{
		while (currNode != NULL) { //find spot for alphabetical insertion
			if(strcmp(currNode->data->name, cat->name) > 0) break;
			if(strcmp(currNode->data->name, cat->name) < 0) {
				prevNode = currNode;
				currNode = currNode->next;
			}
		} 
		//if adding to the front
		if (prevNode == NULL) {
			currNode->prev = newNode;
			newNode->next = currNode;
			(*cats)->head = newNode;
		}
		//if adding to the back
		if (currNode == NULL) {
			prevNode->next = newNode;
			newNode->prev = prevNode;
			(*cats)->tail = newNode;
		}
		//if adding in the middle
		if (currNode != NULL && prevNode != NULL) {
			prevNode->next = newNode;
			newNode->next = currNode;
			newNode->prev = prevNode;
			currNode->prev = newNode;		 
		}
	}	
}
/*   Function: 	cleanup
      Purpose: 	free all dynamically allocated memory
           in: 	cats
*/	
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


