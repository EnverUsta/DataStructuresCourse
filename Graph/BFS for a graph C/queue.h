#ifndef QUEUE_H
#define QUEUE_H


typedef struct Node{
	int m_data;
	struct Node* m_next;
}Node;

Node* tail = NULL;

Node* createQueue()
{
	Node* head  = NULL;
	return head; 	
}

void enqueue(Node** head ,int data)
{
	if(*head == NULL)
	{
		(*head) = malloc(sizeof(Node*));
		(*head)->m_next = NULL;
		(*head)->m_data = data;
		tail = *head;
		return;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->m_data = data;
	newNode->m_next = tail->m_next;
	tail->m_next = newNode;
	tail = tail->m_next;
}

int dequeue(Node** head)
{
	Node* temp = *head;
	int rValue = temp->m_data;
	(*head) = (*head)->m_next;
	free(temp);
	return rValue;
}

int getFront(Node* head)
{
	return head->m_data;
}

int getRear()
{
	return tail->m_data;
}

int isEmpty(Node* head)
{
	if(head == NULL) return 1;
	return 0;
}



#endif