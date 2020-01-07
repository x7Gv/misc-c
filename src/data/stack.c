#include "stack.h"

void stack_init(stack *a, size_t member_size)
{
	a = (struct stack *) malloc(sizeof(struct stack));
	a->member_size = member_size;
	a->top = NULL;
}

int stack_is_full(stack *a)
{
	return a->top == NULL;
}

void stack_push(void *data);

void *stack_pop(stack *a);

void *stack_peek(stack *a);

unsigned stack_size(stack *a);