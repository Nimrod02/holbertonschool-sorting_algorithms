#include "sort.h"

/**
 * swap - swap two values
 * @a: first element to swap
 * @b: second element to swap
 */

void swapValues(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto - function to make partition lomuto
 * @array: array containing data
 * @size: size of the array
 * @low: index 0
 * @rSize: The real size of the array
 */
size_t lomuto(int *array, int low, int size, size_t rSize)
{
	int index2, index = low;
	int pivot = array[size];

	index2 = low;
	while (index2 < size)
	{
		if (array[index2] <= pivot)
		{
			swapValues(&array[index], &array[index2]);
			if (array[index] != array[index2])
				print_array(array, rSize);
			index++;
		}
		index2++;
	}
	swapValues(&array[index], &array[size]);
	if (array[index] != array[size])
		print_array(array, rSize);
	return (index);

}

/**
 * quick - sort an array in ascending order
 * @array: array containing data
 * @size: size of the array
 * @low: index 0
 * @rSize: The real size of the array
 */
void quick(int *array, int low, int size, size_t rSize)
{
	int part;

	if (low >= size)
		return;

	part = lomuto(array, low, size, rSize);

	quick(array, low, part - 1, rSize);
	quick(array, part + 1, size, rSize);

}

/**
 * quick_sort - sort an array in ascending order
 * @array: array containing data
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	size_t g_size;

	if (!array || size < 1)
		return;
	g_size = size;
	quick(array, 0, size - 1, g_size);
}
