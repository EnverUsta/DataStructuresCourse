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

int SUM = 0;
void findSum(Node* head)
{
	if(head == NULL)return;
	findSum(head->m_left);
	SUM += head->m_data;
	findSum(head->m_right);
}

int COUNT = 0;
void findNodeNumber(Node* head)
{
	if(head == NULL)return;
	findNodeNumber(head->m_left);
	COUNT += 1;
	findNodeNumber(head->m_right);
}

int main()
{
	Node* head = NULL;
	head = addData(head, 10);
	head = addData(head, 20);
	head = addData(head, 30);
	head = addData(head, 40);

	traverse(head);
	findSum(head);
	findNodeNumber(head);

	
	printf("average: %d\n", SUM/COUNT);

}