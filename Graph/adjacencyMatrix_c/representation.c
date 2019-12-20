#include <stdio.h>
#include <stdlib.h>



int main(){
	printf("%s", "Enter the dimension: ");
	int dimension;
	scanf("%d", &dimension);
	int array[dimension][dimension];
	for(int i = 0; i < dimension; i++){
		for(int j = 0; j < dimension; j++){
			printf("Input For Graph(%d,%d): ",i+1,j+1);
			int number;
			scanf("%d", &number);
			array[i][j] = number;
			printf("\n");
		}
	}
}

