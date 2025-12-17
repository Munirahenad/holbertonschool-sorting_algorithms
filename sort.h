#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two sorted subarrays into one sorted range
 * @array: Array containing the subarrays to merge
 * @buff: Buffer array used for merging
 * @left: Start index of left subarray
 * @mid: Start index of right subarray
 * @right: End index (exclusive) of right subarray
 */
static void merge(int *array, int *buff, size_t left,
		  size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			buff[k++] = array[i++];
		else
			buff[k++] = array[j++];
	}

	while (i < mid)
		buff[k++] = array[i++];

	while (j < right)
		buff[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = buff[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * split_merge - Recursively splits the array and merges sorted halves
 * @array: Array to sort
 * @buff: Buffer used for merging
 * @left: Start index of the current range
 * @right: End index (exclusive) of the current range
 */
static void split_merge(int *array, int *buff,
			size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
		return;

	mid = (left + right) / 2;

	split_merge(array, buff, left, mid);
	split_merge(array, buff, mid, right);
	merge(array, buff, left, mid, right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort
 * @array: Array of integers to sort
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (!array || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;

	split_merge(array, buffer, 0, size);

	free(buffer);
}
