#include "sort.h"

/**
 *insertion_sort_list - Sorts a doubly linked list of integers
 *		in ascending order using insertion sorted algorithm.
 *@list: Double pointer to the head of the list
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *swap_node;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		swap_node = current;
		current = current->next;

		while (swap_node->prev && swap_node->n < swap_node->prev->n)
		{
			swap_nodes(list, swap_node->prev, swap_node);
			print_list(*list);
		}
	}
}

/**
 *swap_nodes - Swaps two adjecent nodes in a doubly linked list.
 *@list: Double pointer to the head of the list.
 *@left: The first node to swap.
 *@right: The second node to swap.
 */

void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	right->prev = left->prev;
	left->next = right->next;
	right->next = left;
	left->prev = right;
}
