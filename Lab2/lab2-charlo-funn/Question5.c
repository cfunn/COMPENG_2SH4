#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

void string_copy(const char source[], char destination[], int n){

	for (int i = 0; i < n; i++) { // iterate through destination
		destination[i] = (i < n-1 && source[i] ? source[i] : '\0'); // if not the last element, add source[i] to array; otherwise add null char
	}
    
}
