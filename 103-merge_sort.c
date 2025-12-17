#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

static void merge_sort_rec(int *array, int *buf, size_t left, size_t right);
static void merge_arrays(int *array, int *buf, size_t left, size_t mid,
			 size_t right);

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort
 * @array: Pointer to the array
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	merge_sort_rec(array, buf, 0, size);
	free(buf);
}

/**
 * merge_sort_rec - Recursively sorts subarrays
 * @array: Original array
 * @buf: Temporary buffer
 * @left: Left index
 * @right: Right index
 */
static void merge_sort_rec(int *array, int *buf, size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
		return;

	mid = left + (right - left) / 2;
	merge_sort_rec(array, buf, left, mid);
	merge_sort_rec(array, buf, mid, right);
	merge_arrays(array, buf, left, mid, right);
}

/**
 * merge_arrays - Merges two sorted subarrays
 * @array: Original array
 * @buf: Temporary buffer
 * @left: Left index
 * @mid: Middle index
 * @right: Right index
 */
static void merge_arrays(int *array, int *buf, size_t left, size_t mid,
			 size_t right)
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
			buf[k++] = array[i++];
		else
			buf[k++] = array[j++];
	}

	while (i < mid)
		buf[k++] = array[i++];

	while (j < right)
		buf[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = buf[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}
