#include "sort.h"

/**
 * partition - partition the array into two arrays
 * @array: array to be partitioned
 * @low: start of the array
 * @high: end of the array
 * @size: size of the array
 *
 * Return: pivot index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = low - 1, j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i < j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_helper - uses the quicksort function
 * by taking both a start and end to the array
 *
 * @array: array to be sorted
 * @low: start of the array
 * @high: end of the array
 * @size: size of the array
 *
 * Return: no return value
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivot_ind;

	if (low < high)
	{
		pivot_ind = partition(array, low, high, size);
		quick_sort_helper(array, low, pivot_ind - 1, size);
		quick_sort_helper(array, pivot_ind + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array using the quicksort
 * algorithm, in which the last element of the array
 * is chosen, then it's compared with the other elements
 * until it's put in its correct position. From there, the
 * array is partitioned into two arrays, the array before
 * the pivot, and the array after it, and then quicksorting
 * is applied to each subarray. The dividing action continues
 * until each subarray is one element long, and by then the
 * array becomes properly sorted.
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: no return value
 */
void quick_sort(int *array, size_t size)
{
	if (size <= 1)
		return;
	quick_sort_helper(array, 0, (int)size - 1, size);
}
