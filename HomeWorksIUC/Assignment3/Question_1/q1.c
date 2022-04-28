#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	int m_data;
	struct Node* next;
}Node;


//TODO: printing our linkedList.
void printList(Node* head){
	printf("Your singlyLinkedList:\n");
	if(head == NULL){
		printf("you do not have any node.\n");
	}else{
		while(head != NULL){
			printf("%d\n",head->m_data);
			head = head->next;
		}

	}
}

void pushNode(Node** head, int data){
	if(*head == NULL){
		*head = (Node*)malloc(sizeof(Node));
		(*head)->m_data = data,
		(*head)->next = NULL;
		return;
	}
	Node* iter = *head;
	while(iter->next != NULL) iter = iter->next;
	iter->next = (Node*)malloc(sizeof(Node));
	iter->next->m_data = data;
	iter->next->next = NULL;
}


//TODO: Merging two sorted linkedList.
Node* sortedMerge(Node* head1, Node* head2){
	//if head_ref is equal to NULL, nothing to do.
	Node* iter = head1;
	if(iter == NULL || head2 == NULL) return iter;
	while(head2 != NULL){
		Node* dummy = (Node*)malloc(sizeof(Node));
		dummy->m_data = head2->m_data;

		while(iter->next != NULL && iter->next->m_data <= dummy->m_data){
			iter = iter->next;
		}
		//if data that we'll add is smaller than our first node
		//We've used head1 instead of iter because we're changing our first node.
		if(dummy->m_data <= iter->m_data){
			dummy->next	= head1;
			head1 = dummy;
		}
		//Adding to between nodes or to last node.
		else{
			dummy->next	= iter->next;
			iter->next = dummy;	
		}
		head2 = head2->next;
	}
	return head1;
}

//TODO: merging 2 sorted linkedList.
Node* sortedMergeRecursively(Node* a, Node* b){
	Node* result = NULL;

	//our exits for recursive function.
	if(a == NULL) return b;
	else if(b == NULL) return a;

	//We'll choose smaller one and assign it to result.
	if(a->m_data <= b->m_data){
		result = a;
		result->next = sortedMergeRecursively(a->next, b);
	}
	else{
		result = b;
		result->next = sortedMergeRecursively(a, b->next);
	}
	return result;
}

int main(){

	Node* head1 = NULL;
	Node* head2 = NULL;
	pushNode(&head1, 10);
	pushNode(&head1, 20);
	pushNode(&head1, 30);
	pushNode(&head1, 40);
	pushNode(&head1, 50);
	pushNode(&head1, 60);

	pushNode(&head2, 11);
	pushNode(&head2, 21);
	pushNode(&head2, 31);
	pushNode(&head2, 41);
	pushNode(&head2, 51);
	pushNode(&head2, 61);
	printList(head1);
	printList(head2);

	head1 = sortedMerge(head1, head2);
	printList(head1);
}