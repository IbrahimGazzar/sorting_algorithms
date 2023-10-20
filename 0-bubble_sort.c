#include "sort.h"

/**
 * bubble_sort - sorts an array using the bubble sort
 * algorithm, which goes through an array n times, comparing
 * each two adjacent elements and sorts them
 * @array: array to be sorted
 * @size: size of @array
 *
 * Return: no return value
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (size <= 1)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
