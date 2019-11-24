#include <stdio.h>


//TODO: swap function
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}



//TODO: selectionSort function
void selectionSort(int *array, int length){
	for(int startIndex = 0; startIndex < length; ++startIndex){
		int smallestIndex = startIndex;
		for(int currentIndex = startIndex+1; currentIndex < length; currentIndex++){
			if(array[currentIndex] < array[smallestIndex]){
				smallestIndex = currentIndex;
			}
		}
		swap(&array[startIndex], &array[smallestIndex]);
	}
}


int main(){
	int array[] = {10,9,5,6,8,7,4,3,1,2};
	selectionSort(array, 10);

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", array[i]);
	}
}