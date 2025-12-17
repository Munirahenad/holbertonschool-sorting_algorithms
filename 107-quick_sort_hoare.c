#include "sort.h"

/**
 * swap_ints - Swap two integers
 * @a: First integer
 * @b: Second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Hoare partition scheme using last element as pivot
 * @array: Array to sort
 * @low: Start index
 * @high: End index
 * @size: Size of array
 *
 * Return: Partition index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap_ints(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quick_sort_rec - Recursive quick sort
 * @array: Array to sort
 * @low: Start index
 * @high: End index
 * @size: Size of array
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = hoare_partition(array, low, high, size);
		quick_sort_rec(array, low, p, size);
		quick_sort_rec(array, p + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Quick sort using Hoare partition scheme
 * @array: Array to sort
 * @size: Size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
