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
	size_t num, K;

	if (array == NULL)
		return;
	/* Control flow of the passes */
	for (num = 1; num <= size; num++)
	{
		/* This loop is to compare the number of pasess */
		for (K = 0; K < size - 1; K++)
		{
			/* Leverages the swapping if currrent element> next */
			if (array[K] > array[K + 1])
			{
				swap(&array[K], &array[K + 1]);
				print_array(array, size);
			}
		}
	}
}
