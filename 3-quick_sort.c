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
 * partition - Lomuto parition
 * @array: array to start
 * @low: lowest value
 * @hi: highest value
 * @size: size of array
 * Return: pivot
 *
 */

int partition(int *array, ssize_t low, ssize_t hi, size_t size)
{
	ssize_t i, j;
	int pivot;

	pivot = array[hi];
	i = low - 1;
	for (j = low; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[hi] < array[i + 1])
	{
		swap(&array[i + 1], &array[j]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * lomuto_scheme - uses lomuto scheme to sort array
 * @arr: array to be sorted
 * @low: lowest value
 * @high: highest value -- pivot
 * @size: size of the array
 */
void lomuto_scheme(int *arr, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = partition(arr, low, high, size);
		lomuto_scheme(arr, low, i - 1, size);
		lomuto_scheme(arr, i + 1, high, size);
	}
}

/**
 * quick_sort - sorts arr of ints in ascending order using quick sort
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	lomuto_scheme(array, 0, size - 1, size);
}