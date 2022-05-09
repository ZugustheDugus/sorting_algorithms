#include "sort.h"
/**
 * swap - swaps two variables
 * @i: first one to swap
 * @j: second one to swap
 */

void swap(int *i, int *j)
{
	int tmp = *i;

	*i = *j;
	*j = tmp;
}

/**
 * bubble_sort - sorts an array using the bubble sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}