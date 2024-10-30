#include "sort.h"

/**
 *bubble_sort - Sorts an array of integers in ascending order using
 *the Bubble sort algorithm.
 *@array: Pointer to the array to be sorted.
 *@size: the size of the array.
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j;
	int swapped;

	if (array == NULL || size < 2)
		return;

	while (i < size - 1)
	{
		j = 0;
		swapped = 0;
		while (j < size - 1 - i)
		{
			if (_intcmp(array[j], array[j + 1]) > 0)
			{
				_swapints(array, j, (j + 1));
				swapped = 1;
				print_array(array, size);
			}
			j++;
		}

		if (swapped == 0)
			break;
		i++;
	}


}

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
