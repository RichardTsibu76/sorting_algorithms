#include "sort.h"

/**
 *  * find_max - find the maximum value in the array
 *   * @array: Array
 *    * @size: size of the array
 *     *
 *      * Return: The max value
 *       */

int find_max(const int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max);
}

/**
 *  * counting_sort - Sorts an array of int in ascending order using the
 *   * Counting sort algorithm
 *    * @array: Array to be sorted
 *     * @size: size of the array
 *      *
 *       * Return: void
 *        */
void counting_sort(int *array, size_t size)
{
	int max, i, index, *counting_array;
	size_t j;

	if (array == 0 || size < 2)
	{
		return;
	}

	max = find_max(array, size);
	counting_array = (int *)malloc((max + 1) * sizeof(int));

	for (i = 0; i <= max; i++)
	{
		counting_array[i] = 0;
	}

	for (j = 0; j < size; j++)
	{
		counting_array[array[j]]++;
	}
	print_array(array, size);

	index = 0;

	for (i = 0; i <= max; i++)
	{
		while (counting_array[i] > 0)
		{
			array[index] = i;
			index++;
			counting_array[i]--;
		}
	}
	free(counting_array);

}
