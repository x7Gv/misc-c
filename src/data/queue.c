#include "queue.h"
#include "stdio.h"

void queue_init(queue *a, size_t member_size, int max_size)
{
	a->size = 0;
	a->max_size = max_size;
	a->member_size = member_size;
	a->rear = NULL;
	a->front = NULL;
}

int queue_enqueue(queue *a, void *data)
{
	element_t *element = (element_t *) malloc(a->member_size + a->member_size);
	element->next = NULL;
	element->data = (char *) data;

	printf("%d\n", *((int *) element->data));

	if (a->rear == NULL) {

		a->front = a->rear = element;
		return QUEUE_OPERATION_SUCCESS;
	}

	a->rear->next = element;
	a->rear = element;
	return QUEUE_OPERATION_SUCCESS;
}

int queue_dequeue(queue *a)
{
	if (a->front == NULL) {
		return QUEUE_EXCEPTION_UNDERFLOW;
	}

	element_t *tmp = a->front;
	a->front = a->front->next;

	if (a->front == NULL) {
		a->rear = NULL;
	}

	free(tmp);
	return QUEUE_OPERATION_SUCCESS;
}



