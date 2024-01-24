#include "sort.h"

/**
 * swap - This swapping about two integers
 * @a: int one
 * @b: int two
 */
void swap(int *a, int *b)
{
	int keep;

	keep = *a;
	*a = *b;
	*b = keep;
}

/**
 * shell_sort - This funtion sorts an array of integers in
 *	ascending order
 * @array: The array to be sorted
 * @size: Array size
 */
void shell_sort(int *array, size_t size)
{
	size_t space, n, p;

	if (array == NULL || size < 2)
		return;

	space = 1;
	while (space < size / 3)
		space = space * 3 + 1;
	while (space >= 1)
	{
		for (n = space; n < size; n++)
		{
			for (p = n; p >= space && (array[p] < array[p - space]); p -= space)
				swap(&array[p], &array[p - space]);
		}
		space /= 3;
		print_array(array, size);
	}
}
