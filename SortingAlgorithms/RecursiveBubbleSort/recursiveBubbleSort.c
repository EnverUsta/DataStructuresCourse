#include <stdio.h>

//TODO: swap function
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


//TODO:bubbleSortRecursively function
void bubbleSortRecursively(int *array, int size){
	//Base case
	if(size == 1) return;

	// One pass of bubble sort. After 
    // this pass, the largest element 
    // is moved (or bubbled) to end.
	for(int bubble = 0; bubble < size-1; ++bubble)
		if(array[bubble+1] < array[bubble])
			swap(&array[bubble+1], &array[bubble]);
	
	// Largest element is fixed, 
    // recur for remaining array 
	bubbleSortRecursively(array, size-1);
}




int main(){
	int array[] = {10,9,5,6,8,7,4,3,1,2};
	bubbleSortRecursively(array, 10);

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", array[i]);
	}
}