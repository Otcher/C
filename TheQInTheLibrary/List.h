#ifndef DYN_LIST_H
#define DYN_LIST_H

/*
	Node type struct
*/
typedef struct node {
	struct node *before;
	void *info;
	struct node *next;
} node_a;

/*
	List type struct
*/
typedef struct list {
	struct node_a *first_node;
	struct node_a *last_node;
	int sum;
	int cell_count;
} list_a;

/*
	Functions
*/

list_a* lst_init(void *info);
void lst_destroy(list_a* lst);
void lst_delete(list_a* lst, node_a* node);
node_a* lst_addnode(list_a* lst, void *info);
node_a* lst_getfirst(list_a* lst);
node_a* lst_getlast(list_a* lst);
node_a* lst_getnext(node_a* node);
node_a* lst_getprev(node_a* node);
void* lst_getinfo(node_a* node);
int lst_getlength(list_a* lst);
int lst_getavg(list_a* lst);

#endif