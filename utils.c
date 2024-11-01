#include "sort.h"

/**
 *_intcmp - Comapres two integers arguments.
 *@a: The first integer argument
 *@b: The second integer argument
 *
 *Return: A negative value if the first is smaller, positive
 *	if the second is smaller, otherwise 0 if they're equal.
 */

int _intcmp(int a, int b)
{
	return (a - b);
}

/**
 *_swapints - Swap two integer values in an array.
 *@array: The array in which to swap elements.
 *@i: The first integer value in the array.
 *@j: The second integer value in the array
 */

void _swapints(int *array, size_t i, size_t j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @right: A pointer to the tail of the doubly-linked list.
 * @left: A pointer to the current swapping node of the cocktail.
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


/**
 *get_max - Getter to return the maximum value in an
 *	array of integers.
 *@array: The array of integers to find maximum integer in.
 *@size: The length of the array
 *
 * Return: The maximum integer in the array.
 */

int get_max(int *array, int size)
{
	int i;
	int max = 0;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}
