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

/**
 *  Initialize d_arr to heap
 *
 *  @param arr       - ref pointer to associated d_array.
 *  @param node_size - size of type to store in d_array 
 */
void arr_init(d_arr *arr, size_t node_size);

/**
 *  Append a value to the tail of array.
 * 
 *  @param arr  - ref pointer to associated d_array.
 *  @param node - value to append
 */
void arr_append(d_arr *arr, void *node);

/**
 *  Get value from array by an index.
 *
 *  @param arr   - ref pointer to associated d_array.
 *  @param index - index to array.
 *  @param dest  - destination pointer for returned value.
 */
void arr_get(d_arr *arr, int index, void *dest);

/**
 *  Set value to the array by given index.
 * 
 *  @param arr  - ref pointer to associated d_array.
 *  @param node - value to set.
 */
void arr_set(d_arr *arr, int index, void *node);

/**
 *  Free up used memory
 */
void arr_free(d_arr *arr);

#endif