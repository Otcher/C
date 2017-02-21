#ifndef DYN_QUEUE_H
#define DYN_QUEUE_H

/*
	Node type struct
*/
typedef struct node {
	void *info;
	struct node *before;
} node_a;

/*
	Queue type struct
*/
typedef struct queue {
	struct node_a *top_node;
	struct node_a *last_node;
	int cell_count;
} queue_a;

//funcs

queue_a* que_init(void* info);
void que_destroy(queue_a* q);
node_a* que_insert(queue_a* q, void *info);
void* que_pop(queue_a* q);
int que_length(queue_a* q);
int que_top(queue_a* q);

void* que_getinfo(node_a);
void que_print(queue_a* q);

#endif