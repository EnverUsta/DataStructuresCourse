#ifndef MATRIX_H
#define MATRIX_H

void transferToArrayColumnStyle(int **matrix, int **array, int n){
	*array = (int*)malloc(sizeof(int)*n*n);
	int k = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			(*array)[k++] = matrix[j][i];
		}
	}
}

void transferToArrayRowStyle(int **matrix, int **array, int n){
	*array = (int*)malloc(sizeof(int)*n*n);
	int k = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			(*array)[k++] = matrix[i][j];
		}
	}
}

void createMatrix(int ***matrix, int n){
	*matrix = (int**)malloc(sizeof(int*)*n);
	for(int i = 0; i < n; i++){
		*(*matrix+i) = (int*)malloc(sizeof(int)*n);
	}
}

void createArray(int **array, int length){
	*array = (int*)malloc(sizeof(int)*length);
}


void printMatrix(int **matrix, int n){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			printf("i:%d j:%d value:%d\n",i+1, j+1, *(*(matrix+i)+j));
		}
	}
}

void assignMatrix(int **matrix, int n){
	int x = 1;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			*(*(matrix+i)+j) = x++;
		}
	}
}

void assignArray(int *array, int length){
	int x = 1;
	for(int i = 0; i < length; ++i){
		*(array+i) =  x++;
	}
}


#endif