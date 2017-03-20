#include <stdio.h>
#include "a7Defs.h"

int main() {
	CatListType *cats;

	initAllCats(&cats);
	printList(cats);
	cleanup(cats);
	return 0;
}	

