#include <stdio.h>
#include <time.h>


void exeTime(clock_t start, clock_t end){
	double sure = (double)(end - start) / CLOCKS_PER_SEC;
	int dakika, saniye;
	double salise;
	dakika = (sure / 60);
	saniye = (sure - (dakika * 60));
	salise = (sure - (dakika * 60) - (saniye)) * 60;
	printf("\nsure(dakika:saniye:salise)= %d:%d:%f\n", dakika, saniye, salise);
}

//TODO: swap function
//Auxiliary function
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

//Auxiliary function
int binarySearch(int a[], int item, int low, int high) 
{ 
    if (high <= low) 
        return (item > a[low])?  (low + 1): low; 
  
    int mid = (low + high)/2; 
  
    if(item == a[mid]) 
        return mid+1; 
  
    if(item > a[mid]) 
        return binarySearch(a, item, mid+1, high); 
    return binarySearch(a, item, low, mid-1); 
} 
  

// Function to sort an array a[] of size 'n' 
void binaryInsertionSort(int a[], int n) 
{ 
    int i, loc, j, k, selected; 
  
    for (i = 1; i < n; ++i) 
    { 
        j = i - 1; 
        selected = a[i]; 
  
        // find location where selected sould be inseretd 
        loc = binarySearch(a, selected, 0, j); 
  
        // Move all elements after location to create space 
        while (j >= loc) 
        { 
            a[j+1] = a[j]; 
            j--; 
        } 
        a[j+1] = selected; 
    } 
} 

void straightInsertionSort(int Dizi[], int boyut) {
	int i, j,current;
	for (i = 0; i < boyut; i++) {
		current = Dizi[i];
		j = i;
		while (j > 0 && Dizi[j - 1] > current) {
			Dizi[j] = Dizi[j - 1];
			j--;
		}
		Dizi[j] = current;
	}
}


void fillArrayReverse(int *array, int size){
	for (int i = 0; i < size; ++i)
	{
		array[i] = size-i;
	}
}


int main(){

	const int size = 1000;
	int array[size];
	
	fillArrayReverse(array, size);
	clock_t start_selectionSort = clock();
	selectionSort(array, size);
	clock_t end_selectionSort = clock();

	
	fillArrayReverse(array,size);
	clock_t start_bubbleSort = clock();
	bubbleSort(array, size);
	clock_t end_bubbleSort = clock();

	fillArrayReverse(array, size);
	clock_t start_insertionSort = clock();
	insertionSort(array, size);
	clock_t end_insertionSort = clock();

	fillArrayReverse(array, size);
	clock_t start_binaryInsertionSort = clock();
	binaryInsertionSort(array, size);
	clock_t end_binaryInsertionSort = clock();


	fillArrayReverse(array, size);
	clock_t start_straightInsertionSort = clock();
	straightInsertionSort(array, size);
	clock_t end_straightInsertionSort = clock();

	
	
	printf("selectionSort : ");
	exeTime(start_selectionSort, end_selectionSort);
	
	printf("bubbleSort : ");
	exeTime(start_bubbleSort, end_bubbleSort);

	printf("insertionSort : ");
	exeTime(start_insertionSort, end_insertionSort);

	printf("binaryInsertionSort : ");
	exeTime(start_binaryInsertionSort, end_binaryInsertionSort);

	printf("straightInsertionSort : ");
	exeTime(start_straightInsertionSort, end_straightInsertionSort);

}