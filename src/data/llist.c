#include "llist.h"

void llist_init(llist *list, size_t member_size)
{
	list->member_size = member_size;
	list->head = NULL;
}