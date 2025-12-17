#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * print_merge - prints the left or right subarray
 * @array: array to print
 * @start: start index
 * @end: end index
 */
void print_merge(int *array, size_t start, size_t end)
{
	size_t i;
	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i < end)
			printf(", ");
	}
	printf("\n");
}

/**
 * merge - merges two subarrays and prints steps
 * @array: array to merge
 * @tmp: temporary array
 * @left: left index
 * @mid: middle index
 * @right: right index
 */
void merge(int *array, int *tmp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid + 1, k = left;

	printf("Merging...\n[left]: ");
	print_merge(array, left, mid);
	printf("[right]: ");
	print_merge(array, mid + 1, right);

	while (i <= mid && j <= right)
		tmp[k++] = (array[i] <= array[j]) ? array[i++] : array[j++];
	while (i <= mid)
		tmp[k++] = array[i++];
	while (j <= right)
		tmp[k++] = array[j++];

	for (i = left; i <= right; i++)
		array[i] = tmp[i];

	printf("[Done]: ");
	print_merge(array, left, right);
}

/**
 * merge_sort_recursive - recursively splits and merges array
 * @array: array to sort
 * @tmp: temporary array
 * @left: left index
 * @right: right index
 */
void merge_sort_recursive(int *array, int *tmp, size_t left, size_t right)
{
	size_t mid;

	if (left >= right)
		return;

	mid = left + (right - left) / 2;
	merge_sort_recursive(array, tmp, left, mid);
	merge_sort_recursive(array, tmp, mid + 1, right);
	merge(array, tmp, left, mid, right);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;

	merge_sort_recursive(array, tmp, 0, size - 1);
	free(tmp);
}
