#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	int m_data;
	struct Node* m_left, *m_right;
}Node;


Node* addData(Node* head, int data)
{
	if(head == NULL)
	{
		head = (Node*)malloc(sizeof(Node));
		head->m_data = data;
		head->m_right = NULL;
		head->m_left = NULL;
		return head;
	}
	if(data < head->m_data){
		head->m_left = addData(head->m_left, data);
		return head;
	}
	head->m_right = addData(head->m_right, data);
	return head;
	
}

void traverse(Node* head)
{
	if(head == NULL) return;
	traverse(head->m_left);
	printf("%d\n", head->m_data);
	traverse(head->m_right);
}

int COUNT = 0;
void findRightCount(Node* head)
{
	if(head == NULL) return;
	findRightCount(head->m_left);
	COUNT += 1;
	findRightCount(head->m_right);
}

int main()
{
	Node* tree = NULL;
	tree = addData(tree, 5);
	tree = addData(tree, 35);
	tree = addData(tree, 15);
	tree = addData(tree, 3);
	tree = addData(tree, 4);
	findRightCount(tree->m_right);
	printf("%d\n", COUNT);
	
	
}