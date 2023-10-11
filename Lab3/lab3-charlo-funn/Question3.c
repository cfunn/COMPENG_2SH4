#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"




char **read_words(const char *input_filename, int *nPtr){

	
    char **word_list;

    /*write your implementation here*/
//    FILE *input_file = fopen(input_filename, "r");
//    fscanf(input_file, "%d", nPtr);
//    word_list = (char **) calloc(*nPtr, sizeof(char *));
//
//    for (int i = 0; i < *nPtr; i++) {
//    	char *str;
//    	fscanf(input_file, "%s", (char *) str);
//    	printf("%s", str);
//    	str = (char *) calloc(strlen(str), sizeof(char));
//    	word_list[i] = str;
//    	printf("\n%s", word_list[i]);
//    }

    return word_list;

}

int compare_str(const char *str1,const char *str2){

	/*this is a helper function that you can implement and use to facilitate your development*/
   	/*compare_str alphabetically compares two strings.
    	If str2 is alphabetically smaller than str1 (comes before str1),
    	the function returns a 1, else if str1 is smaller than str2, the
    	function returns a 0.*/

	/*write your implementation here and update the return accordingly*/
    return -1;
    
}

void sort_words(char **words, int size){
   
	/*write your implementation here*/
}

void swap(char **str1, char **str2){
 
	/*this is a helper function that you can implement and use to facilitate your development*/
}

void sort2_words(char **words, int size){

   
	/*write your implementation here*/
    
}

