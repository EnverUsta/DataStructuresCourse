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

// Function to add an item to the queue.  
// It changes rear and size 
void enqueue(Queue *queue, int data){
	if(isFull(queue)) return;
	queue->rear = (queue->rear +1)%queue->capacity;
	queue->array[queue->rear] = data;
	queue->size++;
	printf("%d enqueued to queue\n", data); 
}

// Function to remove an item from queue.  
// It changes front and size 
int dequeue(Queue* queue){
	if(isEmpty(queue)) return INT_MIN;
	int rValue = queue->array[queue->front];
	queue->front = (queue->front + 1)%queue->capacity;
	queue->size--;
	return rValue;
}


// Function to get front of queue 
int front(Queue* queue) 
{ 
    if (isEmpty(queue)) return INT_MIN; 
    return queue->array[queue->front]; 
} 
  

// Function to get rear of queue 
int rear(Queue* queue) 
{ 
    if (isEmpty(queue)) return INT_MIN; 
    return queue->array[queue->rear]; 
} 


void printQueue(Queue *queue){
	if(isEmpty(queue)) return;
	printf("your queue: \n");
	for(int i = queue->front; i <= queue->rear; ++i){
		printf("%d\n", queue->array[i]);
	}
}



int main(){
	Queue *queue = createQueue(10);
	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);
	printf("%d dequeued from queue\n", dequeue(queue) );
	printQueue(queue);
}