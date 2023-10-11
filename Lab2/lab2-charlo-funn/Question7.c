#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2){

	int index1 = -1, index2 = -1; // index1 and index2 will be assigned the indices at which there are non-zero values in val1 and val2
	int index3 = 0; // index3 will be the index of val3 and pos3, and will increment after a new element is added
	for (int index = 0; index <= pos1[k1-1] || index <= pos2[k2-1]; index++) { // loop through each possible index until the biggest index in pos1 or pos2
		for (int i = 0; i < k1; i++) { // loop through pos1
			if (pos1[i] == index) { // if pos1 contains the current index, save that pos1 index (in index1)
				index1 = i;
				break; // break out of loop once value is found
			}
		}
		for (int i = 0; i < k2; i++) { // loop through pos2
			if (pos2[i] == index) { // if pos2 contains the current index, save that pos2 index (in index2)
				index2 = i;
				break; // break out of loop once value is found
			}
		}
		if (index1 >= 0 && index2 >= 0) { // both val1 and val2 have non-zero values for this index
			if ((val1[index1] + val2[index2]) != 0) { // make sure the sum doesn't equal 0
				val3[index3] = val1[index1] + val2[index2]; // add sum to val3
				pos3[index3] = index; // add index to pos3
				index3++; // increment index3
			}
		} else if (index1 >= 0) { // only val1 has a non-zero value for this index
			val3[index3] = val1[index1]; // add value to val3
			pos3[index3] = index; // add index to pos3
			index3++; // increment index3
		} else if (index2 >= 0) { // only val2 has a non-zero value for this index
			val3[index3] = val2[index2]; // add value to val3
			pos3[index3] = index; // add index to pos3
			index3++; // increment index3
		}
		index1 = -1; // reset index1 and index2
		index2 = -1;
	}
}
