#include <stdio.h>
#include <stdlib.h>


typedef struct Stack{
	int m_rear;
	unsigned m_capacity;
	int* array;
}Stack;


typedef struct Node{
	int m_data;
	struct Node* m_next;
}Node;


Stack* createStack(unsigned capacity){
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->m_rear = 0;
	s->m_capacity = capacity;
	s->array = (int*)malloc(sizeof(int) * capacity);
	return s;
}


void push(Stack *s, int data){
	if(s->m_rear >= s->m_capacity)return;

	s->array[s->m_rear++] = data;
}


Node* addToLinkedList(Stack* s, Node* n){
	if(n == NULL){
		n = (Node*)malloc(sizeof(Node));
		n->m_data = s->array[--s->m_rear];
		n->m_next = NULL; 
	}
	Node* iter = n;
	for(int i = s->m_rear-1; i >= 0; i--){
		while(iter->m_next != NULL) iter = iter->m_next;
		iter->m_next = (Node*)malloc(sizeof(Node));
		iter->m_next->m_next = NULL;
		iter->m_next->m_data = s->array[i];
	}
	return n;
}


void printLinkedList(Node* head){
	while(head != NULL) {
		printf("data : %d\n", head->m_data);
		head = head->m_next;
	}
}

int main(){
	Node* head = NULL;
	Stack* s  = createStack(10);
	push(s, 10);
	push(s, 20);
	push(s, 30);
	push(s, 40);
	push(s, 50);
	push(s, 60);
	push(s, 70);
	push(s, 80);
	push(s, 90);
	push(s, 100);

	head = addToLinkedList(s, head);
	printLinkedList(head);
}