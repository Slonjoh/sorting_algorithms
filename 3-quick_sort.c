#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order.
 * @array: Array to be sorted
 * @size: Size of elements in @array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qs_recursive(array, 0, size - 1, size);
}

/**
 * qs_recursive - Recursive function for Quick Sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of elements in @array
 */

void qs_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		qs_recursive(array, low, pivot - 1, size);
		qs_recursive(array, pivot + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of elements in @array.
 *
 * Return: Pivot element index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, tmp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;

			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}
