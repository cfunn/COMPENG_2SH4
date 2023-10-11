#include <stdio.h>
#include <stdlib.h>

#include<math.h>
#include "Questions.h"



void add_vectors(double vector1[],double vector2[],double vector3[],int size)
{
    /*vector3 should store the sum of vector1 and vector2. 
	You may assume that all three arrays have the size equal to n
	*/
	//write your code below
	
	for (int i=0; i<size; i++) {
		vector3[i] = vector1[i] + vector2[i]; // each element in vector 3 is the sum of the corresponding elements in vectors 1 and 2
	}
}

double scalar_prod(double vector1[],double vector2[],int size)
{
	// this is the variable holding the scalar product of the two vectors
    double prod=0;

	//write your code below to calculate the prod value
	
    for (int i=0; i<size; i++) {
    	prod += vector1[i] * vector2[i]; // get the product of the ith elements of each vector, then add it to prod
    }

	
	// return the result
    return prod;
}

double norm2(double vector1[], int size)
{
	//this is the variable holding the L2 norm of the passed vector
    double L2;
	
    
	//write your code here
	// you should call function scalar_prod().

    L2 = sqrt(scalar_prod(vector1, vector1, size)); // get the square root of the scalar product of the vector with itself
	
	//finally, return the L2 norm 
    return L2;
}
