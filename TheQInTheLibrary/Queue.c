#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

queue_a* que_init(void* info)
{
	queue_a* queue = malloc(sizeof(queue_a));
	if (queue != NULL)
	{
		node_a* node = malloc(sizeof(node_a));
		if (node != NULL)
		{
			node->info = info;
			node->before = NULL;

			queue->top_node = node;
			queue->last_node = node;
			queue->cell_count = 1;

			return queue;
		}
	}
}

void que_destroy(queue_a * q)
{
	/*
	
		TODO!
	
	*/
}

node_a * que_insert(queue_a * q, void * info)
{
	node_a* node = malloc(sizeof(node_a));
	if (node == NULL) return;

	node_a* oldlast = q->last_node;
	node->info = info;
	node->before = NULL;
	oldlast->before = node;
	q->last_node = node;

	return node;
}

void * que_pop(queue_a * q)
{
	if (q->top_node == NULL) return;
	node_a* topop = q->top_node;
	q->top_node = topop->before;

	void* info = topop->info;

	free(topop);
	topop = NULL;
	--q->cell_count;
	return info;
}

int que_length(queue_a * q)
{
	return q->cell_count;
}

int que_top(queue_a * q)
{
	return ((node_a*)q->top_node)->info;
}

void* que_getinfo(node_a* node)
{
	return node->info;
}

void que_print(queue_a* q)
{
	while (q->top_node != NULL)
	{
		void* i = que_pop(q);
		printf("%p,", i);
	}
}
