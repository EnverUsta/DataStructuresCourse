#include <stdio.h>
#include <stdlib.h>



typedef struct TNode{
	int m_data;
	struct TNode *m_right, *m_left;
}TNode;


typedef struct LNode{
	int m_data;
	struct LNode* m_next;
}LNode;



TNode* add(TNode* tree, int data){
	if(tree == NULL){
		tree = (TNode*)malloc(sizeof(TNode));
		tree->m_data = data;
		tree->m_right = tree->m_left = NULL;
		return tree;
	}
	if(data < tree->m_data){
		tree->m_left = add(tree->m_left, data);
	}else{
		tree->m_right = add(tree->m_right, data);
	}
}

void traverse(TNode* tree){
	if(tree == NULL)return;

	traverse(tree->m_left);
	printf("data : %d\n", tree->m_data);
	traverse(tree->m_right);
}


LNode* addToLinkedList(TNode* tree){
	LNode* head = (LNode*)malloc(sizeof(LNode));
	head->m_next = NULL;

	addToLinkedList(tree->m_left);
	Node* iter = head;
	while(iter->m_next != NULL) iter = iter->m_next;

}


int main(){
	TNode *tree = NULL;
	tree = add(tree, 10);
	tree = add(tree, 100);
	tree = add(tree, 50);
	tree = add(tree, 70);
	tree = add(tree, 65);
	tree = add(tree, 68);
	tree = add(tree, 150);
	tree = add(tree, 200);
	tree = add(tree, 225);
	tree = add(tree, 250);


}