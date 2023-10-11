#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"


int is_diag_dom(int mat[][N2]){

    //this is the flag that is returned to tell whether the mat is diagonally dominant
	int isDiag=0;
	
	//write your code below
	//Return 1 if the matrix is diagonally dominant and 0 otherwise
	
	for (int i = 0; i < N2; i++) { // iterate through each row
		int abs; // initialize absolute value of the row's diagonal element
		int sum = 0; // define sum of all other elements in the row
		for (int j = 0; j < N2; j++) { // iterate through each column (each element in the row)
			if (i == j) { // find the diagonal element
				abs = fabs(mat[i][j]); // define abs
			} else { // if not the diagonal element
				sum += fabs(mat[i][j]); // add its absolute value to sum
			}
		}
		if (abs <= sum) { // if abs is not greater than sum, the matrix is not diagonally dominant
			break; // break out of the loop
		} else if (i == N2-1) { // if still in the loop once all the rows have been checked, it must be diagonally dominant
			isDiag = 1;
		}
	}


    return isDiag;
}
