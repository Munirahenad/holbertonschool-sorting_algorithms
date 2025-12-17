#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Finds the maximum value in an array of integers
 * @array: Pointer to the array
 * @size: Number of elements in the array
 *
 * Return: The maximum value in the array
 */
static int get_max(const int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * build_count - Creates and prepares the counting array (prefix sums)
 * @array: Pointer to the input array
 * @size: Number of elements in the input array
 * @max: Maximum value found in the input array
 *
 * Return: Pointer to the counting array, or NULL on failure
 */
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

/**
 * fill_output - Fills output array in sorted order using counting array
 * @array: Pointer to the input array
 * @size: Number of elements in the array
 * @count: Counting array (prefix sums)
 * @out: Output array to store sorted elements
 */
static void fill_output(const int *array, size_t size, int *count, int *out)
{
	int i;

	for (i = (int)size - 1; i >= 0; i--)
	{
		out[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
}

/**
 * copy_back - Copies sorted output array back into the original array
 * @array: Pointer to the original array
 * @out: Pointer to the sorted output array
 * @size: Number of elements in the array
 */
static void copy_back(int *array, const int *out, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		array[i] = out[i];
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 * @array: Array of integers to sort
 * @size: Number of elements in the array
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
