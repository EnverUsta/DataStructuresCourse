#include <stdlib.h>
#include <stdio.h>

int *dizi = NULL;
int sira = 0, sirabasi = 0, boyut = 2;



//TODO: deque
int deque(){
	if(sirabasi == sira){
		printf("sira bos\n");
		return -1;
	}
	if(sira-sirabasi <= boyut/4){
		int *dizi2 = (int*)malloc(sizeof(int)*boyut/2);
		for(int i = 0; i < (sira-sirabasi); i++){
			dizi2[i] = dizi[i+sirabasi];
		}
		sira -= sirabasi;
		sirabasi = 0;
		free(dizi);
		boyut /= 2;
		dizi = dizi2;
	}
	return dizi[sirabasi++];
}


//TODO: toparla
void toparla(){
	if(sirabasi == 0) return;
	for(int i = 0; i < boyut; i++){
		dizi[i] = dizi[i+sirabasi];
	}
	sira -= sirabasi; 
	sirabasi = 0;
}

//TODO: enque
void enque(int data){
	if(dizi == NULL){
		dizi = (int*)malloc(sizeof(int)*boyut);
	}
	if(sira >= boyut){
		boyut *= 2;
		int* dizi2 = (int*)malloc(sizeof(int)*boyut);
		for(int i = 0; i < boyut/2; i++)
			dizi2[i] = dizi[i];
		free(dizi);
		dizi = dizi2;
	}
	dizi[sira++] = data;
}



int main(){
	for(int i = 0; i < 20; i++){
		enque(i*10);
	}
	for(int i = 0; i < 10; i++){
		printf("%d\n", deque());
	}
	for(int i = 0; i < 20; i++){
		enque(i*10);
	}
	for(int i = 0; i < 30; i++){
		printf("%d\n", deque());
	}
}