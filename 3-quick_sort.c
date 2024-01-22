#include "sort.h"

/**
 * swap - Swaps Elements
 * @a: Element one of the elements
 * @b:This is the second elements
*/
void swap(int *a, int *b)
{
	int hold;

	keep = *a;
	*a = *b;
	*b = keep;
}
/**
 * split - Quick splits of the array
 * @array: The array at concern
 * @l: Lower bound of the array
 * @h: Higher bound of the array
 * @size: Array size at consideration
 * Return: This returns an integer
 */
int split(int *array, int l, int h, size_t size)
{
	int cal_int, pvt = array[h];
	int firsthigh;
/*let the pvt stand for the pivot*/
/*let the cal_int stand for interger calculation*/
	firsthigh = l;
	for (cal_int = l; cal_int < h; cal_int++)
	{
		if (array[cal_int] <= pvt)
		{
			if (firsthigh != cal_int)
			{
				swap(&array[cal_int], &array[firsthigh]);
				print_array(array, size);
			}
			firsthigh++;
		}
	}
	if (firsthigh != h)
	{
		swap(&array[h], &array[firsthigh]);
		print_array(array, size);
	}
	return (firsthigh);
}

/**
 * tmp_sort - This fucntion sorts elements
 * @array: Array of elements to be sorted
 * @l: Low of the array
 * @h: Higher of the array
 * @size: Size of the array
 */

void tmp_sort(int *array, int l, int h, size_t size)
{
	int mid_part;

	if (l < h)
	{
		mid_part = split(array, l, h, size);
		tmp_sort(array, l, mid_part - 1, size);
		tmp_sort(array, mid_part + 1, h, size);
	}
}
/**
 * quick_sort - Sorts elements using quick sort
 * @array: The array of element
 * @size: Array size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	tmp_sort(array, 0, size - 1, size);
}
