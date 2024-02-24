#include "sort.h"

/**
 * _maximum - Find maximum value in the array
 * @array: the array
 * @size: size of array
 *
 * Return: maximum integer in the array.
 */

int _maximum(int *array, int size)
{
	int maximum, i;

	for (maximum = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maximum)
			maximum = array[i];
	}

	return (maximum);
}

/**
 * counting_sort - Sort an array of values
 * @array: the array to sort
 * @size: size of array.
 *
 * Return: Success
 */

void counting_sort(int *array, size_t size)
{
	int *count, *sorted, maximum, i;

	if (!array || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;
	maximum = _maximum(array, size);
	count = malloc(sizeof(int) * (maximum + 1));
	if (!count)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (maximum + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (maximum + 1); i++)
		count[i] += count[i - 1];
	print_array(count, maximum + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
