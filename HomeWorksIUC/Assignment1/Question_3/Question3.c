#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	int m_data;
	struct Node *m_right;
	struct Node *m_left;
}Node;



//TODO: fucnction to add a new node to the tree
Node* add(Node* root, int data){
	if(root == NULL){
		root = (Node*)malloc(sizeof(Node));
		root->m_data = data;
		root->m_left = root->m_right = NULL;
		return root;
	}

	if(root->m_data > data){
		root->m_left = add(root->m_left, data);
	}else{
		root->m_right = add(root->m_right, data);
	}
}


void traverse(Node* tree){
	if(tree == NULL) return;

	traverse(tree->m_left);
	printf("data : %d\n", tree->m_data);
	traverse(tree->m_right);
}


//Question3 :
int biggestData(Node* tree){
	Node* iter = tree;
	while(iter->m_right != NULL) iter = iter->m_right;
	return iter->m_data;
}


int main(){
	Node* tree = NULL;

	tree = add(tree, 100);
	tree = add(tree, 50);
	tree = add(tree, 70);
	tree = add(tree, 65);
	tree = add(tree, 68);
	tree = add(tree, 150);
	tree = add(tree, 200);
	tree = add(tree, 225);
	tree = add(tree, 250);

	traverse(tree);


	printf("biggest data on your tree : %d\n", biggestData(tree));
}