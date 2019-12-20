#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct Node{
	char m_data;
	struct Node* m_next;
}Node;


//TODO: function to add a new data to linkedlist as a sorted.
Node* push(Node* head, char data){
	//It can be null
	if(head == NULL){
		head = (Node*)malloc(sizeof(Node));
		head->m_data = data;
		head->m_next = NULL;
		return head;
	}

	//data can be less than first node
	if(data < head->m_data){
		Node* temp = (Node*)malloc(sizeof(Node));
		temp->m_data = data;
		temp->m_next = head;
		head = temp;
		return head;
	}

	Node* iter = head;
	//except two situations in the above, we may add new data easily :)
	while(iter->m_next != NULL && data > iter->m_next->m_data) iter = iter->m_next;

	Node* temp = (Node*)malloc(sizeof(Node));
	temp->m_data = data;
	temp->m_next = iter->m_next;
	iter->m_next = temp;
	return head;

}



void moveNode(Node** destRef, Node** sourceRef){
	
	Node* newNode = *sourceRef;
	assert(newNode != NULL);

	*sourceRef = newNode->m_next;

	newNode->m_next = *destRef;

	*destRef = newNode;

}
Node* sortedMerge2(Node* a, Node* b){
	Node dummy;
	Node* tail = &dummy;

	dummy.m_next = NULL;

	while(1){
		if(a == NULL){
			tail->m_next = b;
			break;
		}
		else if(b == NULL){
			tail->m_next = a;
			break;
		}

		if(a->m_data <= b->m_data)
			moveNode(&(tail->m_next), &a);
		else
			moveNode(&(tail->m_next), &b);

		tail = tail->m_next;
	}
	return dummy.m_next;
}



	
void print(Node* head){
	while(head != NULL){
		printf("data: %c\n", head->m_data);
		head = head->m_next;
	}
}


Node* sortedMerge(Node* head1, Node* head2){

	Node* result = NULL;

	//Base cases:
	if(head1 == NULL) return head2;
	if(head2 == NULL) return head1;

	//Pick either a or b and recur
	if(head1->m_data <= head2->m_data){
		result = head1;
		head1->m_next = sortedMerge(head1->m_next, head2); 
	}
	else{
		result = head2;
		head2->m_next = sortedMerge(head1, head2->m_next);
	}
	return result;

}


int main(){

	Node* head1 = NULL;
	head1 = push(head1, 'A');
	head1 = push(head1, 'B');
	head1 = push(head1, 'D');
	head1 = push(head1, 'C');
	head1 = push(head1, 'F');
	head1 = push(head1, 'E');

	Node* head2 = NULL;
	head2 = push(head2, 'G');
	head2 = push(head2, 'H');
	head2 = push(head2, 'I');
	head2 = push(head2, 'J');
	head2 = push(head2, 'K');
	head2 = push(head2, 'L');
	

	Node* head3 = sortedMerge2(head1, head2);
	print(head3);

}