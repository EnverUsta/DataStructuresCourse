#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	int m_data;
	struct Node* m_right, *m_left;
}Node;


//TODO: function to add a new node to the tree.
Node* add(Node* root, int data){
	if(root == NULL){
		root = (Node*)malloc(sizeof(Node));
		root->m_data = data;
		root->m_right = root->m_left = NULL;
		return root;
	}
	if(data < root->m_data){
		root->m_left = add(root->m_left, data);
	}else{
		root->m_right = add(root->m_right, data);
	}
}


//TODO: function to merge two trees and returns a new tree.
Node* mergeTree(Node* tree1, Node* tree2){
	if(tree2 == NULL) return tree1;

	mergeTree(tree1, tree2->m_left);
	tree1 = add(tree1, tree2->m_data);
	mergeTree(tree1, tree2->m_right);
	return tree1;
	
}



//TODO: function to print our tree (LDR)
void traverse(Node* tree){
	if(tree == NULL) return;

	traverse(tree->m_left);
	printf("data : %d\n", tree->m_data);
	traverse(tree->m_right);
}




int main(){
	Node* tree1 = NULL;
	Node* tree2 = NULL;

	tree1 = add(tree1, 10);
	tree1 = add(tree1, 100);
	tree1 = add(tree1, 50);
	tree1 = add(tree1, 70);
	tree1 = add(tree1, 65);
	tree1 = add(tree1, 68);
	tree1 = add(tree1, 150);
	tree1 = add(tree1, 200);
	tree1 = add(tree1, 225);
	tree1 = add(tree1, 250);
	printf("tree1:\n");
	traverse(tree1);

	tree2 = add(tree2, 333);
	tree2 = add(tree2, 444);
	tree2 = add(tree2, 1);
	printf("tree2:\n");
	traverse(tree2);



	printf("\n");
	Node* tree3 = mergeTree(tree1, tree2);
	printf("Merged tree :\n");
	traverse(tree3);

}