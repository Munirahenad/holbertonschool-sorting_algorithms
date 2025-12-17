#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using merge sort
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;

	merge_sort_recursive(array, tmp, 0, size);
	free(tmp);
}

/**
 * merge_sort_recursive - Recursively sorts subarrays
 * @array: Original array
 * @tmp: Temporary array
 * @start: Start index
 * @end: End index
 */
void merge_sort_recursive(int *array, int *tmp, size_t start, size_t end)
{
	size_t mid;

	if (end - start < 2)
		return;

	mid = start + (end - start) / 2;
	merge_sort_recursive(array, tmp, start, mid);
	merge_sort_recursive(array, tmp, mid, end);
	merge(array, tmp, start, mid, end);
}

/**
 * merge - Merges two sorted subarrays
 * @array: Original array
 * @tmp: Temporary array
 * @start: Start index
 * @mid: Middle index
 * @end: End index
 */
void merge(int *array, int *tmp, size_t start, size_t mid, size_t end)
{
	size_t i = start, j = mid, k = start;

	printf("Merging...\n[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);

	while (i < mid && j < end)
		tmp[k++] = (array[i] <= array[j]) ? array[i++] : array[j++];

	while (i < mid)
		tmp[k++] = array[i++];

	while (j < end)
		tmp[k++] = array[j++];

	for (i = start; i < end; i++)
		array[i] = tmp[i];

	printf("[Done]: ");
	print_array(array + start, end - start);
}
