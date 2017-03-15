#include <stdio.h>

#define MAX_VALUE       20

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
        else{
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

void printArray(int* arr, int size) {
        for(int i=0; i<size; i++) {
                printf("%d ", arr[i]);
        }
        printf("\n");
}




