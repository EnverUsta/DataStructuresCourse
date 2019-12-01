#include <stdio.h>
#include <stdlib.h>



/*
	README:
		input format(example):
		There should be a '\n'(newline) between first and second matrices.
		There should be spaces(just one space) between all numbers.

		1 2 3 4
		5 6 7 8
		9 10 11 12
		13 14 15 16
		
		1 2 3 4
		5 6 7 8
		9 10 11 12
		13 14 15 16
*/



//TODO: function to multiply two arrays and find result.
void multiply(int *array1, int *array2, int n, int *arrayResult);


//TODO: function to read matrices and get them as arrays.
//I've coded an alternative method in order to read matrices.
//readMatrices and readMatrices2 we may use both of them.
//I've preferred to use second one.
//First one is to read matrices character by character.
//In second one i used fscanf() in order to get numbers.  
void readMatrices(int *array1, int *array2, int n);
void readMatrices2(int *array1, int *array2, int n);

//TODO:function to find the size of the matrices.
int sizeOfMatrices();

//TODO: function to write our result to sonuc.txt.
void writeResult(int *arrayResult, int n);




int main(){
	
	int n = sizeOfMatrices();							//We'll have n*n matrices. We found the n right now.
	int *array1 = (int*)malloc(sizeof(int)*n*n);
	int *array2 = (int*)malloc(sizeof(int)*n*n);
	int *arrayResult = (int*)malloc(sizeof(int)*n*n);

	readMatrices2(array1, array2, n);					//We've read our matrices from matrisler.txt file.
	multiply(array1, array2, n, arrayResult);
	writeResult(arrayResult, n);

	free(array1);
	free(array2);
	free(arrayResult);
	
}


void writeResult(int *arrayResult, int n){
	FILE *fp = fopen("sonuc.txt", "w");
	int sizeOfTheArray = n*n;
	int  i = 0;
	while(i != sizeOfTheArray){
		fprintf(fp, "%d ", arrayResult[i]);
		if((i+1)%(n) == 0) fputc('\n', fp);
		i++;
	}
	fclose(fp);
}



void multiply(int *array1, int *array2, int n, int *arrayResult){
	int sizeOfTheArray = n*n;
	int arrayResultCount = 0;
		int i = 0;
		int j = 0;
		int result = 0;
		int changeI = 0;
		while(arrayResultCount != sizeOfTheArray)
		{
			result += array1[i]*array2[j];
			j+=n;
			i++;
			if(j > (sizeOfTheArray-1)) {
				arrayResult[arrayResultCount++] = result;
				//printf("%d\n", result);
				j = j%(sizeOfTheArray-1);
				i -= n;
				result = 0;
				changeI++;
				if(changeI%n == 0) {
					i += n;
					j = 0;
				}	
			}
		}	
}


int sizeOfMatrices(){
	FILE *fp = fopen("matrisler.txt", "r");
	char ch;
	int n = 1;											//we have n*n matrices.Therefore, we'll find the n.
	while((ch = fgetc(fp)) != '\n'){
		if(ch == ' ') n++;
		else	continue;
	}
	fclose(fp);
	return n;
}

void readMatrices(int *array1, int *array2, int n){
	FILE *fp = fopen("matrisler.txt", "r");

	int countArray1 = 0;
	int countArray2 = 0;
	
	char ch;
	char temp;
	int number = 0;
	int whichArray = 1;
	while((ch = fgetc(fp)) != EOF){
		if((ch == ' ' || ch == '\n') && (temp != ' ')){
			if(temp == '\n' && ch == '\n'){
				whichArray = 2;							//We realized that we'll read the second array
				continue;
			}
			if(whichArray == 1){
				array1[countArray1++] = number;
			}
			else if(whichArray == 2){
				array2[countArray2++] = number;
			}
			number = 0;
		}
		else{
			if(ch == '\n') continue;
			number = (number*10) + (ch - '0');
		}
		temp = ch;
	}
	if(ch == EOF){
		array2[countArray2] = number;					//In order to read last number of the array2.
	}
	fclose(fp);
}


void readMatrices2(int *array1, int *array2, int n){
	FILE *fp = fopen("matrisler.txt", "r");
	int sizeOfMatrices = n*n;
	printf("%s\n", "icine girdi.");
	int countArray1 = 0;
	int countArray2 = 0;

	for (int i = 0; i < sizeOfMatrices; ++i)
	{
		int number;
		fscanf(fp, "%d", &number);
		printf("%d\n", number);
		array1[countArray1++] = number;
	}

	for (int i = 0; i < sizeOfMatrices; ++i)
	{
		int number;
		fscanf(fp, "%d", &number);
		printf("%d\n", number);
		array2[countArray2++] = number;
	}
	fclose(fp);
}