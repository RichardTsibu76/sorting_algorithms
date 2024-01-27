#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 *swap_ints - This swaps two integers in an array.
 *@a: First int
 *@b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int keep_swap;

	keep_swap = *a;
	*a = *b;
	*b = keep_swap;
}

/**
 *bitonic_merge - This sorts a bitonic sequence inside an array of integers.
 *@array: Integer array
 *@size: array size
 *@start: Starting index
 *@seq: The size of the sequence to sort.
 *@flow: The order of direction in which is to be sorted
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t fig, leap_into = seq / 2;

	if (seq > 1)
	{
		for (fig = start; fig < start + leap_into; fig++)
		{
			if ((flow == UP && array[fig] > array[fig + leap_into]) ||
					(flow == DOWN && array[fig] < array[fig + leap_into]))
				swap_ints(array + fig, array + fig + leap_into);
		}
		bitonic_merge(array, size, start, leap_into, flow);
		bitonic_merge(array, size, start + leap_into, leap_into, flow);
	}
}

/**
 *bitonic_seq - Convert an array of integers into a bitonic sequence.
 *@array: An array of integers.
 *@size: The size of the array.
 *@start: The starting index of a block of the building bitonic sequence.
 *@seq: The size of a block of the building bitonic sequence.
 *@flow: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 *bitonic_sort - sorts an array in int in ascending order bitonic sort
 *@array: An array of integers.
 *@size: The size of the array.
 *
 *Description: Prints the array after each swap. Only works for
 *size = 2^k where k >= 0 / which means size is equal to pow of 2
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
