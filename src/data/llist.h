#ifndef _LLIST_H_
#define _LLIST_H_

#include "stdlib.h"

struct node
{
	char *data;
	struct node *next;
};

typedef struct llist 
{
	struct node *head;
	size_t member_size;

	unsigned int len;
} 
llist;

void llist_init(llist *list, size_t member_size);

void llist_add(llist *list, void *data);

#endif
