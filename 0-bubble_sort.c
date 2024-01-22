#include "sort.h"

/**
 * swap - This is the swap function
 * @a: First integer to be swapped
 * @b: The second integer to be swapped
 */


void swap(int *a, int *b)
{
	int keep;

	keep = *a;
	*a = *b;
	*b = keep;
}

/**
 * bubble_sort - Bubble sort algorithm for the certain elements
 * @array: Array of elements to be sorted
 * @size: Array size
 */

void bubble_sort(int *array, size_t size)
{
	size_t num, k;

	if (array == NULL)
		return;
	/* Loop to control the number of passes of the bu */
	for (num = 1; num <= size; num++)
	{
		/* Loop to control the number of comparisons per pass */
		for (k = 0; k < size - 1; k++)
		{
			/* Swap if current element > next */
			if (array[k] > array[k + 1])
			{
				/*swapping of elements*/
				swap(&array[k], &array[k + 1]);
				print_array(array, size);
			}
		}
	}
}
