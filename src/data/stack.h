#ifndef _STACK_H_
#define _STACK_H_

#include "stdlib.h"

#define STACK_UNDEFINED_LIMIT -1

#define STACK_OPERATION_SUCCESS 0;

#define STACK_EXCEPTION_OVERFLOW -2
#define STACK_EXCEPTION_UNDERFLOW -3

typedef struct stack stack;
typedef struct frame_t frame_t;

struct frame_t
{
	char *data;
	frame_t *next;
};

struct stack
{
	size_t member_size;
	int max_size;
	unsigned int size;

	frame_t *top;
};

/**
 * @brief      Initialize stack
 *
 * @param      a            Stack ref to initialize.
 * @param[in]  member_size  The size of data in frame.
 * @param[in]  max_size		Maximum size of the stack until overflow.
 */
void stack_init(stack *a, size_t member_size, int max_size);

int stack_push(stack *a, void *data);

void *stack_pop(stack *a);

void *stack_peek(stack *a);

unsigned stack_size(stack *a);

#endif
