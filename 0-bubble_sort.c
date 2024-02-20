#include "sort.h"

/**
 * bubble_sort - A function that sorts the array of size
 * @array: A pointer to the array to sort
 * @size: The size of the array
 *
 * Return: Always(0) on success
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int swapped;

	do {
		swapped = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				/* swap the values */
				swap2values(&array[i - 1], &array[i]);
				swapped = 1;

				/* print array after swapping */
				print_array(array, size);
			}
		}
	} while (swapped);
}
