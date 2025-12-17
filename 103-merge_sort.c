#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

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
