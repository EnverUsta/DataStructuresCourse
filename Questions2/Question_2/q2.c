#include <stdio.h>
#include <stdlib.h>
#include "C:\GitHub\DataStructure\Questions2\matrixLibrary/matrix.h"	//for some useful functions.

//Formula that we only need => k = i*n - i*(i+1)/2 + j
//Our array will have 15 elements
//Our matrix will be upper triangular matrix

void question2(int *array, int n);		//n is the dimension of the matrix.


int main(){
	int *array;
	createArray(&array, 15);			//allocating memory for 15 elements
	assignArray(array, 15);
	question2(array, 5);
}


void question2(int *array, int n){
	//Firstly, allocate a matrix
	int **matrix;
	matrix = (int**)malloc(sizeof(int*)*n);
	for(int i = 0; i < n; ++i){
		*(matrix+i) = (int*)malloc(sizeof(int)*n);
	}

	//Secondly, assigning the values to matrix.
	for(int i = 0; i < n; ++i){
		for(int j = i; j < n; ++j){
			int k = i*n - i*(i+1)/2 + j;
			matrix[i][j] = array[k];
		}
	}

	//Finally, finding the biggest value in the last column
	int lastColumnIndex = n-1;
	int biggestValue = matrix[0][lastColumnIndex];	//initialize it with the first one.
	for(int i = 1; i < n; i++){						//we don't need to look at first one again.
		if(matrix[i][lastColumnIndex] > biggestValue)
			biggestValue = matrix[i][lastColumnIndex]; 
	}
	printf("%d\n", biggestValue);

}