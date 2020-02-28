#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "stdlib.h"

#define QUEUE_UNDEFINED_LIMIT -1

#define QUEUE_OPERATION_SUCCESS 0;

#define QUEUE_EXCEPTION_OVERFLOW -2
#define QUEUE_EXCEPTION_UNDERFLOW -3

typedef struct queue queue;
typedef struct element_t element_t;

struct element_t
{
	char *data;
	element_t *next;
};

struct queue
{
	size_t member_size;
	int max_size;
	unsigned int size;

	element_t *rear, *front;
};

/**
 * @brief      Initialize queue
 *
 * @param      a            	Queue ref to initialize.
 * @param[in]  member_size  	The size of data in frame.
 * @param[in]  max_size		Maximum size of the stack until overflow.
 */
void queue_init(queue *a, size_t member_size, int max_size);

int queue_enqueue(queue *a, void *data);

int queue_dequeue(queue *a);

int queue_empty(queue *a);



#endif
