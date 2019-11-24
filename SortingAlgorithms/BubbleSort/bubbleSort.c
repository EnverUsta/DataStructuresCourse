#include <stdio.h>


//TODO: swap function
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


//TODO: bubbleSort function
void bubbleSort(int *array, int size){
	int isSwapped;
	for (int tour = 0; tour < size-1; ++tour)
	{
		isSwapped = 0;
		for(int bubble = 0; bubble < size-1-tour; bubble++){
			if(array[bubble+1] < array[bubble]){
				swap(&array[bubble+1], &array[bubble]);
				isSwapped = 1;
			}
		}
		if(isSwapped == 0) break;
	}
}




int main(){
	int array[] = {10,9,5,6,8,7,4,3,1,2};
	bubbleSort(array, 10);

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", array[i]);
	}
}