#include <stdlib.h>
#include <stdio.h>

typedef struct Stack{
	int stack[20];
	int curr;
}Stack;



//TODO: pushing the integer to the last
void push(Stack *s, int data){
	s->stack[s->curr] = data;
	++s->curr;
}

//deleting the last value from the stack.
int pop(Stack *s){
	int rValue = s->stack[s->curr];
	s->stack[s->curr] = 0;
	--s->curr;
	return rValue;
}

//printing out stack
void printStack(Stack *s){
	if(s->curr == 0){
		printf("Your stack is empty\n");
		return;
	}
	for(int i = 0; i < s->curr; ++i){
		printf("%d ", s->stack[i]);
	}
	printf("\n");
}

int main(){
	Stack s;
	s.curr = 0;

	push(&s, 10);
	push(&s, 20);
	push(&s, 30);

	printStack(&s);
	pop(&s);
	printStack(&s);
	pop(&s);
	printStack(&s);
	pop(&s);
	printStack(&s);
	push(&s, 50);
	push(&s , 100);
	printStack(&s);

}