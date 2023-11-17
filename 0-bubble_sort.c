#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Size of elements in @array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;
	int swp;

	for (i = 0; i < size - 1; i++)
	{
		swp = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

				swp = 1;

				print_array(array, size);
			}
		}

		if (swp == 0)
			break;
	}
}
