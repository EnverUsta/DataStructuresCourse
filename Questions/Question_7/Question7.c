#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	int m_data;
	struct Node* m_right, *m_left;	
}Node;



Node* add(Node* root, int data){
	if(root == NULL){
		root = (Node*)malloc(sizeof(Node));
		root->m_data = data;
		root->m_left = root->m_right = NULL;
		return root;
	}
	if(data < root->m_data){
		root->m_left = add(root->m_left, data);
	}else{
		root->m_right = add(root->m_right, data);
	}
}

void NumberOfBranches(Node* tree, int left, int right){
	if(tree == NULL)return;

	NumberOfBranches(tree->m_left, left++, right)


}



int main(){
	Node* tree = NULL;
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

	int x = 0;
	int y = 0;
	NumberOfBranches(tree, x, y);


}