#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	int m_data;
	struct Node* m_next;
}Node;



void push(Node** head, int data){
	//If stack is empty.
	if(*head == NULL){
		(*head) = (Node*)malloc(sizeof(Node));
		(*head)->m_data = data;
		(*head)->m_next = NULL;
		return; 
	}
	
	//if we add a node to stack.
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->m_data = data;
	temp->m_next = *head;
	*head = temp;
}


int pop(Node** head){
	//if the stack is empty return min int.
	if(*head == NULL){
		printf("You do not have any item yet.\n");
		return INT_MIN;	
	} 

	//else keep the data and remove it.
	Node* temp = *head;
	int rValue = temp->m_data;
	*head = (*head)->m_next;
	return rValue;
}

void printStack(Node* head){
	//if it is empty
	if(head == NULL){
		printf("You do not have any item in stack.\n");
		return;
	}
	//if we have some items in stack
	while(head != NULL){
		printf("data : %d\n", head->m_data);
		head = head->m_next;
	}

}


int main(){
	Node* head = NULL;
	int choice;
	do{
		printf("\nYou can choose what you want:\n1-push_back\n2-pop\n3-List\n(-1 for exit)\n");
		printf("What is your choice :");
		scanf("%d",&choice);
		switch(choice){
			case -1:
				printf("By By\n");
				break;
			case 1:
				printf("Please enter a data : ");
				int data;
				scanf("%d", &data);
				push(&head, data);
				break;
			case 2:
				printf("Popping ...\n");
				printf("Popped the data %d from the stack\n", pop(&head));
				break;
			case 3:
				printf("Your stack : \n");
				printStack(head);
				break;
			default:
				printf("Wrong choice!!!\n");
				break;
		}
	}while(choice != -1);
}