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
	int *m_array;
}Stack;

typedef struct Queue{
	int m_rear;
	int m_front;
	int m_capacity;
	int *m_array;
}Queue;


Stack* createStack(int capacity)
{
	Stack *newStack = malloc(sizeof(Stack));
	newStack->m_capacity = capacity;
	newStack->m_array = malloc(sizeof(int)*capacity);
	newStack->m_top = -1;
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


void push(Stack *stack, int data)
{
	stack->m_array[++stack->m_top] = data;
}


int pop(Stack* stack)
{
	if(stack->m_top < 0)
		return INT_MIN;
	int rValue = stack->m_array[stack->m_top--];
	return rValue;
}

void printStack(Stack* stack)
{
	for(int i = 0; i <= stack->m_top; i++){
		printf("%d\n", stack->m_array[i]);
	}
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



int main(){
	TNode *head = NULL;
	Stack *stack = createStack(10);
	Queue *queue = createQueue(10);

	head = addTree(head, 10);
	head = addTree(head, 20);
	head = addTree(head, 30);
	head = addTree(head, 40);
	head = addTree(head, 50);
	addTreeToStack(head, stack);
	printStack(stack);

	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);
	enqueue(queue, 50);
	printf("%d\n", dequeue(queue));
	printf("%d\n", dequeue(queue));

}