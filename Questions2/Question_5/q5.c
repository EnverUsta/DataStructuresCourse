#include <stdio.h>
#include <stdlib.h>


typedef struct TNode{
	int m_data;
	struct TNode *m_right;
	struct TNode *m_left;
}TNode;


typedef struct Stack{
	int m_top;
	int m_capacity;
	int m_size;
	int *m_array;
}Stack;

typedef struct Queue{
	int m_rear;
	int m_front;
	int m_capacity;
	int *m_array;
}Queue;

typedef struct LNode{
	int m_data;
	struct LNode* m_next;
}LNode;


void addData(LNode** head, int data)
{
	if(*head == NULL)
	{
		*head = (LNode*)malloc(sizeof(LNode));
		(*head)->m_next = NULL;
		(*head)->m_data = data;
		return; 
	}
	LNode* iter = *head; 
	while(iter->m_next != NULL) iter = iter->m_next;
	LNode* temp = malloc(sizeof(LNode));
	temp->m_data = data;
	temp->m_next = iter->m_next;
	iter->m_next = temp;
}


void printLinkedList(LNode* head)
{
	if(head == NULL)return;
	while(head != NULL)
	{
		printf("linkedList: %d\n", head->m_data);
		head = head->m_next;
	}
	printf("\n");
}


Stack* createStack(int capacity)
{
	Stack *newStack = malloc(sizeof(Stack));
	newStack->m_capacity = capacity;
	newStack->m_array = malloc(sizeof(int)*capacity);
	newStack->m_top = -1;
	newStack->m_size = 0;
	return newStack;
}


Queue* createQueue(int capacity)
{
	Queue *newQueue = malloc(sizeof(Queue));
	newQueue->m_capacity = capacity;
	newQueue->m_array = malloc(sizeof(int)*capacity);
	newQueue->m_front = 0;
	newQueue->m_rear = -1;
}


void enqueue(Queue *queue, int data)
{
	if(queue->m_rear >= queue->m_capacity)	queue->m_rear = queue->m_rear % queue->m_capacity;
	queue->m_array[++queue->m_rear] = data; 
}

int dequeue(Queue *queue)
{
	int rValue;
	if(queue->m_rear == -1)
	{
		return INT_MIN;
	}
	rValue = queue->m_array[queue->m_front++];
	return rValue;
}

void printQueue(Queue *queue)
{
	for(int i = queue->m_front; i <= queue->m_rear; i++){
		printf("queue : %d\n", queue->m_array[i]);
	}
	printf("\n");
}


void push(Stack *stack, int data)
{
	stack->m_array[++stack->m_top] = data;
	stack->m_size++;
}


int pop(Stack* stack)
{
	if(stack->m_top < 0)
		return INT_MIN;
	int rValue = stack->m_array[stack->m_top--];
	stack->m_size--;
	return rValue;
}

void printStack(Stack* stack)
{
	for(int i = 0; i <= stack->m_top; i++){
		printf("stack: %d\n", stack->m_array[i]);
	}
	printf("\n");
}


TNode* addTree(TNode *tNode, int data)
{
	if(tNode == NULL)
	{
		tNode = malloc(sizeof(TNode));
		tNode->m_data = data;
		tNode->m_right = tNode->m_left = NULL;
		return tNode;
	}

	if(data < tNode->m_data)
	{
		tNode->m_left = addTree(tNode->m_left, data);
		return tNode;
	}
	tNode->m_right = addTree(tNode->m_right, data);
	return tNode;
}

void printTree(TNode* head)
{
	if(head == NULL) return;

	printTree(head->m_left);
	printf("%d\n", head->m_data);
	printTree(head->m_right);
}

void addTreeToStack(TNode* head, Stack* stack)
{
	if(head == NULL) return;

	addTreeToStack(head->m_left, stack);
	push(stack, head->m_data);
	addTreeToStack(head->m_right, stack);
}

void addTreeToQueue(TNode* head, Queue *queue)
{
	if(head == NULL) return;
	addTreeToQueue(head->m_left, queue);
	enqueue(queue, head->m_data);
	addTreeToQueue(head->m_right, queue);
}

void addTreeToLinkedList(TNode* head, LNode* headL)
{
	if(head == NULL) return;
	addTreeToLinkedList(head->m_left, headL);
	addData(&headL, head->m_data);
	addTreeToLinkedList(head->m_right, headL);
}

void stackToQueue(Stack* stack, Queue *queue)
{

}

void stackToLinkedList(Stack *stack, LNode* head)
{
	for(int i = 0; i < stack->m_size; i++)
	{
		addData(&head, stack->m_array[i]);	
	}
}

int main(){
	TNode *head = NULL;
	LNode *headL = NULL;
	Stack *stack = createStack(10);
	Queue *queue = createQueue(10);


	push(stack, 1);
	head = addTree(head, 10);
	head = addTree(head, 20);
	head = addTree(head, 30);
	head = addTree(head, 40);
	head = addTree(head, 50);
	printf("Before: \n");
	printStack(stack);
	addTreeToStack(head, stack);
	printf("After: \n");
	printStack(stack);

	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);
	enqueue(queue, 50);
	printf("Before: \n");
	printQueue(queue);

	addTreeToQueue(head, queue);
	printf("After: \n");
	printQueue(queue);

	addData(&headL, 5);
	addData(&headL, 10);
	addData(&headL, 15);
	addData(&headL, 20);
	addData(&headL, 25);
	addData(&headL, 30);
	printf("Before: \n");
	printLinkedList(headL);
	addTreeToLinkedList(head, headL);
	printf("After: \n");
	printLinkedList(headL);

	printf("After the stackToLinkedList():\n");
	stackToLinkedList(stack, headL);
	printLinkedList(headL);

}