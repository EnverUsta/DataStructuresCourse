#include <stdio.h>
#include <stdlib.h>


//Definition of our QNode struct.
typedef struct QNode
{
	int m_data;
	struct QNode* m_next;	
}QNode;


//Definition of our Queue.
//It contains QNode front and QNode rear adresses.
typedef struct Queue
{
	QNode* front, *rear;
}Queue;


// A utility function to create a new linked list node.
QNode* newNode(int data){
	QNode* qNode = (QNode*)malloc(sizeof(QNode));
	qNode->m_data = data;
	qNode->m_next = NULL;
	return qNode;
}


//A utility function to create an empty queue.
Queue* createQueue(){
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->front = q->rear = NULL;
	return q;
}

//The function to add a data to queue.
void enqueue(Queue *q, int data){
	//Create a new node
	QNode* temp = newNode(data);

	//if q is empty
	if(q->rear == NULL){
		q->rear = q->front = temp;
		return;
	}

	//Add the new node at the end of queue and change rear
	q->rear->m_next = temp;
	q->rear = temp;
}

//function to delete the first node of queue (It's my solution).
int dequeueMy(Queue **q_ref){
	//if queue is empty
	if((*q_ref)->front == NULL)return INT_MIN;

	//We'll define a temp in order to delete first item of queue
	QNode* temp;
	temp = (*q_ref)->front;
	//store the data
	int rValue = temp->m_data;
	(*q_ref)->front = (*q_ref)->front->m_next;
	free(temp);

	// If front becomes NULL, then change rear also as NULL
	if((*q_ref)->front == NULL) (*q_ref)->rear = NULL;
	return rValue;
}


// Function to remove a key from given queue q
QNode* dequeueGeeks(Queue *q){
	//if queue is empty
	if(q->front == NULL) return q->front;

	//Store previous front and move front one node ahead
	QNode* temp = q->front;
	free(temp);

	q->front = q->front->m_next;

	//If front beccomes null, then change rear also as null
	if(q->front == NULL) q->rear = NULL;
	return temp;

}


void printQueue(Queue* q){
	if(q == NULL) return;
	QNode* iter = q->front;
	while(iter != NULL){
		printf("data: %d\n", iter->m_data);
		iter = iter->m_next;
	}
}



int main(){
	Queue *q = createQueue();
	enqueue(q, 10);
	enqueue(q, 20);
	enqueue(q, 30);
	printQueue(q);
	printf("After my dequeue function\n");
	dequeueMy(&q);
	printQueue(q);

	QNode* n = dequeueGeeks(q); 
    if (n != NULL) 
        printf("Dequeued item is %d\n", n->m_data); 
    printf("After Geeks dequeue function\n");
    printQueue(q);

}