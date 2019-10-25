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

//TODO: printing our linkedList recursively.
void printListRecursively(Node* head){
	printf("%d\n",head->m_data);
	printListRecursively(head->next);
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
	Node *next, *prev = NULL;
	Node *curr = *head_ref;
	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr; 
		curr = next;
	}
	(*head_ref) = prev;
}

//TODO: Function to do reverse our linkedList recursively.
Node* reverseRecursively(Node* head){ 
        if (head == NULL || head->next == NULL) return head; 
        /* reverse the rest list and put  
          the first element at the end */
        Node* rest = reverseRecursively(head->next); 
        head->next->next = head; 
  
        /* tricky step -- see the diagram */
        head->next = NULL; 
  
        /* fix the head pointer */
        return rest;
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


void mergeSort(Node** head_ref){
	
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
	head = reverseRecursively(head);
	printList(head);
	

}	