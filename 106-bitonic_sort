#include "sort.h"
#include <stdio.h>

/**
* swap - Swaps two integers
* @a: First integer
* @b: Second integer
*/
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
* bitonic_compare - Compares elements in a bitonic sequence
* @array: The array to sort
* @i: First index
* @j: Second index
* @dir: Direction (1 for ascending, 0 for descending)
*/
void bitonic_compare(int *array, size_t i, size_t j, int dir)
{
if ((array[i] > array[j] && dir == 1) ||
(array[i] < array[j] && dir == 0))
{
swap(&array[i], &array[j]);
}
}

/**
* bitonic_merge - Merges a bitonic sequence
* @array: The array to sort
* @low: Starting index
* @cnt: Number of elements to sort
* @dir: Direction (1 for ascending, 0 for descending)
* @size: Total size of array (for printing)
*/
void bitonic_merge(int *array, size_t low, size_t cnt,
int dir, size_t size)
{
size_t k, i;

if (cnt > 1)
{
k = cnt / 2;
for (i = low; i < low + k; i++)
bitonic_compare(array, i, i + k, dir);

bitonic_merge(array, low, k, dir, size);
bitonic_merge(array, low + k, k, dir, size);
}
}

/**
* bitonic_sort_recursive - Recursive bitonic sort
* @array: The array to sort
* @low: Starting index
* @cnt: Number of elements to sort
* @dir: Direction (1 for ascending, 0 for descending)
* @size: Total size of array (for printing)
*/
void bitonic_sort_recursive(int *array, size_t low,
size_t cnt, int dir, size_t size)
{
size_t k;

if (cnt > 1)
{
k = cnt / 2;

/* Print the merging step */
printf("Merging [%lu/%lu] (%s):\n",
cnt, size, dir == 1 ? "UP" : "DOWN");
print_array(array + low, cnt);

/* Sort first half in ascending order */
bitonic_sort_recursive(array, low, k, 1, size);

/* Sort second half in descending order */
bitonic_sort_recursive(array, low + k, k, 0, size);

/* Merge the whole sequence */
bitonic_merge(array, low, cnt, dir, size);

/* Print the result */
printf("Result [%lu/%lu] (%s):\n",
cnt, size, dir == 1 ? "UP" : "DOWN");
print_array(array + low, cnt);
}
}

/**
* bitonic_sort - Sorts an array of integers in ascending order
* using the Bitonic sort algorithm
* @array: The array to be sorted
* @size: Number of elements in the array
*/
void bitonic_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

/* Start recursive bitonic sort */
bitonic_sort_recursive(array, 0, size, 1, size);
}
