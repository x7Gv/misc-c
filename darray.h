/**
 * @file 	darray.h
 * @author  	Oskari J. Manninen <7Gv>
 * @date 	20 Aug 2019
 * 
 * @brief Header definitions and a public interface for d_arr 	
 */

#ifndef _DARRAY_H_
#define _DARRAY_H_

#include <stdlib.h>
#define ARR_INITIAL_CAPACITY 128

/**
 * @brief 	Main structure for a d_arr 'object'
 * 
 * Every functionality d_arr serves will be refereced
 * by this struct.
 */
typedef struct d_arr
{
	int size; 	  /**< Current size of the array. */
	int capacity; 	  /**< Current potential capacity of array. */

	void **data;	  /**< The actual data array */		
	size_t node_size; /**< Size of declared node to be stored expressed by bytes */
} d_arr;

/**
 * @brief      Initialize the array.
 *
 * @param      arr        Reference pointer to the associated array-struct.
 * @param[in]  node_size  The node size
 */
void arr_init(d_arr *arr, size_t node_size);

/**
 * @brief      Append a node of data to the tail of array.
 *
 * @param      arr   Reference pointer to the associated array-struct.    
 * @param      node  The node to be appended.
 */
void arr_append(d_arr *arr, void *node);

/**
 * @brief      Get data from the array by an index.
 *
 * @param      arr    Reference pointer to the associated array-struct.
 * @param[in]  index  The index
 * @param[out] dest   The destination
 */
void arr_get(d_arr *arr, int index, void *dest);

/**
 * @brief      Set node of data to the given index in the array.
 *
 * @param      arr    Reference pointer to the associated array-struct.
 * @param[in]  index  The index of array
 * @param      node   The node to be set
 */
void arr_set(d_arr *arr, int index, void *node);

/**
 * @brief      Free up memory allocated to the array.
 *
 * @param      arr    Reference pointer to the associated array-struct.
 */
void arr_free(d_arr *arr);

#endif