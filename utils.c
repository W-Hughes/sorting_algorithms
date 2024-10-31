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
