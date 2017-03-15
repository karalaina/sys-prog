#include <stdio.h>

int main() {
	char x = 0xa3;
	char y = 0x0b;

	printf("x: %d\n", x);
	printf("y: %d\n", y);
	printf("x&y: %d\n", x&y);
	printf("x|y: %d\n", x|y);
	printf("y<<3: %d\n", y<<3);
	printf("x>>1: %d\n", x>>1);

	return 0;
}
