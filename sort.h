#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * print_array - Prints an array of integers
 * @array: Array to print
 * @size: Size of the array
 */
void print_array(const int *array, size_t size);

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size);

#endif /* SORT_H */
