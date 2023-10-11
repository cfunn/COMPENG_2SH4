#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[]){
	
	int index, ascii; // initialize variables
	for (int i = 0; word[i]; i++) { // go through word char by char
		ascii = (int) word[i]; // set ascii to ascii value of char
		if (ascii >= 65 && ascii <= 90) { // char is upper case
			index = ascii - 65;
		} else if (ascii >= 97 && ascii <= 122) { // char is lower case
			index = ascii - 97;
		} else { // if char is not a letter (e.g. a space)
			continue;
		}
		freq[index] += 1; // add 1 to appropriate index
	}
   
}
