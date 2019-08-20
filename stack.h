#ifndef _STACK_H_
#define _STACK_H_

struct frame
{
	void *data;
	struct frame *next;
};

struct stack
{
	int size;
	struct frame *top;
};

void stack_init(struct stack *ref);

void stack_push(void *data);

void stack_pop(void *dest);

#endif