#include <stdio.h>
#include "a7Defs.h"

/*   Function: 	toLower
      Purpose: 	set all characters of a given string to lower-case
       in/out: 	str
*/
void toLower(char *str) {
	int i = 0;
	while (str[i] != '\0') { //loop until null reached
		if(str[i] >= 65 && str[i] <= 90) //if char is uppercase
			str[i] += 32;	//make it lowercase
		i++;
	}
	
}

/*   Function: 	getGender
      Purpose: 	get the appropriate GenderType value for the given string
           in: 	gender
          out: 	g
      Returns: 	C_NOK is string is not equivalent to a gender value, C_OK if it is
*/
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
