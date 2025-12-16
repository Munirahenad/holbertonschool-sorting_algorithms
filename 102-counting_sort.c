#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array using Counting sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	int max = 0;
	size_t i;

	if (!array || size < 2)
		return;

	/* Find the maximum value */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Allocate counting array */
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;

	/* Initialize counting array */
	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;

	/* Store counts */
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* Accumulate counts */
	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];

	/* Print counting array */
	print_array(count, max + 1);

	/* Allocate output array */
	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}

	/* Build output array (stable) */
	for (i = size; i > 0; i--)
	{
		output[count[array[i - 1]] - 1] = array[i - 1];
		count[array[i - 1]]--;
	}

	/* Copy back to original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
