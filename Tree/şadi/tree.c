#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int m_data;
	struct Node *m_right;
	struct Node *m_left;
}Node;


//TODO: add
Node* add(Node* tree, int data){
	if(tree == NULL){
		tree = (Node*)malloc(sizeof(Node));
		tree->m_data = data;
		tree->m_right = NULL;
		tree->m_left = NULL;
		return tree;
	}
	if(data < tree->m_data){
		tree->m_left = add(tree->m_left, data);
		return tree;
	}
	tree->m_right = add(tree->m_right, data);
	return tree;
}


//TODO: traverse
void traverse(Node* tree){
	if(tree == NULL)return;
	traverse(tree->m_left);
	printf("%d\n", tree->m_data);
	traverse(tree->m_right);
}

//TODO: it returns the data if it can find in the tree
int find1(Node* tree, int data){
	if(tree == NULL)return -1;
	if(tree->m_data = data){
		return tree->m_data;	
	}
	find1(tree->m_left, data);
	find1(tree->m_right, data);
}

//TODO: it returns 1 if it can find in tree otherwise it returns 0
int find2(Node* tree, int data){
	if(tree == NULL) return -1;
	if(tree->m_data == data) return 1;
	if(find2(tree->m_right, data) == 1) return 1;
	if(find2(tree->m_left, data) == 1) return 1;
}

//TODO: it will return the smallest value in tree.
int findMinRecursively(Node* tree){
	if(tree->m_left == NULL)return tree->m_data;
	findMin(tree->m_left);
}

//TODO: it will return the biggest value in tree.
int findMaxREcursively(Node* tree){
	if(tree->m_right == NULL)return tree->m_data;
	findMax(tree->m_right);
}


int main(){
	Node* tree = NULL;
	add(tree, 10);
	tree = add(tree, 20);
	tree = add(tree, 30);
	tree = add(tree, 5);
	tree = add(tree, 45);
	tree = add(tree, 25);
	tree = add(tree, 40);
	tree = add(tree, 100);
	traverse(tree);
	printf("%d\n", find2(tree, 5));
	printf("Max value in tree: %d\n", findMinRecursively(tree));
	printf("Min value in tree: %d\n", findMaxREcursively(tree));
}