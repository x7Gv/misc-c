#include "llist.h"

void llist_init(llist *list, size_t member_size)
{
	list->member_size = member_size;
	list->head = NULL;
}

void llist_push(llist *list, void *data)
{
	node_t *new = (node_t *) malloc(list->member_size);
	new->data = (char *) data;

	llist_insert_begin(list, *(new));
}

void llist_append(llist *list, void *data)
{
	node_t *new = (node_t *) malloc(list->member_size);
	node_t *last = list->head;

	new->data = (char *) data;
	new->next = NULL;

	if (list->head == NULL) {
		list->head = new;
		return;
	}

	while (last->next != NULL) {
		last = last->next;
	}

	last->next = new;

	return;
}

void llist_insert_begin(llist *list, node_t new_node)
{
	new_node.next = list->head;
	list->head = &new_node;
}

void llist_insert_after(node_t node, node_t new_node)
{
	new_node.next = node.next;
	node.next = &new_node;
}

void llist_remove_after(node_t node)
{
	node_t obsolete = *((node_t *) node.next);
	node.next = node.next->next;

	free(obsolete.data);
}

void llist_remove_begin(llist *list)
{
	node_t obsolete = *((node_t *) list->head);
	list->head = list->head->next;

	free(obsolete.data);
}