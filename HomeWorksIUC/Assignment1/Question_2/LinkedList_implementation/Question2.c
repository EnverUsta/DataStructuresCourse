#include <stdio.h>
#include <stdlib.h>


typedef struct QNode{
	int m_data;
	struct QNode* m_next;
}QNode;


typedef	struct Queue{
	struct QNode* m_front, *m_rear;
}Queue;


//TODO: function to create a new queueu
Queue* createQueue(){
	Queue *q = (Queue*)malloc(sizeof(Queue));
	q->m_front = NULL;
	q->m_rear = NULL;
	return q;
}


//TODO: function to add a new node to our queue.
//We've used passing by address because we'll change q's itself.
void enqueue(Queue **q, int data){
	//If we don't have any node in the queue.
	if((*q)->m_front == NULL){
		(*q)->m_front = (QNode*)malloc(sizeof(QNode));
		(*q)->m_front->m_data = data;
		(*q)->m_front->m_next = NULL;
		(*q)->m_rear = (*q)->m_front;
		return;	
	}

	//else
	(*q)->m_rear->m_next = (QNode*)malloc(sizeof(QNode));
	(*q)->m_rear->m_next->m_data = data;
	(*q)->m_rear = (*q)->m_rear->m_next;
	(*q)->m_rear->m_next = NULL;

}


//TODO: function to remove the first Node of queue.
//We have to use pass by address here as well.However, if you want you may also use return by address.
//But i'll return int because when i remove a node, i'll return the data inside of the node.
int dequeue(Queue** q){
	//If we don't have any node in the queue, i want nothing to do.However opted to return an integer.
	//Therefore, i'm gonna use INT_MIN keyword here.
	if((*q)->m_front == NULL) return INT_MIN;

	QNode* temp = (*q)->m_front;

	//I'll keep my return value.
	int keptData = temp->m_data;
	(*q)->m_front = (*q)->m_front->m_next;
	free(temp);
	return keptData;
}


void printQueue(Queue *q){
	//if we don't have any node in the queue, nothing to do
	if(q == NULL) return;
	printf("\nNumbers in front of the queue :\n");
	QNode *iter = q->m_front;
	while(iter != NULL){
		printf("number : %d\n", iter->m_data);
		iter = iter->m_next;
	}
}


int main(){
	Queue *boxOffice1 = createQueue();
	Queue *boxOffice2 = createQueue();
	Queue *boxOffice3 = createQueue();

	enqueue(&boxOffice1, 1);
	enqueue(&boxOffice1, 2);
	enqueue(&boxOffice1, 3);
	enqueue(&boxOffice1, 4);
	enqueue(&boxOffice1, 5);
	printQueue(boxOffice1);
	printf("number '%d' left from the box office.\n", dequeue(&boxOffice1));
	printf("number '%d' left from the box office \n", dequeue(&boxOffice1));

	printQueue(boxOffice1);

	//We may also add some customers to other boxOffice as well.


}