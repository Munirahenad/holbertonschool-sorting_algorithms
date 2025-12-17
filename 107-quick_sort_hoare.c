#include "sort.h"

/**
* swap_ints - swap two integers
* @a: first integer
* @b: second integer
*/
void swap_ints(int *a, int *b)
{
int tmp = *a;

*a = *b;
*b = tmp;
}

/**
* hoare_partition - Hoare partition scheme
* @array: array to sort
* @low: start index
* @high: end index
* @size: array size
*
* Return: partition index
*/
int hoare_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j = high + 1;

while (1)
{
do {
i++;
} while (array[i] < pivot);

do {
j--;
} while (array[j] > pivot);

if (i >= j)
return (j);

swap_ints(&array[i], &array[j]);
print_array(array, size);
}
}

/**
* quick_sort_rec - recursive quick sort
* @array: array to sort
* @low: start index
* @high: end index
* @size: array size
*/
void quick_sort_rec(int *array, int low, int high, size_t size)
{
int p;

if (low < high)
{
p = hoare_partition(array, low, high, size);
quick_sort_rec(array, low, p, size);
quick_sort_rec(array, p + 1, high, size);
}
}

/**
* quick_sort_hoare - Quick sort using Hoare partition
* @array: array to sort
* @size: array size
*/
void quick_sort_hoare(int *array, size_t size)
{
if (!array || size < 2)
return;

quick_sort_rec(array, 0, size - 1, size);
}
