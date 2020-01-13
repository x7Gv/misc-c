#include "stack.h"
#include "stdio.h"

void stack_init(stack *a, size_t member_size, int max_size)
{
	a->size = 0;
	a->max_size = max_size;
	a->member_size = member_size;
	a->top = NULL;
}

int stack_is_full(stack *a)
{
	return (a->size < a->max_size) && (a->max_size != STACK_UNDEFINED_LIMIT);
}

int stack_push(stack *a, void *data)
{

	frame_t *frame = (frame_t *) malloc(a->member_size + a->member_size);
	frame->next = a->top;
	frame->data = (char *) data;

	a->top = frame;

	return STACK_OPERATION_SUCCESS;
}

void *stack_pop(stack *a)
{
	if (a->top == NULL) {
		return NULL;
	}

	frame_t *target = a->top;
	a->top = a->top->next;

	void *data = (void *) target->data;
	free(target->data);

	a->size--;

	return data;
}

void *stack_peek(stack *a)
{
	if (a->top == NULL) {
		return NULL;
	}

	return a->top->data;
}

unsigned stack_size(stack *a);