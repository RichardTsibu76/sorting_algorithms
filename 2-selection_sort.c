#include "sort.h"

/**
 * swap - Swaps elements
 * @a: The first elements to be swapped
 * @b: The second elements
 */

void swap(int *a, int *b)
{
	int hold;

	hold = *a;
	*a = *b;
	*b = hold;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 *	using the selection sort algorithm
 * @array: Array of elements
 * @size: Array size
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t val, j, min_val;

	if (array == NULL)
		return;

	for (val = 0; val < size - 1; val++)
	{
		min_val = val;
		for (j = val + 1; j < size; j++)
		{
			if (array[j] < array[min_val])
				min_val = j;
		}
		if (min_val != val)
		{
			swap(&array[val], &array[min_val]);
			print_array(array, size);
		}
	}
}
