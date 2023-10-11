
#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

Matrix::Matrix(){
	rowsNum=3;
	colsNum=3;
	matrixData=NULL;
	matrixData = (int**)malloc(rowsNum*sizeof(int*));

    // Allocate rows for fake "2D array":
	for (int i = 0 ; i < rowsNum ; ++i )
	{
	   matrixData[i] = (int*) malloc(colsNum*sizeof(int));
	}

	for (int i = 0 ; i < rowsNum ; ++i )
		for (int j = 0 ; j < colsNum ; ++j )
			matrixData[i][j]=0;
}

Matrix::Matrix( int row, int col ){

	/*
	* constructs a row-by-col matrix with
	* all elements equal to 0; if row ≤ 0, the number of rows of the matrix is set to
	* 3; likewise, if col ≤ 0 the number of columns of the matrix is set to 3.
	*/

	// instance variables
	rowsNum = (row <= 0) ? 3 : row;
	colsNum = (col <= 0) ? 3 : col;
	matrixData=NULL;

	// allocate memory and set each value to 0 using calloc()
	matrixData = (int**)calloc(rowsNum, sizeof(int*));
	for (int i = 0 ; i < rowsNum ; ++i ) {
	   matrixData[i] = (int*) calloc(colsNum, sizeof(int));
	}
}


Matrix::Matrix(int row, int col, int** table){

	/*
	* constructs a matrix out of the two dimensional array table, with the same number of rows, columns, and the same
	* element in each position as array table.
	*/

	// instance variables
	rowsNum = row;
	colsNum = col;
	matrixData=NULL;
	
	// allocate memory
	matrixData = (int**)calloc(rowsNum, sizeof(int*));
	for (int i = 0 ; i < rowsNum ; ++i ) {
	   matrixData[i] = (int*) calloc(colsNum, sizeof(int));
	}

	// set each element in the matrix to the corresponding value in the other matrix (pointed at by table)
	for (int i = 0 ; i < rowsNum ; ++i ) {
		for (int j = 0 ; j < colsNum ; ++j ) {
			matrixData[i][j]=table[i][j];
		}
	}
}

int Matrix::getElement(int i, int j){

	if (i < this->rowsNum && j < this->colsNum) { // check whether i and j are valid indexes
		return this->matrixData[i][j]; // if valid, return the element at those indexes
	} else {
		throw std::out_of_range( "Invalid indexes." ); // if not valid, throw exception
	}
}

bool Matrix::setElement(int x, int i, int j){

	if (i < this->rowsNum && j < this->colsNum) { // check whether i and j are valid indexes
		this->matrixData[i][j] = x; // if valid, set the element at those indexes to x
		return true;
	}

    return false; // return false if not valid
}


Matrix Matrix::copy(){

	/* fix the code and write your implementation below */

    Matrix copy = Matrix(this->rowsNum,this->colsNum); // construct new matrix object

    for (int i = 0 ; i < this->rowsNum ; ++i ) {
		for (int j = 0 ; j < this->colsNum ; ++j ) {
			copy.matrixData[i][j] = this->matrixData[i][j]; // add each element from this matrix to copied matrix
		}
	}

    return copy; // return copied matrix
}


void Matrix::addTo( Matrix m ){

	if (m.rowsNum == this->rowsNum && m.colsNum == this->colsNum) { // check whether matrices are the same size
		for (int i = 0 ; i < this->rowsNum ; ++i ) {
			for (int j = 0 ; j < this->colsNum ; ++j ) {
				this->matrixData[i][j] += m.matrixData[i][j]; // add each element of m matrix to each corresponding element of this matrix
			}
		}
	} else {
		throw std::invalid_argument( "Invalid operation" ); // if matrices are not the same size, throw exception
	}
}


Matrix Matrix::subMatrix(int i, int j){

	/* The exception detail message should read: "Submatrix not defined"*/
	/* fix the code and write your implementation below */

	Matrix subM;

	if (i < this->rowsNum && j < this->colsNum) {
		subM = Matrix (i+1,j+1);
		for (int a = 0; a <= i; ++a) {
			for (int b = 0; b <= j; ++b) {
				subM.matrixData[a][b] = this->matrixData[a][b];
			}
		}
	} else {
		throw std::out_of_range( "Submatrix not defined" ); // throw exception
	}

    return  subM;
}


int Matrix::getsizeofrows(){

	/* update below return */
	return this->rowsNum;
}


int Matrix::getsizeofcols(){

	/* update below return */
    return this->colsNum;
}


bool Matrix::isUpperTr(){

	/* write your implementation here and update return accordingly */
	for (int col = 0; col < this->colsNum; col++) {
		for (int row = col+1; row < this->rowsNum; row++) {
			if (this->matrixData[row][col] != 0) { // check to make sure each element below the main diagonal is 0
				return false; // if not, return false
			}
		}
	}
	
	return true;
}


string Matrix::toString(){

	string output="";

	for (int i = 0 ; i < this->rowsNum ; ++i ) {
		for (int j = 0 ; j < this->colsNum ; ++j ) {
			output += std::to_string(this->matrixData[i][j]) + " ";
		}
		output += "\n";
	}

	//return output;
	return output;
}
