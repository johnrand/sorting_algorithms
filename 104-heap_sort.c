#include "sort.h"

/**
 * sift_down - Repair the heap whose root element at index start
 * @array: Array rep the heap
 * @start: Index of root of heap
 * @end: Index of last element in heap
 * @size: Size of the array
 */

void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child, swap;
	int temp;

	while ((root * 2) + 1 <= end)
	{
		child = (root * 2) + 1;
		swap = root;

		if (array[swap] < array[child])
		{
			swap = child;
		}
		if (child + 1 <= end && array[swap] < array[child + 1])
		{
			swap = child + 1;
		}
		if (swap != root)
		{
			temp = array[root];
			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size);
			root = swap;
		}
		else
		{
			return;
		}
	}
}


/**
 * heap_sort - Sorts an array in ascending order
 * @array: Array to be sorted
 * @size: Size of the array
 */


void heap_sort(int *array, size_t size)
{
	int i, temp;

	/* Build heap by rearrange array */
	for (i = size / 2 - 1; i >= 0; i--)
	{
		sift_down(array, i, size - 1, size);
	}

	/* 1 by 1 extract an element from heap */
	for (i = size - 1; i > 0; i--)
	{
		/* Move current root to end */
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, 0, i - 1, size);
	}
}
