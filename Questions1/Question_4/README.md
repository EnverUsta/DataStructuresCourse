**ITERATIVE METHOD**

```
void reverseLinkedList(Node** head){
	Node* next, *prev = NULL;
	Node* curr = *head;
	while(next != NULL){
		next = curr->m_next;
		curr->m_next = prev;
		prev = curr;
		curr = next;
	}
	(*head) = prev;
}
```
</br></br>
**RECURSIVE METHOD**

```

Node* reverseLinkedListRecursively(Node* head){

	if(head == NULL || head->m_next == NULL) return head;
  
	Node* rest = reverseLinkedListRecursively(head->m_next);
  
	head->m_next->m_next = head;
  
	head->m_next = NULL;
  
	return rest;
}
