#include "sort.h"

/*effectively add prototypes for the fuctions*/
int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 *get_max - Concern with getting the maximum value of the arrry
 *@array: Array of int
 *@size: Array size
 *Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int mx, fig;

	for (mx = array[0], fig = 1; fig < size; fig++)
	{
		if (array[fig] > mx)
			mx = array[fig];
	}

	return (mx);
}

/**
 *radix_counting_sort - A fucntion that sorts array of integers
 *	in ascending order using the counting sort algorithm.
 *@array: An array of integers to be sorted
 *@size: Size of the array to be sorted
 *@sig: The significant digit at concern
 *@buff: A storage for the array
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t d;

	for (d = 0; d < size; d++)
		count[(array[d] / sig) % 10] += 1;

	for (d = 0; d < 10; d++)
		count[d] += count[d - 1];

	for (d = size - 1; (int)d >= 0; d--)
	{
		buff[count[(array[d] / sig) % 10] - 1] = array[d];
		count[(array[d] / sig) % 10] -= 1;
	}

	for (d = 0; d < size; d++)
		array[d] = buff[d];
}

/**
 *radix_sort - Sort an array of integers in ascending
 *		order using the radix sort algorithm.
 *@array: Integer array
 *@size: Array size
 *
 *Description: Implements the LSD radix sort algorithm. outputs
 *	the array after each sig. digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int mx, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	mx = get_max(array, size);
	for (sig = 1; mx / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
