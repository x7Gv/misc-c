#ifndef _LLIST_H_
#define _LLIST_H_

#include "stdlib.h"

/**
 * @brief      Sub structure that contains the data to be linked.
 */
typedef struct node_t
{
	char *data;
	node_t *next;
}
node_t;

/**
 * Main Link to the list.
 */
typedef struct llist_t
{
	node_t *head;
	size_t member_size;
} 
llist;

/**
 * @brief      Initialize the list 
 *             [member_size]->NULL
 * 
 * @param      list         The list to initialize
 * @param[in]  member_size  The member size
 */
void llist_init(llist *list, size_t member_size);

/**
 * @brief      Append data to the tail of list.
 *
 * @param      list  The list to append
 * @param      data  The data to append
 */
void llist_append(llist *list, void *data);

/**
 * @brief      Push data to the beginning of list.
 *
 * @param      list  The list to push to.
 * @param      data  The data to push to.
 */
void llist_push(llist *list, void *data);

/**
 * @brief      Insert data to the beginning of list.
 *
 * @param      list      The list to insert to (head)
 * @param[in]  new_node  The node to insert.
 */
void llist_insert_begin(llist *list, node_t new_node);

/**
 * @brief      Insert data after a given node.
 *
 * @param[in]  node      The node to insert to.
 * @param[in]  new_node  The node to insert.
 */
void llist_insert_after(node_t node, node_t new_node);

/**
 * @brief      Remove node from the head of the list and
 * 		link it again.
 *
 * @param      list  The list to do the operation.
 */
void llist_remove_begin(llist *list);

/**
 * @brief      Remove node from the tail of the list and
 * 		link it again.
 *
 * @param      list  The list to do the operation.
 */
void llist_remove_after(node_t node);

#endif
