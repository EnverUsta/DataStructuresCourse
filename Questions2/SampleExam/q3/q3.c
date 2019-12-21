#include <stdio.h>
#include <stdlib.h>



int** createMatrix(int n)
{
	int **matrix = malloc(sizeof(int*)*n);
	for(int i = 0; i < n; ++i)
	{
		*(matrix+i) = malloc(sizeof(int));
	}
	return matrix;
}


void initializeMatrix(int **matrix, int dimension)
{
	int k = 1;
	for(int i = 0; i < dimension; ++i){
		for(int  j = 0; j < dimension; ++j){
			matrix[i][j] = k++;
		}
	}
}


void printMatrix(int **matrix, int dimension)
{
	for(int i = 0; i < dimension; ++i){
		for(int  j = 0; j < dimension; ++j){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}


//Necessary function r. row and k. column
void quiz3(int r, int k, int dimension, int **matrix)
{
	r--;
	k--;
	int sum = 0;
	for(int i = 0; i < dimension; i++){
		sum += matrix[i][k] * matrix[r][i];
	}
	printf("result: %d \n", sum);
}

int main()
{
	int **matrix = createMatrix(3);
	initializeMatrix(matrix, 3);
	printMatrix(matrix, 3);
	quiz3(1,2,3,matrix);

}