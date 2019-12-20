#include <stdio.h>
#include <stdlib.h>


typedef struct LNode{
	int m_data;
	struct LNode* m_next;
}LNode;


typedef struct TNode{
	int m_data;
	struct TNode* m_right, *m_left;
}TNode;



void addSorted(LNode** head, int data){
	if(*head == NULL){
		*head = (LNode*)malloc(sizeof(LNode));
		(*head)->m_data = data;
		(*head)->m_next = NULL;
		return;
	}
	if(data < (*head)->m_data){
		LNode* temp = (LNode*)malloc(sizeof(LNode));
		temp->m_data = data;
		temp->m_next = (*head);
		*head = temp;
		return;
	}
	LNode* iter = *head;
	while(iter->m_next != NULL && data > iter->m_next->m_data) iter = iter->m_next;
	LNode* temp = (LNode*)malloc(sizeof(LNode));
	temp->m_data = data;
	temp->m_next = iter->m_next;
	iter->m_next = temp;
}


void printLinkedList(LNode* head){
	if(head == NULL){printf("you do not have any node :(\n");return;}
	printf("Your linked list:\n");
	while(head != NULL){
	 	printf("data : %d\n",head->m_data );
		head = head->m_next;
	}

}



TNode* addTree(TNode* root, int data){
	if(root == NULL){
		root = (TNode*)malloc(sizeof(TNode));
		root->m_data = data;
		root->m_left = root->m_right = NULL;
		return root;
	}

	if(data < root->m_data){
		root->m_left = addTree(root->m_left, data);
	}else{
		root->m_right = addTree(root->m_right, data);
	}
	return root;
}

void traverse(TNode* root){
	if(root == NULL) return;

	traverse(root->m_left);
	printf("data: %d\n", root->m_data);
	traverse(root->m_right);
}


void addToLinkedList(TNode* root, LNode** head){
	if(root == NULL)return;
	addToLinkedList(root->m_left, head);
	addSorted(&head, root->m_data);
	addToLinkedList(root->m_right, head);
}

int left = 0;
int right = 0;

void getBranchNumber(TNode* root){
	if(root == NULL)return;
	if(root->m_left != NULL){
		left++;
		getBranchNumber(root->m_left);
	}
	if(root->m_right != NULL){
		right++;
		getBranchNumber(root->m_right);
	}
}





int main(){
	LNode* head = NULL;
	TNode* root = NULL;
	LNode* head2 = NULL;


	addSorted(&head, 10);
	addSorted(&head, 20);
	addSorted(&head, 30);
	addSorted(&head, 40);
	addSorted(&head, 50);

	root = addTree(root, 10);
	root = addTree(root, 20);
	root = addTree(root, 15);
	root = addTree(root, 5);
	root = addTree(root, 3);
	root = addTree(root, 2);
	root = addTree(root, 13);
	root = addTree(root, 12);
	
	addToLinkedList(root, &head2);


	getBranchNumber(root);
	printf("left : %d\n", left );
	printf("right : %d\n", right );

}