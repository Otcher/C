#include <stdlib.h>
#include <stdio.h>
#include "List.h"

/*
	Initializes the list
*/
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

/*
	"Destroys" the list by deleting every value from it
*/
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

/*
	Deletes a specific node from a given list
*/
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
		If it was just a 1 cell list (no nodes pointed by the before and next pointers)
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

/*
	Adds a node to the list (adds it after the last node)
*/
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

/*
	Returns the first node in a given list
*/
node_a* lst_getfirst(list_a* lst)
{
	return lst->first_node;
}

/*
	Returns the last node in a given list
*/
node_a * lst_getlast(list_a * lst)
{
	return lst->last_node;
}

/*
	Returns the next node in the list (if there is no node next it, the function will return NULL)
*/
node_a * lst_getnext(node_a * node)
{
	return node->next;
}

/*
	Returns the previous node in the list (if there is no node before it, the function will return NULL)
*/
node_a * lst_getprev(node_a * node)
{
	return node->before;
}

/*
	Returns the info of the node
*/
void * lst_getinfo(node_a * node)
{
	return node->info;
}

/*
	Returns the length of a given list
*/
int lst_getlength(list_a * lst)
{
	return lst->cell_count;
}

/*
	Returns the average of the nodes in the list
*/
int lst_getavg(list_a * lst)
{
	return lst->sum/lst->cell_count;
}