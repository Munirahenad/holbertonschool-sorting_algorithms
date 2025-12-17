#include "sort.h"
#include <stdlib.h>

static int get_max(const int *array, size_t size);
static int *build_count(const int *array, size_t size, int max);
static void fill_output(const int *array, size_t size, int *count, int *out);
static void copy_back(int *array, const int *out, size_t size);

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max, *count, *out;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);
	count = build_count(array, size, max);
	if (count == NULL)
		return;

	print_array(count, (size_t)max + 1);

	out = malloc(sizeof(int) * size);
	if (out == NULL)
	{
		free(count);
		return;
	}

	fill_output(array, size, count, out);
	copy_back(array, out, size);

	free(count);
	free(out);
}

static int get_max(const int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}

static int *build_count(const int *array, size_t size, int max)
{
	int *count;
	size_t i;

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return (NULL);

	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];

	return (count);
}

static void fill_output(const int *array, size_t size, int *count, int *out)
{
	int i;

	for (i = (int)size - 1; i >= 0; i--)
	{
		out[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
}

static void copy_back(int *array, const int *out, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		array[i] = out[i];
}
