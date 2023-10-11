
#include "Questions.h"



int Q1_for(){
	int sum = 0;
	
	// calculate your sum below..this has to use for loop
	for (int i = 30; i <= 1000; i += 2) { // increment by 2 each time; if number is divisible by 4 it will be divisible by 2
		if (i % 4 == 0) { // check to see if number is divisible by 4
			sum += i; // increment sum
		}
	}
	
	// here, we return the calculated sum:
	return sum;
}
int Q1_while(){
	int sum = 0;
	int i = 30;

	// calculate your sum below..this has to use while loop
	while (i <= 1000) {
		if (i % 4 == 0) { // check whether number is divisible by 4
			sum += i; // increment sum
		}
		i += 2; // increment by 2
	}
	
	// here, we return the calculated sum:
	return sum;
}
int Q1_do(){
	int sum = 0;
	int i = 30;
	
	// calculate your sum below..this has to use do-while loop
	do {
		if (i % 4 == 0) { // check whether number is divisible by 4
			sum += i; // increment sum
		}
		i += 2;
	} while (i <= 1000);
	
	// here, we return the calculated sum:
	return sum;
}
//===============================================================================================
int Q2(int Q2_input){
	
	// this is the flag that is holding whether the input number is 5-digit or not
	int IsFiveDigit = 0;
	int count = 0;

	Q2_input = abs(Q2_input); // change to absolute value; sign has no impact on number of digits
	
	// Do your coding below to check
	while (Q2_input >= 10) { // check to see whether number is greater than or equal to 10
		Q2_input /= 10; // divide by 10 to remove another digit from the number
		count++; // add one to count
	}
	count++; // if number is less than 10, there must be one digit left, so add one to count
	
	if (count == 5) { // check whether there are 5 digits
		IsFiveDigit = 1;
	}
	
	//finally, we must return IsFiveDigit, which must be 1 is the number is five digits and 0 otherwise
	return IsFiveDigit;
}
//===============================================================================================
int Q3(float Q3_input){
	
	/* Question 3: 
	Write a program that takes a student's Q3_input as an input, which is a floating point value,
	and returns:
	4 if the Q3_input is in the range 90-100,
	3 if it is in the range 80-89, 
	2 if it is in the range 70-79,
	1 if it is in the range 60-69 and
	0 if the Q3_input is between 0 and 59.
	If the Q3_input is not in the range 0-100, the program should return -1
*/	
	// this is the variable that holds the out value to return
	float GPA;
	
	
	// Do your coding below to calculate the GPA variable value
	if (Q3_input < 0 || Q3_input > 100) { // first check whether the input is out of range
		GPA = -1;
	} else if (Q3_input >= 90) { // if input is in range and it is greater than or equal to 90, it must be in the range 90-100
		GPA = 4;
	} else if (Q3_input >= 80) { // if this is true, the input must be in the range 80-89.9999 (since the last else if statement was not true)
		GPA = 3;
	} else if (Q3_input >= 70) { // and so on...
		GPA = 2;
	} else if (Q3_input >= 60) {
		GPA = 1;
	} else {
		GPA = 0;
	}
	
	// finally, we return the GPA
	return GPA;	
}
//===============================================================================================
double Q4(int Q4_input){
	
	// this is the variable that holds the pi value to return
	double pi=0;
	
	
	// Do your coding below to calculate the pi value
	for (int n = 0; n < Q4_input; n++) {
		if (n % 2 == 0) { // if n is even, add term
			pi += 4.0 / (1.0 + 2.0*n);
		} else { // if n is odd, subtract term
			pi -= 4.0 / (1.0 + 2.0*n);
		}

	}
	
	// finally, we return the pi value
	return pi;	
}
//===============================================================================================
int Q5(){
	
	// this is the variable that holds and the total number of triples to return at the end of the function
	int totNumTriples=0;
	
	
	/* Do your coding below
		Use a triple-nested for loop that simply tries all possibilities
		and update the total number of triples if needed
	*/
	
	for (int hypot = 1; hypot <= 400; hypot++) {
		for (int side1 = 1; side1 <= 400; side1++) {
			for (int side2 = 1; side2 <= 400; side2++) {
				if (side1 <= side2 && side1*side1 + side2*side2 == hypot*hypot) { // make sure the formula fits and make sure side1 is less than or equal to side2
					totNumTriples++; // increment total number of triples
				}
			}
		}
	}

	
	//finally you should return the total number of triples.
	return totNumTriples;
}
//===============================================================================================
int Q6(int Q6_input, int perfect[]){
	
	
	
		//counts is the variable that should hold the total number of found perfect numbers
		//you should update it within your code and return it at the end
	    int counts=0;


		/*
		*
		*perfect is an array that you need to add into it any perfect number you find
		*which means at the end of this function, the perfect[] array should hold all the found perfect numbers in the range
		*you do not need to return perfect because as stated in lectures arrays are already passed by reference. so, modifying them will 
		*automatically reflect in the main calling function.
		*/
	    
		for (int num = 1; num < Q6_input; num++) { // go through all numbers from 1 to Q6_input and check for perfect numbers
			int sum = 0; // initialize sum of perfect numbers
			for (int i = 1; i < num; i++) { // go through all numbers from 1 to num to get the factors of num
				if (num % i == 0) {
					sum += i; // add the factors of num to sum
				}
			}
			if (sum == num) { // check to see whether the sum equals num
				perfect[counts] = num; // if so, add num to perfect
				counts++; // increment counts
			}
		}

	   return counts;

	
}
//===============================================================================================
int Q7a(int Q7_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;
	
	
	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//in this part you can assume the knowledge of the number of digits: seven-digit positive integer
	
	for (int i = 1000000; i > 0; i /= 10) { // this should iterate 7 times
		reversedInt += (Q7_input % 10) * i; // add another digit, multiplied by the correct amount to be able to add it to reversedInt
		Q7_input /= 10; // take off another digit
	}
	
	return reversedInt;

}
int Q7b(int Q7b_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;
	

	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//this part should be generalized for any number of allowed digits
	
	while (Q7b_input > 0) { // make sure number is greater than 0 (meaning there are more digits left in the number)
		reversedInt *= 10; // multiply by 10 to shift the digits over and make room for a new digit
		reversedInt += Q7b_input % 10; // add new digit to reversedInt
		Q7b_input /= 10; // remove that same digit from Q7b_input
	}
	
	return reversedInt;
}
