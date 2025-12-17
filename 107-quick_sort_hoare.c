#include "sort.h"

void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high;

    while (1)
    {
        do {
            i++;
        } while (i <= high && array[i] < pivot);

        do {
            j--;
        } while (j >= low && array[j] > pivot);

        if (i >= j)
        {
            if (i != high)
            {
                swap_ints(&array[i], &array[high]);
                print_array(array, size);
            }
            return (i);
        }

        swap_ints(&array[i], &array[j]);
        print_array(array, size);
    }
}

void quick_sort_rec(int *array, int low, int high, size_t size)
{
    int p;

    if (low < high)
    {
        p = hoare_partition(array, low, high, size);
        quick_sort_rec(array, low, p - 1, size);
        quick_sort_rec(array, p + 1, high, size);
    }
}

void quick_sort_hoare(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_rec(array, 0, size - 1, size);
}
