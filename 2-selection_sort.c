#include "sort.h"
#include <stdlib.h>

/**
 * find_max - find the maximum value in an array
 * @array: array of integers
 * @size: number of elements in array
 * Return: maximum integer in array
 */
static int find_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * init_count_array - allocate and initialize count array
 * @max: maximum value in array
 * Return: pointer to count array or NULL on failure
 */
static int *init_count_array(int max)
{
	int *count;
	size_t i;

	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return (NULL);

	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;

	return (count);
}

/**
 * count_elements - counts occurrences of elements
 * @array: original array
 * @size: number of elements
 * @count: counting array
 */
static void count_elements(int *array, size_t size, int *count)
{
	size_t i;

	for (i = 0; i < size; i++)
		count[array[i]]++;
}

/**
 * cumulative_count - transforms count array to cumulative counts
 * @count: counting array
 * @size: size of count array
 */
static void cumulative_count(int *count, size_t size)
{
	size_t i;

	for (i = 1; i < size; i++)
		count[i] += count[i - 1];
}

/**
 * build_output_array - build sorted array using count array
 * @array: original array
 * @size: number of elements
 * @count: cumulative count array
 * @output: output array
 */
static void build_output_array(int *array, size_t size, int *count, int *output)
{
	size_t i;

	for (i = size; i > 0; i--)
	{
		output[count[array[i - 1]] - 1] = array[i - 1];
		count[array[i - 1]]--;
	}
}

/**
 * counting_sort - sorts an array of integers using counting sort
 * @array: array of integers
 * @size: number of elements
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	int max;

	if (!array || size < 2)
		return;

	max = find_max(array, size);

	count = init_count_array(max);
	if (!count)
		return;

	count_elements(array, size, count);
	cumulative_count(count, max + 1);

	/* Print counting array */
	print_array(count, max + 1);

	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}

	build_output_array(array, size, count, output);

	for (size_t i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
