#include "sort.h"
#include <stdlib.h>

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
 * count_sort - function to perform counting sort based on significant digit
 * @arr: array
 * @n: size of array
 * @exp: exp
 *
 */

void count_sort(int arr[], int n, int exp)
{
	int *output = malloc(n * sizeof(int));
	int i;
	int count[10] = {0};

	if (output == NULL)
		return;

	/* Store count of occurrences */
	for (i = 0; i < n; i++)
	{
		count[(arr[i] / exp) % 10]++;
	}

	/* Change count[i] that count[i] contains actual pos of digit in output */
	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	/* Build output array */
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	/* Copy outpt2arr[] so that arr[] contain sort nums based on curr digit */
	for (i = 0; i < n; i++)
	{
		arr[i] = output[i];
	}
	free(output);
}

/**
 * radix_sort - sorts an array in ascending order
 * @array: array to sort
 * @size: size of array
 *
 */

void radix_sort(int *array, size_t size)
{
	int exp, max = _maximum(array, size);

	/* Perform counting sort for every digit */
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		/* Print array after each pass */
		print_array(array, size);
	}
}
