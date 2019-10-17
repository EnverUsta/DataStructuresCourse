#include <stdlib.h>
#include <stdio.h>



//Definition of our struct
typedef struct Node{
	int m_data;
	struct Node* next;	
}Node;


//function to do return number of elements recursively.
int getCountRecursive(Node* head){
	if(head == NULL) return 0;
	return getCountRecursive(head->next) + 1;
}


//TODO: Pushing node to our linklist.
void pushNode(Node** head_ref, int data){
	//adding node to first place. 
	if((*head_ref) == NULL){
		(*head_ref) = (Node*)malloc(sizeof(Node));
		(*head_ref)->m_data = data;
		(*head_ref)->next = NULL;
	}
	else{
		Node* iter = *head_ref;
		while(iter->next != NULL)iter = iter->next;
		iter->next = (Node*)malloc(sizeof(Node));
		iter->next->m_data = data;
		iter->next->next = NULL;
	}
}


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

//TODO: Function to swap nodes x and y in linked list by changing links. 
void swapNodes(Node** head_ref, int x, int y){

	//Nothig to do if x and y are the same.
	if(x == y) return;

	//Search for x (keep track prevX and currX)
	Node* prevX = NULL, *currX = *head_ref;
	while(currX && currX->m_data != x){
		prevX = currX;
		currX = currX->next;
	}

	//Search for y (keep track prevY and currY)
	Node* prevY = NULL, *currY = *head_ref;
	while(currY && currY->m_data != y){
		prevY = currY;
		currY = currY->next;
	}

	//if either x or y is not present, nothing to do.
	if(currX == NULL || currY == NULL) return;

	//if x is not head of linkedlist
	if(prevX != NULL) prevX->next = currY;
	//if x is head of linkedlist, make y as new head.
	else{
		*head_ref = currY;
	}

	//if y is not head of linkedlist
	if(prevY != NULL) prevY->next = currX;
	//if y is head of linkedlist, make x as new head.
	else{
		*head_ref = currX;
	}

	//Swap next pointers.
	Node* temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;

}


//TODO: Function to do reverse our linkedList.
void reverseLinkedList(Node** head_ref){
	Node* next, *prev = NULL;
	Node* curr = *head_ref;
	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr; 
		curr = next;
	}
	(*head_ref) = prev;
}

Node* reverseRecursively(Node* head) 
    { 
        if (head == NULL || head->next == NULL) 
            return head; 
  
        /* reverse the rest list and put  
          the first element at the end */
        Node* rest = reverseRecursively(head->next); 
        head->next->next = head; 
  
        /* tricky step -- see the diagram */
        head->next = NULL; 
  
        /* fix the head pointer */
        return rest; 
    } 


int main(){
	Node* head = NULL;
	pushNode(&head, 10);
	pushNode(&head, 20);
	pushNode(&head, 30);
	pushNode(&head, 40);
	pushNode(&head, 50);
	pushNode(&head, 60);
	printList(head);
	printf("number of elements in your linkedList :%d\n", getCountRecursive(head));
	reverseLinkedList(&head);
	printList(head);
	head = reverseRecursively(head);
	printList(head);

}	