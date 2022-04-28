#include <stdio.h>
#include <stdlib.h>

//Definition of Node struct
typedef struct Node{
	int m_data;
	struct Node* m_next;
}Node;



//function to add a new node to queue
//it keeps tail as well 
void enqueu(Node** head, int data, Node** tail){
	if(*head == NULL){
		*head = (Node*)malloc(sizeof(Node));
		(*head)->m_data = data;
		(*head)->m_next = NULL;
		*tail = *head;
		return;
	}
	Node* iter = *tail;
	iter->m_next = (Node*)malloc(sizeof(Node));
	iter->m_next->m_data = data;
	iter->m_next->m_next = NULL;
	*tail = iter->m_next;
}

//function to delete our first in node and return that value.
int dequeue(Node** head){
	Node *temp = *head;
	int rValue = temp->m_data;
	*head = (*head)->m_next;
	free(temp);
	return rValue;
}



//function to print our queue
void printQueue(Node* head){
	if(head == NULL) return;
	while(head != NULL){
		printf("your data: %d\n", head->m_data);
		head = head->m_next;	
	} 
}

int getFront(Node* head){
	return head->m_data;
}

int getRear(Node* tail){
	return tail->m_data;
}




int main(){
	Node* head = NULL;
	Node* tail = NULL;

	enqueu(&head, 10, &tail);
	enqueu(&head, 20, &tail);
	enqueu(&head, 30, &tail);
	enqueu(&head, 40, &tail);
	enqueu(&head, 50, &tail);
	printf("%d dequeued from the queue\n", dequeue(&head));
	printf("%d dequeued from the queue\n", dequeue(&head));
	enqueu(&head, 100, &tail);
	printQueue(head);

	printf("getFront => %d\n", getFront(head));
	printf("getRear => %d\n", getRear(tail));

}