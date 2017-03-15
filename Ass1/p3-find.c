#include <stdio.h>

#define MAX_SIZE 16
#define C_OK      0
#define C_NOK    -1

void initArray(int*);
int  findNum(int*, int);

int main()
{
  int array[MAX_SIZE];
  int selectedNum, index;

  initArray(array);

  printf("Please enter the number you want to find: ");
  scanf("%d", &selectedNum);

  index = findNum(array, selectedNum);

  if (index < 0) {
    printf("Sorry, we could not find your number\n");
  }
  else {
    printf("We found your number %d at index %d\n", selectedNum, index);
  }

  return 0;
}

/*
  Function:  initArray
  Purpose:   initialize an array with Fibonacci numbers
      out:   arr
*/
void initArray(int *arr)
{
  int i;

  arr[0] = 0;
  arr[1] = 1;

  for (i=2; i<MAX_SIZE; i++) {
    arr[i] = arr[i-1] + arr[i-2];
  }

  for (i=0; i<MAX_SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

}

/*
  Function:  findNum
  Purpose:   to find a given number in a given array
       in:   arr
       in:   num
   return:   index where we found the number, or C_NOK if not found
*/
int findNum(int *arr, int num)
{
  int i;

  for (i=0; i<MAX_SIZE; i++) {
    if (arr[i] == num) {
      return i;
    }
  }
  return C_NOK;
}


