#include <stdio.h>
#include "a7Defs.h"

void toLower(char *str) {
	int i = 0;
	while (str[i] != '\0') {
		if(str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	
}

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