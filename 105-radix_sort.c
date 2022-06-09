#include "sort.h"

/**
 * get_max - gets highest element of array
 * @array: the array
 * @size: size of array
 * Return: Max
 */

int get_max(int *array, int size)
{
	int i;
	int max = array[0];

	for (i = 0; i < size; ++i)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * _calloc - malloc and fill an array
 * @n: size of array
 * Return: pointer to array
 */
int *_calloc(int n)
{
	int j;
	int *new;

	new = malloc(sizeof(int) * (n));
	if (!new)
	{
		return (NULL);
	}
		/* fill empty array */
	for (j = 0; j < n; j++)
		new[j] = 0;
	return (new);
}

/**
 * countSort - Count sort
 * @arr: array
 * @size: size
 * @exp: exponet
 */
void countSort(int *arr, int size, int exp)
{
	int *count, *output, i;

	count = _calloc(10);
	if (!count)
		return;

	for (i = 0; i < size; i++)
		count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] = count[i] + count[i - 1];
	output = malloc(sizeof(int) * (size));
	if (!output)
		return;
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
		arr[i] = output[i];
	free(output);
	free(count);
}

/**
 * radix_sort - radix sort implemnation
 * @size: size of array
 * @array: array to sort
 *
 */
void radix_sort(int *array, size_t size)
{

	int exp, max;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
		print_array(array, size);
	}

}
