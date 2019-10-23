#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int m_data;
	struct Node* m_next;
}Node;


Node* root = NULL;
Node* tail = NULL;


void enque(int data){
	if(root == NULL){
		root = (Node*)malloc(sizeof(Node));
		root->m_data = data;
		root->m_next = NULL;
		tail = root;
		return;
	}
	tail->m_next = (Node*)malloc(sizeof(Node));
	tail->m_next->m_data = data;
	tail = tail->m_next;
	tail->m_next = NULL;
}

int deque(){
	if(root == NULL){
		printf("linked list bos");
		return -1;	
	}
	Node* temp = root;
	int rValue = temp->m_data;
	root = root->m_next;
	free(temp);
	return rValue;
}


int main(){
	enque(10);
	enque(20);
	enque(30);
	enque(40);
	enque(50);
	printf("%d\n", deque());
	printf("%d\n", deque());
	printf("%d\n", deque());
	printf("%d\n", deque());
	printf("%d\n", deque());
	printf("%d\n", deque());
}