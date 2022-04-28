#include <stdio.h>
#include <stdlib.h>


typedef struct Queue{
	int m_front, m_rear, m_size;
	unsigned m_capacity;
	int* m_array;
}Queue;

//TODO: function to create a new Queue.
Queue* createQueue(unsigned capacity){
	Queue *q = (Queue*)malloc(sizeof(Queue));
	q->m_front = q->m_rear = q->m_size = 0;
	q->m_capacity = capacity;
	q->m_array = (int*)malloc(sizeof(int) * capacity);
	return q;
}


//TODO: function to add a node to the queue.
void enqueue(Queue* q, int data){
	//If we don't have enough space, nothing to do.
	if(q->m_rear == q->m_capacity) return;


	q->m_array[q->m_rear++] = data;
	q->m_size++;
}



//TODO: function to print the queue
void printQueue(Queue *q){
	//If our queue is empty, nothing to do.
	if(q->m_rear == 0) return;
	printf("\n");
	for(int i = q->m_front; i < q->m_rear; ++i){
		printf("number : %d\n", q->m_array[i]);
	}
}


int dequeu(Queue* q){
	//If we don't have any element in the queue.
	if(q->m_rear == 0) return INT_MIN;

	int keptData = q->m_array[q->m_front++];
	q->m_size--;
	return keptData;
}



int main(){
	Queue *ticketBox1 = createQueue(10);
	Queue *ticketBox2 = createQueue(10);
	Queue *ticketBox3 = createQueue(10);


	enqueue(ticketBox1, 1);
	enqueue(ticketBox1, 2);
	enqueue(ticketBox1, 3);
	enqueue(ticketBox1, 4);
	enqueue(ticketBox1, 5);
	printQueue(ticketBox1);

	printf("%d left from the ticket box\n", dequeu(ticketBox1));
	printf("%d left from the ticket box\n", dequeu(ticketBox1));
	printQueue(ticketBox1);
}