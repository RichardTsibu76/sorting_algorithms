#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 *swap_ints - Swap two integers in an array.
 *@a: The first integer to swap.
 *@b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int hold_swap;

	hold_swap = *a;
	*a = *b;
	*b = hold_swap;
}

/**
 *max_heapify - coverts binary tree into binary heap
 *@array: Array integer denoting the tree
 *@size: Array size
 *@base: Base row index of the tee
 *@root: binary tree root node.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left_side, right_side, large;

	left_side = 2 * root + 1;
	right_side = 2 * root + 2;
	large = root;

	if (left_side < base && array[left_side] > array[large])
		large = left_side;
	if (right_side < base && array[right_side] > array[large])
		large = right_side;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 *heap_sort - Sort an array of integers in ascending
 *		order using the heap sort algorithm.
 *@array: An array of integers.
 *@size: Array size
 *Description: This implements the sift-down heap sort
 *algorithm. output swapped array
 */
void heap_sort(int *array, size_t size)
{
	int fig;

	if (array == NULL || size < 2)
		return;

	for (fig = (size / 2) - 1; fig >= 0; fig--)
		max_heapify(array, size, size, fig);

	for (fig = size - 1; fig > 0; fig--)
	{
		swap_ints(array, array + fig);
		print_array(array, size);
		max_heapify(array, size, fig, 0);
	}
}
