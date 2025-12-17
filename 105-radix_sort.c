#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
* get_max - Gets the maximum value in an array
* @array: The array to search
* @size: Number of elements in the array
* Return: The maximum value
*/
int get_max(int *array, size_t size)
{
int max = array[0];
size_t i;

for (i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}
return (max);
}

/**
* counting_sort_for_radix - Performs counting sort on array based on digit
* @array: The array to sort
* @size: Number of elements in the array
* @exp: The current exponent (10^exp)
*/
void counting_sort_for_radix(int *array, size_t size, int exp)
{
int *output = malloc(sizeof(int) * size);
int count[10] = {0};
size_t i;

if (output == NULL)
return;

/* Store count of occurrences in count[] */
for (i = 0; i < size; i++)
count[(array[i] / exp) % 10]++;

/*
 * Change count[i] so that count[i] now contains actual
 * position of this digit in output[]
 */
for (i = 1; i < 10; i++)
count[i] += count[i - 1];

/* Build the output array */
for (i = size; i > 0; i--)
{
output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
count[(array[i - 1] / exp) % 10]--;
}

/*
 * Copy the output array to array[], so that array[] now
 * contains sorted numbers according to current digit
 */
for (i = 0; i < size; i++)
array[i] = output[i];

free(output);
}

/**
* radix_sort - Sorts an array of integers in ascending order
* using the LSD Radix sort algorithm
* @array: The array to be sorted
* @size: Number of elements in the array
*/
void radix_sort(int *array, size_t size)
{
int max, exp;

if (array == NULL || size < 2)
return;

/* Find the maximum number to know number of digits */
max = get_max(array, size);

/*
* Do counting sort for every digit. Note that instead
* of passing digit number, exp is passed. exp is 10^i
* where i is current digit number
*/
for (exp = 1; max / exp > 0; exp *= 10)
{
counting_sort_for_radix(array, size, exp);
print_array(array, size);
}
}
