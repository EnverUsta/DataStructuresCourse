#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int m_data;
	struct Node* m_next;
}Node;


//This function will add new data as a sorted.
Node* add(Node* head, int data){
	//If we don't have any node in our linkedList
	if(head == NULL){
		head = (Node*)malloc(sizeof(Node));
		head->m_data = data;
		head->m_next = NULL;
		return head;
	}

	//Adding to first place
	if(data < head->m_data){
		Node* temp = (Node*)malloc(sizeof(Node));
		temp->m_data = data;
		temp->m_next = head;
		head = temp;
		return head;
	}

	Node* iter = head;
	while(iter->m_next != NULL && iter->m_next->m_data <= data) iter = iter->m_next;
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->m_data = data;
	temp->m_next = iter->m_next;
	iter->m_next = temp;
	return head;
}


void printLinkedList(Node* head){
	printf("Your linked list: \n");
	while(head != NULL){
		printf("data : %d\n", head->m_data);
		head = head->m_next;
	}
}


//TODO: reverse linked list with iterative method.
void reverseLinkedList(Node** head){
	Node* next, *prev = NULL;
	Node* curr = *head;
	while(next != NULL){
		next = curr->m_next;
		curr->m_next = prev;
		prev = curr;
		curr = next;
	}
	(*head) = prev;
}

//TODO: reverse linked list with recursive method.
Node* reverseLinkedListRecursively(Node* head){
	if(head == NULL || head->m_next == NULL) return head;

	Node* rest = reverseLinkedListRecursively(head->m_next);
	head->m_next->m_next = head;

	head->m_next = NULL;

	return rest;
}


int main(){
	Node* head = NULL;

	head = add(head, 30);
	head = add(head, 10);
	head = add(head, 20);
	head = add(head, 50);
	head = add(head, 5);	

	printLinkedList(head);
	reverseLinkedList(&head);
	printLinkedList(head);
	head = reverseLinkedListRecursively(head);
	printLinkedList(head);
}