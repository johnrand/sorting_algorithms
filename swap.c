#include "sort.h"

/**
 * swap2values - A function that swaps two values
 * @x: Pointer to First value
 * @y: Pointer to Second value
 *
 * Returns: Void
 */

void swap2values(int *x, int *y)
{
	*y = *x ^ *y;
	*x = *x ^ *y;
	*y = *x ^ *y;
}
