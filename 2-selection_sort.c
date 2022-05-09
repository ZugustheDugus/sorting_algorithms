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
 * selection_sort - sort array of int ascending order using selection algorithm
 * @array: array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, idx;
	int min, flag = 0;

	if (array == NULL)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				idx = j;
				flag = 1;
			}
			if ((flag == 1) && (j == size - 1))
			{
				swap(&array[idx], &array[i]);
				print_array(array, size);
			}
		}
		flag = 0;
	}
}