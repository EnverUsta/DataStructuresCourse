#include <stdio.h>
#include <stdlib.h>



typedef struct Queue{
	int m_rear, m_front;
	int m_capacity;
	int *m_array;
}Queue;


typedef struct Node{
	int m_data;
	struct Node* m_right, *m_left;
}Node;


Node* addData(Node* head, int data)
{
	if(head == NULL)
	{
		head = malloc(sizeof(Node));
		head->m_right = head->m_left = NULL;
		head->m_data = data;
		return head;
	}

	if(data < head->m_data)
		head->m_left = addData(head->m_left, data);
	else
		head->m_right = addData(head->m_right, data);
	return head;
	
}

Queue* createQueue(int capacity)
{
	Queue *q;
	q = malloc(sizeof(Queue));
	q->m_rear = q->m_front = 0;
	q->m_capacity = capacity;
	q->m_array = malloc(sizeof(int)*capacity);
	return q;
}


void enqueue(Queue *q, int data)
{
	q->m_array[q->m_rear++] = data;
}


int dequeue(Queue *q)
{
	int rValue = q->m_array[q->m_front++];
	return rValue;
}

void traverse(Node *head)
{
	if(head == NULL) return;
	traverse(head->m_left);
	printf("tree: %d\n", head->m_data);
	traverse(head->m_right);
}

void addQueueToTree(Queue *q, Node** head)
{
	int loopCount = q->m_rear;
	while(loopCount > 0)
	{
		*head = addData(*head, dequeue(q));
		loopCount--;
	}
}


int main()
{
	Queue *queue = createQueue(10);
	enqueue(queue, 5);
	enqueue(queue, 15);
	enqueue(queue, 25);

	Node* head = NULL;
	addQueueToTree(queue, &head);
	head = addData(head, 10);
	head = addData(head, 20);
	traverse(head);
	
}