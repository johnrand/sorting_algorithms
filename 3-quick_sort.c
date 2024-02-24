#include "sort.h"

/**
 * swap - Swaps two integers
 * @x: Pointer to the first integer
 * @y: Pointer to the second integer
 */

void swap(int *x, int *y)
{
	*y = *x ^ *y;
	*x = *x ^ *y;
	*y = *x ^ *y;
}

/**
 * _partition - Partitions the array and returns the index of the pivot
 * @array: array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 *
 * Return: Index of the pivot
 */

int _partition(int *array, int low, int high, size_t size)
{
	int *pivot, i, j;

	pivot = array + high;
	for (i = j = low; j < high; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}

	return (i);
}

/**
 * qsort_rec - Recursively sorts the array
 * @array: array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */

void qsort_rec(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = _partition(array, low, high, size);
		qsort_rec(array, low, pi - 1, size);
		qsort_rec(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: Size of the array
 *
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	qsort_rec(array, 0, size - 1, size);
}
