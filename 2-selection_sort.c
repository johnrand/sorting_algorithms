#include "sort.h"

/**
 * selection_sort - Sort an array of integers
 * @array: the array.
 * @size: The size of the array.
 *
 * Return: the array after each swap.
 */

void selection_sort(int *array, size_t size)
{
	int *smallest, temp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		smallest = array + i;
		for (j = i + 1; j < size; j++)
			smallest = (array[j] < *smallest) ? (array + j) : smallest;

		if ((array + i) != smallest)
		{
			temp = *smallest;
			*smallest = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
