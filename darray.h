#ifndef _DARRAY_H_
#define _DARRAY_H_

#include <stdlib.h>
#define ARR_INITIAL_CAPACITY 128

typedef struct d_arr
{
	int size;
	int capacity;

	void **data;
	size_t node_size;
} d_arr;

void arr_init(d_arr *arr, size_t node_size);

void arr_append(d_arr *arr, void *node);

void arr_get(d_arr *arr, int index, void *dest);

void arr_set(d_arr *arr, int index, void *dest);

void arr_free(d_arr *arr);

#endif