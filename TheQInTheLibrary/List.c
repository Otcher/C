#include <stdlib.h>
#include <stdio.h>
#include "List.h"

list_a* lst_init(void* info)
{
	list_a* lst = malloc(sizeof(list_a));
	if (lst != NULL)
	{
		node_a* node = malloc(sizeof(node_a));
		if (node != NULL)
		{
			node->before = NULL;
			node->info = info;
			node->next = NULL;

			lst->first_node = node;
			lst->last_node = node;

			lst->sum = (int)info;
			lst->cell_count = 1;
		}
	}
	return lst;
}

void lst_destroy(list_a* lst)
{
	if (lst == NULL) return;
	
	node_a* temp = lst->first_node;

	while (temp != NULL)
	{
		lst_delete(lst, temp);
		temp = lst->first_node;
	}
}

void lst_delete(list_a* lst, node_a* node)
{
	if (lst == NULL || node == NULL)
		return;

	node_a* first = lst->first_node;
	node_a* last = lst->first_node;
	if (first == node)
	{
		lst->first_node = first->next;
		first->before = NULL;
	}
	/* If its not the 1st nor last then update next and before nodes
	to point at eachother */
	else if (node->before != NULL && node->next != NULL)
	{
		(node->before)->next = node->next;
		(node->next)->before = node->before;
	}
	else if (last == node)
	{
		lst->last_node = last->before;
		last->next = NULL;
	}
	/*
		If it was just a 1 cell list
	*/
	else
	{
		lst->first_node = NULL;
		lst->last_node = NULL;
	}

	--lst->cell_count;
	lst->sum -= (int)node->info;
	free(node);
	node = NULL;
}

node_a* lst_addnode(list_a* lst, void *info)
{
	node_a* node = malloc(sizeof(node_a));
	if (node == NULL) return;

	node->info = info;
	node->next = NULL;

	lst->sum += (int)info;
	++lst->cell_count;
	if (lst->first_node != NULL)
	{
		node_a* pLast = lst->last_node;
		pLast->next = node;
		node->before = pLast;
		lst->last_node = node;
		return lst->last_node;
	}
	else
	{
		node->before = NULL;
		node->info = info;
		node->next = NULL;

		lst->first_node = node;
		lst->last_node = node;

		lst->sum = (int)info;
		lst->cell_count = 1;
	}
}

node_a* lst_getfirst(list_a* lst)
{
	return lst->first_node;
}

node_a * lst_getlast(list_a * lst)
{
	return lst->last_node;
}

node_a * lst_getnext(node_a * node)
{
	return node->next;
}

node_a * lst_getprev(node_a * node)
{
	return node->before;
}

void * lst_getinfo(node_a * node)
{
	return node->info;
}

int lst_getlength(list_a * lst)
{
	return lst->cell_count;
}

int lst_getavg(list_a * lst)
{
	return lst->sum/lst->cell_count;
}

void print_nodes(node_a *node, list_a* lst)
{
	if (node == NULL)
	{
		printf("This list is empty\n");
		return;
	}

	if (node->before == NULL) printf("{");
	printf("%p, ", node->info);
	if (node->next != NULL) print_nodes(node->next, lst);
	else
	{
		printf("DONE}\n");
		printf("sum: %d, cell count: %d\n", lst->sum, lst->cell_count);
	}
}
