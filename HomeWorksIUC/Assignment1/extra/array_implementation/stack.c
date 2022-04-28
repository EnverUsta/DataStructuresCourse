#include <stdio.h>
#include <stdlib.h>

//Definition of stack
typedef struct Stack
{
	int m_rear, m_capacity;
	int *m_array;
}Stack;


int isEmpty(Stack *stack){
	return (stack->m_rear == 0);
}

int isFull(Stack *stack){
	return (stack->m_capacity == stack->m_rear);
}


//function to create a new stack.
Stack* createStack(int capacity){
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->m_array = (int*)malloc(sizeof(int)* capacity);
	stack->m_rear = 0;
	stack->m_capacity = capacity;
	return stack;
}


void push(Stack **stack_ref, int data){
	//if we do not have enough storage for new data.
	if(isFull(*stack_ref)){
		printf("Actually, your stack is full.\n");
		printf("However, we'll enhance your capacity (2x)\n");
		printf("Give us a few seconds ...\n");
		printf("Your new capacity is : %d\n", (*stack_ref)->m_capacity*2);
		Stack* temp = (Stack*)malloc(sizeof(Stack));
		temp->m_array = (int*)malloc(sizeof(int) * ((*stack_ref)->m_capacity*2));
		temp->m_capacity = (*stack_ref)->m_capacity*2;
		temp->m_rear = (*stack_ref)->m_rear;

		for(int i = 0; i < (*stack_ref)->m_capacity; i++){
			temp->m_array[i] = (*stack_ref)->m_array[i];
		}
		printf("pushed : %d\n", data);
		temp->m_array[temp->m_rear++] = data;
		*stack_ref = temp;
		return;
	}
	//if we have enough storage, we'll add the data to back of stack.
	printf("pushed : %d\n", data);
	(*stack_ref)->m_array[(*stack_ref)->m_rear++] = data;
}

int pop(Stack *stack){
	//if we do not have any item in stack, nothing to do.
	//However, we have to return a value, therefore we'll return INT_MIN.
	if(isEmpty(stack)) return INT_MIN;
	//If we have some items
	int rValue = stack->m_array[stack->m_rear-1];
	stack->m_array[stack->m_rear--];
	return rValue;
}

void printStack(Stack* stack){
	printf("Your stack is: \n");
	for(int i = 0; i < stack->m_rear; ++i){
		printf("your data : %d\n", stack->m_array[i]);
	}
}



int main(){

	Stack* stack = createStack(5);
	int choice;
	do{
		printf("\nYou can choose what you want:\n1-push_back\n2-pop\n3-List\n(-1 for exit)\n");
		printf("What is your choice :");
		scanf("%d",&choice);
		switch(choice){
			case -1:
				printf("By By\n");
				break;
			case 1:
				printf("Please enter a data : ");
				int data;
				scanf("%d", &data);
				push(&stack, data);
				break;
			case 2:
				if(isEmpty(stack)){
					printf("You do not have any item in stack!!!");
					break;
				} 
				printf("Popping ...\n");
				printf("Popped the data %d from the stack\n", pop(stack));
				break;
			case 3:
				printStack(stack);
				break;
			default:
				printf("Wrong choice!!!\n");
				break;
		}
	}while(choice != -1);
}