#include "sort.h"

/**
 * sift_down - Repair the heap whose root element is at index 'root'
 * @array: Array to sort
 * @size: Size of the array
 * @root: Index of the root of the heap
 * @end: Last index of the heap to consider
 */
static void sift_down(int *array, size_t size, size_t root, size_t end)
{
    size_t max_child, left_child;
    int temp;

    while ((left_child = 2 * root + 1) <= end)
    {
        max_child = left_child;
        if (left_child + 1 <= end && array[left_child + 1] > array[left_child])
            max_child = left_child + 1;

        if (array[root] >= array[max_child])
            return;

        temp = array[root];
        array[root] = array[max_child];
        array[max_child] = temp;

        print_array(array, size);
        root = max_child;
    }
}

/**
 * heapify - Builds a max heap from the array
 * @array: Array to heapify
 * @size: Size of the array
 */
static void heapify(int *array, size_t size)
{
    ssize_t start;

    if (size < 2)
        return;

    start = (size - 2) / 2; /* Last parent node */

    while (start >= 0)
    {
        sift_down(array, size, start, size - 1);
        start--;
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    size_t end;
    int temp;

    if (array == NULL || size < 2)
        return;

    heapify(array, size);

    end = size - 1;
    while (end > 0)
    {
        temp = array[0];
        array[0] = array[end];
        array[end] = temp;

        print_array(array, size);

        end--;
        sift_down(array, size, 0, end);
    }
}
