#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */
static void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Array of integers
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 *
 * Return: Index of the pivot
 */
static int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_rec - Recursive quick sort
 * @array: Array of integers
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
static void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_sort_rec(array, low, p - 1, size);
		quick_sort_rec(array, p + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array using Quick sort (Lomuto)
 * @array: Array of integers
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
