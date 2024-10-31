#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm (Lomuto partition scheme).
 * @array: The array of integers to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - Recursively sorts the array using Quick Sort.
 * @array: The array to sort.
 * @low: The starting index of the subarray.
 * @high: The ending index of the subarray.
 * @size: The total size of the array.
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);

		quicksort(array, low, pivot_index - 1, size);
		quicksort(array, pivot_index + 1, high, size);
	}
}

/**
 * lomuto_partition - Partitions the array using Lomuto partition scheme.
 * @array: The array to partition.
 * @low: The starting index of the subarray.
 * @high: The ending index of the subarray (pivot).
 * @size: The total size of the array.
 *
 * Return: The index of the pivot element after partition.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				_swapints(array, i, j);
				print_array(array, size);
			}
		}
	}

	if (array[high] != array[i + 1])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;

		print_array(array, size);
	}

	return (i + 1);
}

