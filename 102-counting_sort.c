#include "sort.h"

/**
 *counting_sort - This function emphasises on counting sort
 *array in ascending order
 *@array: Order of arry at concern
 *@size: The size of the array
 *Return: This deos not return value
 */
void counting_sort(int *array, size_t size)
{
		size_t i_value, max = array[0], j;
			int *tmp, *result;

			if (array == NULL || size < 2)
				return;

			for (i_value = 1; i_value < size; i_value++)
			{
				if (array[i_value] > (int) max)
					max = array[i_value];
			}
			tmp = malloc(sizeof(int) * (max + 1));
			if (tmp == NULL)
				return;
			result = malloc(sizeof(int) * size);
			if (result == NULL)
			{
				free(tmp);
				return;
			}
			for (i_value = 0; i_value <= (size_t) max; i_value++)
				tmp[i_value] = 0;
			for (j = 0; j < size; j++)
				tmp[array[j]] = tmp[array[j]] + 1;
			for (i_value = 1; i_value <= max; i_value++)
				tmp[i_value] = tmp[i_value] + tmp[i_value - 1];
			print_array(tmp, max + 1);
			for (i_value = size - 1; (int) i_value >= 0; i_value--)
			{
				tmp[array[i_value]] = tmp[array[i_value]] - 1;
				result[tmp[array[i_value]]] = array[i_value];
			}
			for (i_value = 0; i_value < size; i_value++)
				array[i_value] = result[i_value];
			free(tmp);
			free(result);
}
