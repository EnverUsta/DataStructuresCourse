#include <stdio.h>
#include <stdlib.h>
#include "C:\GitHub\DataStructure\Questions2\matrixLibrary/matrix.h"	//for some useful functions.


//Formula that we only need = k = i*n + j(for row), k = j*n +i(for column). 

void question1(int *array, int n);						//Question1's respond.


int main(){
	int **matrix;						//It hasn't been allocated yet.
	int n = 4;							//dimension of matrix.
	createMatrix(&matrix, n);
	assignMatrix(matrix, n);
	printMatrix(matrix, n);

	int *array;							//It hasn't been allocated yet, it'll be allocated after the following function.
	transferToArrayRowStyle(matrix, &array, n);

	question1(array, n);


	free(matrix);
	free(array);
}

void question1(int *array, int n){
	//sort the 3rd row in the matrix by using array.
	//The formula will be k = i*n + j
	//3rd row so i will be equal to 2 (because index starts from 0)
	//j will increase like j = 0, 1, 2, 3... until it reaches to n-1
	
	//for sorting
	int i = 2;
	for(int j = 0; j < n; ++j){
		int k1 = i*n + j;
		for(int index = j+1; index < n; ++index){
			int k2 = i*n + index;
			if(array[k2] < array[k1]){
				int temp = array[k1];
				array[k1] = array[k2];
				array[k2] = temp;
			}
		}
	}

	//for printing, it'll print 3rd row after sorting.
	//assign i again.
	i = 2;
	for(int j = 0; j < n; ++j){
		int k = i*n + j;
		printf("%d\n", array[k]);
	}
}