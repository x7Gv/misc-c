#include "./darray.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void arr_init(d_arr *arr, size_t node_size)
{
	arr->size = 0;
	arr->capacity = ARR_INITIAL_CAPACITY;

	arr->data = malloc(arr->capacity * node_size);

	if (arr->data == NULL) {
		fprintf(stderr, "Err: failed to initialize miscc->d_array ! Assertion: *data != NULL\n");
		exit(EXIT_FAILURE);
	}

	arr->node_size = node_size;
}

void arr_append(d_arr *arr, void *node)
{
	if (arr->size >= arr->capacity) {
		arr->capacity *= 2;
		arr->data = realloc(arr->data, arr->capacity * sizeof(arr->data));
	}

	arr->data[arr->size++] = node; 
}

void arr_get(d_arr *arr, int index, void *dest)
{
	if (arr->size < index) {
		fprintf(stderr, "Err: d_array index out of bounds.\n");
		exit(EXIT_FAILURE);
	}

	dest = arr->data[index];
}

void arr_set(d_arr *arr, int index, void *node)
{
	while (index >= arr->size) {
		arr_append(arr, NULL);
	}

	arr->data[arr->size] = node;
}

void arr_free(d_arr *arr)
{
	free(arr->data);
}
