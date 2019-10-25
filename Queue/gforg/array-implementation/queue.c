#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int *queue;
	int m_first;
	int m_curr;
	int m_capacity;
}Node;


Node* createQueue(int capacity){
	Node* node = (Node*)malloc(sizeof(Node));
	node->m_first = 0;
	node->m_curr = 0;
	node->m_capacity = capacity;
	node->queue = (int*)malloc(sizeof(int) * node->m_capacity);
	return node;
}


void enqueue(Node* node, int data){
	if(node == NULL)return;
	node->queue[node->m_curr++] = data;
}

int dequeue(Node* node){
	if(node == NULL) return -1;
	return node->queue[node->m_first++];
}


void printQueue(Node* node){
	printf("Your queue : \n");
	for(int i = node->m_first; i < node->m_curr; ++i){
		printf("%d\n",node->queue[i]);
	}
}

int getFront(Node* node){
	return node->queue[node->m_first];
}
int getRear(Node* node){
	return node->queue[node->m_curr-1];
}

int main(){
	Node* queue = createQueue(20);
	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);
	printQueue(queue);

	printf("degueue : %d\n", dequeue(queue));
	printf("degueue : %d\n", dequeue(queue));
	printQueue(queue);
}