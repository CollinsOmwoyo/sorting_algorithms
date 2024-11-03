#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
 * lomuto_partition - Partition using the Lomuto scheme
 * @array: Pointer to the array of integers
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Total size of the array (for printing)
 * Return: The final pivot position
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j;

for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
    i++;
    if (i != j)
    {
        swap(&array[i], &array[j]);
        print_array(array, size);
    }
}
}

if (i + 1 != high)
{
swap(&array[i + 1], &array[high]);
print_array(array, size);
}

return (i + 1);
}

/**
 * quick_sort_recursive - Recursively using Quick Sort
 * @array: Pointer to the array of integers
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Total size of the array (for printing)
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pivot = lomuto_partition(array, low, high, size);
quick_sort_recursive(array, low, pivot - 1, size);
quick_sort_recursive(array, pivot + 1, high, size);
}
}

/**
 * quick_sort - ascending order using Quick Sort
 * @array: Pointer to the array of integers to sort
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_sort_recursive(array, 0, size - 1, size);
}
