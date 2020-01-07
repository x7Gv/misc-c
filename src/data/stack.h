#ifndef _STACK_H_
#define _STACK_H_

#include "stdlib.h"

typedef struct stack stack;

struct frame
{
	char *data;
	struct frame *next;
};

struct stack
{
	size_t member_size;
	unsigned size;
	struct frame *top;
};

void stack_init(stack *a, size_t member_size);

void stack_push(void *data);

void *stack_pop(stack *a);

void *stack_peek(stack *a);

unsigned stack_size(stack *a);

#endif
