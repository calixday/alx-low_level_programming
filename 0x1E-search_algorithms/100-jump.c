#include "search_algos.h"

/**
  * jump_search - Searches for a value in a sorted array
  *               of integers using jump search.
		  Uses the square root of the array size as the jump step.
  */
int jump_search(int *array, size_t size, int value)
{
	size_t i, jump, s;

	if (array == NULL || size == 0)
		return (-1);

	s = sqrt(size);
	for (i = jump = 0; jump < size && array[jump] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", jump, array[jump]);
		i = jump;
		jump += s;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, jump);

	jump = jump < size - 1 ? jump : size - 1;
	for (; i < jump && array[i] < value; i++)
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	return (array[i] == value ? (int)i : -1);
}
