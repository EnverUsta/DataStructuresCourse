#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Queue{
	int front, rear, size;
	unsigned capacity;
	int *array;
}Queue;


Queue* createQueue(unsigned capacity){
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity-1;			// This is important, see the enqueue
	queue->array = (int*)malloc(sizeof(int) * queue->capacity);
	return queue;
}


int isFull(Queue *queue){
	return (queue->size == queue->capacity);
}

int isEmpty(Queue *queue){
	return (queue->size == 0);
}

void enqueue(Queue *queue, int data){
	if(isFull(queue)) return;
	queue->rear = (queue->rear +1)%queue->capacity;
	queue->array[queue->rear] = data;
	queue->size++;
	printf("%d enqueued to queue", data); 
}

int main(){

}