#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	int m_data;
	struct Node* m_next;	
}Node;


void addData(Node** head, int data)
{
	if(*head == NULL)
	{
		*head = malloc(sizeof(Node));
		(*head)->m_data = data;
		(*head)->m_next = NULL;
		return;
	}
	Node* iter = *head;
	while(iter->m_next != NULL) iter = iter->m_next;

	Node* temp = malloc(sizeof(Node));
	temp->m_data = data;
	temp->m_next = iter->m_next;
	iter->m_next = temp;
}


Node* reverseRecursively(Node* head)
{
	if(head == NULL || head->m_next == NULL) return head;

	Node* rest = reverseRecursively(head->m_next);
	head->m_next->m_next = head;

	head->m_next = NULL;

	return rest;
}

void printLinkedList(Node* head)
{
	if(head == NULL) return;

	while(head != NULL)
	{
		printf("linkedList: %d\n", head->m_data);
		head = head->m_next;
	}
}


int main()
{
	Node *head = NULL;
	addData(&head, 10);
	addData(&head, 20);
	addData(&head, 30);
	addData(&head, 40);
	addData(&head, 50);
	printLinkedList(head);
	printf("Reverse linkedList: \n");
	head = reverseRecursively(head);
	printLinkedList(head);
}