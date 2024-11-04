#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in
 * ascending order using Counting sort.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int max;
	int *count;
	int *sorted;

	if (array == NULL || size < 2)
		return;

	max = _get_max_int_array(array, size);
	if (max == -1)
		return;

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);
	sorted = malloc(sizeof(int) * size);

	if (sorted == NULL)
	{
		free(count);
		return;
	}
	for (i = size; i-- > 0;)
		sorted[--count[array[i]]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}

/**
 *_get_max_int_array - Finds the maximum integer value in an integer array.
 *@array: Point to an integer array to find maximum integer from.
 *@size: The the number of elememt in the array.
 *
 * Return: The maximum value in the array, or -1 if size is 0.
 */

int _get_max_int_array(int *array, size_t size)
{
	int max;
	size_t i;

	if (size == 0)
		return (-1);

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
