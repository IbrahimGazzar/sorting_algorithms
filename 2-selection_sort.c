#include "sort.h"

/**
 * selection_sort - sorts an integer array using the
 * selcetion sort algorithm. In this algorithm, the
 * elements of the array are picked squentially and
 * compared with every element ahead in the array. If
 * the picked element is greater than the element it's
 * being compared with, a swapping occurs. The smaller
 * element then continues the comparison process, swapping
 * on finding smaller elements as well. This goes on until
 * the second to last element is compared with the last one,
 * after which the array becomes properly sorted.
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: no return value
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_ind;
	int temp, minim;

	for (i = 0; i < size - 1; i++)
	{
		minim = array[i];
		min_ind = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < minim)
			{
				minim = array[j];
				min_ind = j;
			}
		}
		if (min_ind != i)
		{
			temp = array[i];
			array[i] = array[min_ind];
			array[min_ind] = temp;
			print_array(array, size);
		}
	}
}
