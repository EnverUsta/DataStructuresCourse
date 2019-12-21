#include <stdio.h>
#include <stdlib.h>


void initializeMatrixZero(int dimension, int matrix[dimension][dimension])
{
	for(int i = 0; i < dimension; ++i){
		for(int j = 0; j < dimension; ++j){
			matrix[i][j] = 0;
		}
	}
}


void printMatrix(int dimension, int matrix[dimension][dimension])
{
	for(int i = 0; i < dimension; ++i){
		for(int j = 0; j < dimension; ++j){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}


void addLink(int dimension, int matrix[dimension][dimension])
{
	printf("Which row: ");
	int r;
	scanf("%d", &r);
	printf("Which Column: ");
	int c;
	scanf("%d", &c);
	matrix[r-1][c-1] = 1;
}


int main(){
	printf("%s", "Enter the Number of Nodes: ");
	int dimension;
	scanf("%d", &dimension);
	int matrix[dimension][dimension];
	initializeMatrixZero(dimension, matrix);
	printMatrix(dimension, matrix);

	printf("How many link you'll add: \n");
	int howMany;
	scanf("%d", &howMany);
	int i =0;
	while(i < howMany){
		addLink(dimension, matrix);
		i++;
	} 
	printMatrix(dimension, matrix);
	
}

