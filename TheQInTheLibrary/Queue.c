#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"
#include "List.h"

/*
	Initalize the queue by creating a new list with one node containing the info
*/
queue_a* que_init(void* info)
{
	queue_a* queue = malloc(sizeof(queue_a));
	if (queue != NULL)
	{
		queue->ls = lst_init(info);

		return queue;
	}
}

/*
	Destroy the queue by deleting all nodes from the list
*/
void que_destroy(queue_a * q)
{
	lst_destroy(q->ls);
}

/*
	Insert a new value into the Queue
*/
node_a * que_insert(queue_a * q, void * info)
{
	list_a *lst = q->ls;
	node_a *node = lst_addnode(lst, info);

	return node;
}

/*
	Pop the first node in queue
*/
void * que_pop(queue_a * q)
{
	list_a *lst = q->ls;
	node_a *node = lst_getfirst(lst);

	void *info = lst_getinfo(node);
	lst_delete(lst, node);

	return info;
}

/*
	Return length of queue
*/
int que_length(queue_a * q)
{
	return (lst_getlength(q->ls));
}

/*
	Return the value of the top of the queue without removing the node
*/
void* que_top(queue_a * q)
{
	return (lst_getinfo(lst_getfirst(q->ls)));
}
