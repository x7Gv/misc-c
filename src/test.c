#include "data/llist.h"
#include "data/stack.h"
#include "data/queue.h"

#include <stdio.h>

llist list;
stack stk;
queue q;

void test()
{
	llist_init(&list, sizeof(int));

	int i0 = 12;
	int i1 = 15;
	int i2 = 546;

	llist_append(&list, &i0);
	llist_append(&list, &i1);
	llist_append(&list, &i2);
}

void test1()
{
	int i3 = 34;
	int i4 = 235;
	int i5 = 239;
	int i6 = 92;

	stack_init(&stk, sizeof(int), 4);

	stack_push(&stk, &i3);
	stack_push(&stk, &i4);
	stack_push(&stk, &i5);
	stack_push(&stk, &i6);
}

void test2()
{
	int i0a = 10;
	int i1a = 20;
	int i2a = 30;
	int i3a = 40;
	int i4a = 50;

	queue_init(&q, sizeof(int), 16);

	queue_enqueue(&q, &i0a);
	queue_enqueue(&q, &i1a); 
    	queue_dequeue(&q); 
    	queue_dequeue(&q);
    	queue_enqueue(&q, &i2a);
	queue_enqueue(&q, &i3a);  
	queue_enqueue(&q, &i4a);
    	queue_dequeue(&q); 

    	printf("q_front : %d\n", *((int *) q.front->data)); 
   	printf("q_rear : %d\n", *((int *) q.rear->data)); 
}


int main(int argc, char **argv)
{
	test();
	int i2 = 546;
	llist_push(&list, &i2);

	node_t *n = list.head;

	while (n != NULL) {
		printf("%d\n", *((int *) n->data));
		n = n->next; 
	}

	test1();
	frame_t *f = stk.top;

	while (f != NULL) {
		printf("%d\n", *((int *) f->data));
		f = f->next;
	}

	printf("----------------------------------\n");
	test2();

	return 0;
}
