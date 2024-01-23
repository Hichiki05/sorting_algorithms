#include "sort.h"

/**
 * swap - Swaps two elements in an array and prints the current state.
 *
 * @array: The array containing the elements to swap.
 * @size: The size of the array.
 * @a: Pointer to the first element to swap.
 * @b: Pointer to the second element to swap.
 */
void swap(int *array, size_t size, int *a, int *b)
{
if (*a != *b)
{
*a = *a + *b;
*b = *a - *b;
*a = *a - *b;
print_array((const int *)array, size);
}
}

/**
 * lomuto_partition - Partitions an array using the Lomuto partition scheme.
 *
 * @array: The array to be partitioned.
 * @size: The size of the array.
 * @lo: The low index of the partition.
 * @hi: The high index of the partition.
 *
 * Return: The index of the pivot element.
 */
size_t lomuto_partition(int *array, size_t size, ssize_t lo, ssize_t hi)
{
int i, j, pivot = array[hi];

for (i = lo, j = lo; j < hi; j++)
{
if (array[j] < pivot)
{
swap(array, size, &array[j], &array[i]);
i++;
}
}
swap(array, size, &array[i], &array[hi]);

return (i);
}

/**
 * quicksort - Recursively sorts an array using the quicksort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @lo: The low index of the partition.
 * @hi: The high index of the partition.
 */
void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi)
{
if (lo < hi)
{
size_t p = lomuto_partition(array, size, lo, hi);
if (p > 0)
quicksort(array, size, lo, p - 1);
quicksort(array, size, p + 1, hi);
}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using quicksort.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
return;
quicksort(array, size, 0, size - 1);
}

