#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * @array: Array to sort
 * @size: Size of the array
 */

void shell_sort(int *array, size_t size)
{
	int intval = 1;
	int i, j, temp;

	while (intval <= (int)(size / 3))
	{
		intval = intval * 3 + 1;
	}

	while (intval > 0)
	{
		print_array(array, size);

		for (i = intval; i < (int)size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= intval && array[j - intval] > temp)
			{
				array[j] = array[j - intval];
				j -= intval;
			}
			array[j] = temp;
		}
		intval = (intval - 1) / 3;
	}
}
