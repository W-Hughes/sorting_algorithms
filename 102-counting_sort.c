#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in
 * ascending order using Counting sort.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *output;
	size_t i;
	int max = get_max(array, size);

	if (array == NULL || size < 2)
		return;

	count_array = malloc((max + 1) * sizeof(int));
	if (!count_array)
		return;
	for (i = 0; i <= (size_t)max; i++)
		count_array[i] = 0;

	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	for (i = 1; i <= (size_t)max; i++)
		count_array[i] += count_array[i - 1];
	print_array(count_array, max + 1);
	output = malloc(size * sizeof(int));

	if (!output)
	{
		free(count_array);
		return;
	}

	for (i = size; i > 0; i--)
	{
		output[count_array[array[i - 1]] - 1] = array[i - 1];
		count_array[array[i - 1]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count_array);
	free(output);
}
