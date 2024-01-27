#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 *swap_ints - This function swaps 2 integers int an array
 *@a: the first int
 *@b: the second
 */
void swap_ints(int *a, int *b)
{
	/*this is for the swapping*/
	int hold_swapped_value;

	hold_swapped_value = *a;
	*a = *b;
	*b = hold_swapped_value;
}

/**
 *hoare_partition - Order a subset of an array of integer
 *@array: array of integers.
 *@size: The size of the array.
 *@left: The starting index of the subset to order.
 *@right: The ending index of the subset to order.
 *Return: The final partition index.
 *Description: Uses the last element of the partition as the pivot.
 *Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 *hoare_sort - Implement the quicksort algorithm through recursion.
 *@array: An array of integers to sort.
 *@size: The size of the array.
 *@left: The starting index of the array partition to order.
 *@right: The ending index of the array partition to order.
 *Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 *quick_sort_hoare - This fuction sorts an array of integers
 *	using the quick sort algorithm.
 *@array: An array of integers.
 *@size: The size of the array.
 *Description: Uses the Hoare partition scheme. Prints
 *        * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}