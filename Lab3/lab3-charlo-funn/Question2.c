#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


student **create_class_list(char *filename, int *sizePtr){
	
	student **class_list;

	/*write your implementation here*/
	FILE *class_file = fopen(filename, "r"); // open file
	fscanf(class_file, "%d", sizePtr); // find class size by reading first line of file
	class_list = (student **) calloc(*sizePtr, sizeof(student *)); // allocate memory for class list

	for (int i = 0; i < *sizePtr; i++) { // iterate through each student
		student *studentPtr = (student *) calloc(6, sizeof(student)); // allocate memory for the student
		fscanf(class_file, "%d %s %s", &(studentPtr->student_id), (char *)&(studentPtr->first_name), (char *)&(studentPtr->last_name)); // read line in file with student info, assign to members of student structure
		class_list[i] = studentPtr; // add student to class list
	}

	fclose(class_file); // close file

	/* finally return the created class list*/
	return class_list;
}

int find(int idNo, student **list, int size)
{
	
	/*write your implementation here and update the return accordingly*/
	int index = -1;
	for (int i = 0; i < size; i++) { // loop through list
		if (list[i]->student_id == idNo) { // find index of student number
			index = i;
			break; // break once found
		}
	}

	return index;
}

void input_grades(char *filename, student **list, int size)
{

	/*write your implementation here*/
	FILE *grade_file = fopen(filename, "r"); // open file to read
	int idNo, index;
	for (int i = 0; i < size; i++) { // loop through lines of grade file
		fscanf(grade_file, "%d", &idNo); // get student id
		index = find(idNo, list, size); // get index of student in the class list
		fscanf(grade_file, "%d %d", &(list[index]->project1_grade), &(list[index]->project2_grade)); // get the student's corresponding grades and assign to grades in student structure
	}

	fclose(grade_file); // close file

}

void compute_final_course_grades(student **list, int size)
{
	
	/*write your implementation here*/
	double g1, g2, gFinal;
	for (int i = 0; i < size; i++) { // loop through class list
		g1 = (double) list[i]->project1_grade; // get project 1 grade
		g2 = (double) list[i]->project2_grade; // get project 2 grade
		gFinal = (g1+g2)/2; // compute final grade
		list[i]->final_grade = gFinal; // add final grade to student structure
	}

}

void output_final_course_grades(char *filename, student **list, int size)
{
	
	/*write your implementation here*/
	FILE *grade_file = fopen(filename, "w"); // open file to write
	fprintf(grade_file, "%d\n", size); // add class size to file

	for (int i = 0; i < size; i++) { // loop through list and add student numbers and final grades to file
		fprintf(grade_file, "%d %f\n", list[i]->student_id, list[i]->final_grade);
	}

	fclose(grade_file); // close file
}


void withdraw(int idNo, student **list, int* sizePtr)
{
	/*write your implementation here*/
	int index = find(idNo, list, *sizePtr); // get index of student to remove
	if (index == -1) { // check whether id exists in the list
		printf("Student %d is not in this class!\n", idNo);
	} else {
		int i;
		for (i = index; i < *sizePtr-1; i++) { // shift each element to the left to replace the element that was removed
			list[i] = list[i+1];
		}
		free(list[i]); // deallocate space
		*sizePtr -= 1; // update size of list
	}
}

void destroy_list(student **list, int *sizePtr)
{
	/*write your implementation here*/
	for (int i = 0; i < *sizePtr; i++) { // free each student individually
		free(list[i]);
	}
	free(list); // free list as a whole
	*sizePtr = 0; // update size of list
}
