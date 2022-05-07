#include "sort.h"


/**
 * merge_sort_and_print - does final merge and printing
 * @array: array to be sorted
 * @temp: temp array
 * @left: left index of array
 * @mid: mid index of array
 * @right: right index of array
 */

void merge_sort_and_print(int *array, int *temp, int left, int mid, int right)
{
	int tempLeft = left, tempRight = mid + 1, current = left;
	int i, current_print;

	for (i = left; i <= right; i++)
		temp[i] = array[i];
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + tempLeft, tempRight - tempLeft);
	printf("[right]: ");
	print_array(array + tempRight, right + 1 - tempRight);
current_print = current;
	while (tempLeft <= mid || tempRight <= right)
	{
		if (tempLeft <= mid && tempRight <= right)
		{
			if (temp[tempLeft] <= temp[tempRight])
				array[current] = temp[tempLeft], current++, tempLeft++;
			else
				array[current] = temp[tempRight], current++, tempRight++;
		}
		else if (tempLeft >= mid && tempRight <= right)
			array[current] = temp[tempRight], current++, tempRight++;
		else
			array[current] = temp[tempLeft], current++, tempLeft++;
	}
	printf("[Done]: ");
	print_array(array + current_print, right + 1 - left);


}


/**
 * recursive_merg_sort - recrusivly calls itself
 * @array: array
 * @temp: temp array
 * @left: left part of array
 * @right: right part of array
 */
void recursive_merg_sort(int *array, int *temp, int left, int right)
{
	int mid;

	if (left < right && array)
	{
		mid = (left + right - 1) / 2;
		recursive_merg_sort(array, temp, left, mid);
		recursive_merg_sort(array, temp, mid + 1, right);
		merge_sort_and_print(array, temp, left, mid, right);
	}
}


/**
 * merg_sort - merge sort algo
 * @array: array to be sorted
 * @size: size of the array to be sorted
 * Return: void
 *
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size <= 1)
		return;
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;
	recursive_merg_sort(array, temp, 0, size - 1);
	free(temp);
}