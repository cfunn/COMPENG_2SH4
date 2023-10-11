#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr []){

	int index = 0; // define index
	for (int sum = 0; sum < 2*N3-1; sum++) { // (column #)+(row #) in each diagonal is constant - look through matrix column by column to get the correct order
		for (int c = 0; c < N3; c++) { // c = column
			for (int r = 0; r < N3; r++) { // r = row
				if (c+r == sum) { // find all entries of the matrix where c+r = sum
					arr[index] = mat[r][c]; // add to array
					index++;
					break; // move on to the next column
				}
			}
			if (c > sum) { // if c > sum, then all entries in the diagonal should have been found
				break; // move on to the next diagonal
			}
		}
	}
}
