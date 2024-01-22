#include "sort.h"

/**
 * swap - A swapping function sorting algorithm
 * @a: First number at consideration to swapped
 * @b: The second number
 */

void swap(int *a, int *b)
{
	int hold;

	hold = *a;
	*a = *b;
	*b = hold;
}

/**
 * bubble_sort - This function sorts an array of integers
 *     in ascending order using Bubble sort algorithm
 * @array: Array of elements
 *
 * @size: Size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL)
		return;
	/* Loop to control the number of passes */
	for (i = 1; i <= size; i++)
	{
		/* Loop to control the number of comparisons per pass */
		for (j = 0; j < size - 1; j++)
		{
			/* Swap if current element > next */
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
