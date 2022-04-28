#include <stdlib.h>
#include <stdio.h>


//Pros: Easy to implement. Memory is saved as pointers are not involved.
//Cons: It is not dynamic. It doesn’t grow and shrink depending on needs at runtime.


typedef struct Stack{
	int top;
	unsigned capacity;
	int *array;
}Stack;


int isFull(Stack *s){
	return s->top == s->capacity -1;
}

int isEmpty(Stack *s){
	return s->top == -1;
}


//TODO: push
void push(Stack *s, int data){
	if(isFull(s)) return;
	s->array[++s->top] = data;
	printf("%d pushed to stack\n", data);
}

//TODO: pop
int pop(Stack *s){
	if(isEmpty(s)) return INT_MIN;
	return s->array[s->top--];
}


//TODO: creating a stack
Stack* createStack(unsigned capacity){
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->capacity = capacity;
	s->top = -1;
	s->array = (int*)malloc(sizeof(int)*s->capacity);	
	return s;
}

	

void printStack(Stack s){
	int count = 0;
	while(count != s.top + 1){
		printf("%d ", s.array[count]);
		++count;
	}
}

int main() 
{ 
    struct Stack* stack = createStack(100); 
  
    push(stack, 10); 
    push(stack, 20); 
    push(stack, 30); 
    push(stack, 40);
  
    printf("%d popped from stack\n", pop(stack));

    printStack(*stack);

    return 0; 
} 