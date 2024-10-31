#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in
 *          ascending order using the Cocktail Shaker Sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		current = *list;

		while (current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}

		if (!swapped)
			break;

		swapped = 0;

		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}

