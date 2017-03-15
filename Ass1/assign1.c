#include <stdio.h>

#define MAX_VALUE	20

int addToArray(int*,int,int);
int remFromArray(int*, int, int);
void printArray(int*, int);

int main() {
	int array[MAX_VALUE];
	int numToAdd, size = 0;

	printf("Please enter a number to add: ");
	scanf("%d", &numToAdd);
        while (numToAdd != -1 && size<MAX_VALUE) {
		size = addToArray(array, size, numToAdd);
                printf("Please enter a number to add: ");  
                scanf("%d", &numToAdd);
	}
	printArray(array, size);
	
	int numToGo;
	printf("Please enter a number to remove: ");
	scanf("%d", &numToGo);
	while (numToGo != -1) {
		size = remFromArray(array, size, numToGo);
		printf("Please enter a number to remove: ");
		scanf("%d", &numToGo);
	}
	printArray(array, size);
	return 0;
}
/*   Function:	addToArray
      Purpose:	add a given integter to a given array in ascending order
       in/out:	arr
       in/out: 	size
           in: 	numToAdd
       Return: 	new size of array after integer is added
*/
int  addToArray(int* arr, int size, int numToAdd) {
	int index;

	if(numToAdd<arr[0]) {
		for(int i=size; i>0; i--) {
			arr[i] = arr[i-1];
		}
		arr[0] = numToAdd;
		size++;
	}
	else if(numToAdd>arr[size-1]) { 
		arr[size] = numToAdd;
		size++;
	}
	else {
		for(int i=0; i<size; i++) {
			if (numToAdd >= arr[i] && numToAdd <= arr[i+1]) {
				index = i+1;
			}
		}
		for(int i=size; i>index; i--) {
			arr[i] = arr[i-1];
		}
		arr[index] = numToAdd;
		size++;
	}
	return size;
}
/*   Function:	remFromArray
      Purpose: 	remove a given integer from a given array
       in/out: 	arr
       in/out: 	size
           in: 	numToGo
       Return: 	new size of array after integer is removed or the 
		original size if integer is not in the array 
*/
int remFromArray(int* arr, int size, int numToGo) {
	int index;

	for(int i=0; i<size; i++) {
		if (arr[i] == numToGo) {
			index = i;
			for(int j=index; j<size; j++) {
				arr[j] = arr[j+1];
			}
			size--;
			break;
		}
	}
	return size;	
}							
/*   Function:	printArray
      Purpose: 	print all elements of a given array
           in: 	arr
           in: 	size
*/
void printArray(int* arr, int size) {
	for(int i=0; i<size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");		
}	

