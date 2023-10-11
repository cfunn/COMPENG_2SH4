#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Questions.h"



char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	char *z = NULL;
	
	/*write your implementation here*/
	z = (char *) malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char)); // memory allocation for new string

	int index = 0; // define index of new string

	for (int i = 0; i < strlen(str1); i++) { // add each char of str1 to z
		z[index] = str1[i];
		index++;
	}
	for (int i = 0; i < strlen(str2); i++) { // add each char of str2 to z
		z[index] = str2[i];
		index++;
	}
	z[index] = '\0'; // add null character

	/* finally, return the string*/
	return z;
	
}
