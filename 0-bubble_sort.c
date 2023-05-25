#include "sort.h"

/**
 * swap - swap function for the value of the array
 * @a: first value for the swap
 * @b: second value for the swap
 *
*/
void swap(int *a, int *b)
{
	int temp;

	temp = *b;
	*b = *a;
	*a = temp;

}

/**
 * bubble_sort - main function for sorting data
 * @array: array of value need to be sort
 * @size: size of the array
 *
*/
void bubble_sort(int *array, size_t size)
{
	size_t index, j;

	if (array == NULL)
		return;

	for (index = 0; index < size - 1; index++)
	{
		for (j = 0; j < size - index - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
