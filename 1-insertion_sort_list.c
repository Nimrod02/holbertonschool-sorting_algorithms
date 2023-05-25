#include "sort.h"

/**
 * doubleSwap - swap function for the value of the array
 * @list: list of int for the task
 * @node1: first value for the swap
 * @node2: second value for the swap
 *
*/
void doubleSwap(listint_t **list, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;

	if (node2->next != NULL)
		node2->next->prev = *node1;

	node2->prev = (*node1)->prev;

	node2->next = *node1;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;

	else
		*list = node2;

	(*node1)->prev = node2;

	*node1 = node2->prev;
}

/**
 * insertion_sort_list - sorting list
 * @list: double pointers that contain the value
 *
 *
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *nodePrev, *nodeNext;

	if (list == NULL || *list == NULL)
	return;

	for (nodeNext = (*list)->next; nodeNext != NULL; nodeNext = nodeNext->next)
	{
		nodePrev = nodeNext->prev;

		while (nodePrev != NULL && nodePrev->n > nodeNext->n)
		{
			doubleSwap(list, &nodePrev, nodeNext);
			print_list(*list);
			nodePrev = nodeNext->prev;
		}
	}
}
