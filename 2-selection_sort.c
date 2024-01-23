#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the selection sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
size_t i, j, k;
int temp;

/* Check for valid array and size */
if (!array || !size)
return;

/* Iterate through the array */
for (i = 0; i < size - 1; i++)
{
/* Find the minimum element in the unsorted part of the array */
for (j = size - 1, k = i + 1; j > i; j--)
{
if (array[j] < array[k])
{
k = j;
}
}

/* Swap the found minimum element with the first element */
if (array[i] > array[k])
{
temp = array[i];
array[i] = array[k];
array[k] = temp;

/* Print the current state of the array after swapping */
print_array(array, size);
}
}
}

