#include <stdio.h>
#include <stdlib.h>



typedef struct Stack{
	int m_capacity, m_size;
	int m_top;
	int* m_array;
}Stack;


Stack* createStack(int capacity)
{
	Stack *stack = malloc(sizeof(Stack));
	stack->m_capacity = capacity;
	stack->m_size = 0;
	stack->m_top = -1;
	stack->m_array = malloc(sizeof(int)*capacity);
	return stack;
}


void push(Stack *stack, int data)
{
	stack->m_array[++stack->m_top] = data;
	stack->m_size++;
}

int pop(Stack* stack)
{
	int rValue =stack->m_array[stack->m_top--];
	stack->m_size--;
	return rValue;
}

int findMax(Stack *stack)
{
	if(stack == NULL || stack->m_array == NULL) return -1;

	int maxValue = pop(stack);
	for(int i = 0; i < stack->m_size; ++i)
	{
		int keep = pop(stack);
		if(keep > maxValue) maxValue = keep;
	}
	return maxValue;
}

int findMin(Stack *stack)
{
	if(stack == NULL || stack->m_array == NULL) return -1;

	int minValue = pop(stack);
	for(int i = 0; i < stack->m_size-1; ++i)
	{
		int keep = pop(stack);
		if(keep < minValue)
			minValue = keep;
	}
	return minValue;
}

int main()
{
	Stack *stack = createStack(10);
	push(stack, 5);
	push(stack, 10);
	push(stack, 15);
	push(stack, 20);

	printf("%d\n", findMax(stack));
	printf("%d\n", findMin(stack));
}