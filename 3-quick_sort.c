#include "sort.h"

/**
 * swap_and_print - Swaps two elements in array and prints it (only if changed)
 * @array: Array of integers
 * @i: First index
 * @j: Second index
 * @size: Size of the array
 */
static void swap_and_print(int *array, int i, int j, size_t size)
{
	int tmp;

	if (i == j)
		return;

	if (array[i] == array[j])
		return;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	print_array(array, size);
}

/**
 * lomuto_partition - Partitions array using Lomuto scheme
 * @array: Array of integers
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 *
 * Return: Index of pivot after partition
 */
static int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_and_print(array, i, j, size);
		}
	}

	swap_and_print(array, i + 1, high, size);
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursively sorts array using Quick sort
 * @array: Array of integers
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
static void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, p - 1, size);
		quick_sort_recursive(array, p + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using Quick sort (Lomuto)
 * @array: Array of integers
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, (int)size - 1, size);
}
