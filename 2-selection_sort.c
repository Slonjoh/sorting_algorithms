#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, lowest_index;
	int tmp;

	if (!array || size < 2)
		return;

    /*
     *size_t i, j, lowest_index;
     *int tmp;
    */

	for (i = 0; i < size - 1; i++)
	{
		lowest_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[lowest_index])
				lowest_index = j;
		}

		if (lowest_index != i)
		{
			tmp = array[i];
			array[i] = array[lowest_index];
			array[lowest_index] = tmp;

			print_array(array, size);
		}
	}
}
