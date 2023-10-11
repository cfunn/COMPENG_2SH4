#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void efficient(const int source[], int val[], int pos[], int size){
	
	int index = 0;
	for (int i = 0; i < size; i++) { // iterate through source
		if (source[i] != 0) { // find non-zero values
			val[index] = source[i]; // add non-zero values to val
			pos[index] = i; // add indices to pos
			index++; // increment index of val and pos
		}
	}
}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){

    for (int i = 0; i < m; i++) { // iterate through source
    	for (int j = 0; j < n; j++) { // iterate through pos
    		if (i == pos[j]) { // if i is equal to one of the non-zero positions, add the value to source
    			source[i] = val[j];
    		}
    	}
    	if (!source[i]) { // if no non-zero value has been found for the index, set it to 0
    		source[i] = 0;
    	}
    }

}
