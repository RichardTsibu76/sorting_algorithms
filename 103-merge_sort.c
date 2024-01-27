#include "sort.h"

/*the desnagated prototype for the fuctions*/

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 *merge_subarr - This Function merges sorted array of int.
 *@subarr: sub array to be sorted
 *@buff: Temporal storage for subarray
 *@front: It's the array front index.
 *@mid: The middle index called the pivot
 *@back: This is the index at the back
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t d, e, f = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (d = front, e = mid; d < mid && e < back; f++)
		buff[f] = (subarr[d] < subarr[e]) ? subarr[d++] : subarr[e++];
	for (; d < mid; d++)
		buff[f++] = subarr[d];
	for (; e < back; e++)
		buff[f++] = subarr[e];
	for (d = front, f = 0; d < back; d++)
		subarr[d] = buff[f++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 *merge_sort_recursive - Recursively merges sort
 *@subarr: This is the subarry
 *@buff: Temporal storage
 *@front: The front index
 *@back:back index
 *Return: no ret. value
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 *merge_sort - Sort an array of integers in ascending
 *	order using the merge sort algorithm.
 *@array: An array of integers.
 *@size: Array size
 *Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;
/*dynamically allocating memory*/
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
