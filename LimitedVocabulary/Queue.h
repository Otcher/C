#ifndef DYN_QUEUE_H
#define DYN_QUEUE_H
#include "List.h"

/*
	Queue type struct
*/
typedef struct queue {
	struct list_a* ls;
} queue_a;

//Functions

queue_a* que_init(void* info);
void que_destroy(queue_a* q);
node_a* que_insert(queue_a* q, void *info);
void* que_pop(queue_a* q);
int que_length(queue_a* q);
void* que_top(queue_a* q);

#endif