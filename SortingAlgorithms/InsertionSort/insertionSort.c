#include <stdio.h>

//TODO: swap function
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//TODO: insertionSort function
/*
void insertionSort(int *array, int size){
	for(int  i = 1; i < size; ++i){
		int isBool = 0;
		int k;
		for(int j = 0; j < i; ++j){
			if(array[i] < array[j] && isBool != 1){
				isBool = 1;
				k = j;
			}
			if(isBool == 1){
				if(k != 0)
					swap(&array[i-j+1], &array[i-j]);
				else
					swap(&array[i-j], &array[i-j-1]);
			}
		}
	}
}
*/

void insertionSort(int *array, int size){
	int key, i, j;
	for (i = 1; i < size; ++i){
		key = array[i];
		j = i - 1;
		while(j >= 0 && array[j] > key){
			array[j+1] = array[j];
			j = j-1;
		}
		array[j+1] = key;
	}
}



int main(){
	int array[] = {10,9,5,6,8,7,4,3,1,2};
	insertionSort(array, 10);

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", array[i]);
	}
}