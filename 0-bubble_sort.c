#include "sort.h"

/**
 * swap - A swapping function sorting algorithm
 * @a: First number at consideration to swapped
 * @b: The second number
 */

void swap(int *a, int *b)
{
	int keep;

	keep = *a;
	*a = *b;
	*b = keep;
}

/**
 * bubble_sort - This function sorts an array of integers
 *     in ascending order using Bubble sort algorithm
 * @array: Array of elements of the algorithm
 * @size: Array Size of the elements
 */

void bubble_sort(int *array, size_t size)
{
	size_t num, j;

	if (array == NULL)
		return;
	/* Control flow of the passes */
	for (num = 1; num <= size; num++)
	{
		/* This loop is to compare the number of pasess */
		for (j = 0; j < size - 1; j++)
		{
			/* Leverages the swapping if currrent element> next */
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
