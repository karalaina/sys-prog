#include <stdio.h>

#define MAX_SIZE 16

int getNums(int*);
int computeMax(int*, int);

int main()
{
  int array[MAX_SIZE];
  int total, max;

  total = getNums(array);

  max = computeMax(array, total); 

  printf("The max is %d\n", max);

  return 0;
}

int getNums(int *arr)
{
  int currNum, i, totalNums;

  totalNums = 0;

  printf("Enter a number: ");
  scanf("%d", &currNum);

  while (currNum >= 0 && totalNums < MAX_SIZE) {
    arr[totalNums] = currNum;
    totalNums++;
    printf("Enter a number: ");
    scanf("%d", &currNum);
  }
  return totalNums;
}

int computeMax(int *arr, int total)
{
  int tmpMax = 0;
  int i;

  for (i=0; i<total; i++) {
    if (arr[i] > tmpMax) {
      tmpMax = arr[i];
    }
  }
  return tmpMax;
}


