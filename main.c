#include "darray.h"

#include <stdlib.h>
#include <stdio.h>

int main()
{
	d_arr *arr = malloc(sizeof(d_arr));
	arr_init(arr, sizeof(int));

	for (int i = 0; i <= 512; i++) {

		void *tmp = &i;
		arr_append(arr, tmp);
	}

	for (int j = 0; j <= arr->size; j++) {

		void *tmp;
		arr_get(arr, j, tmp);

		tmp = tmp + sizeof(int);


		printf("%d\n", *(int*) tmp);
	}

	free(arr);
	return 0;
}
