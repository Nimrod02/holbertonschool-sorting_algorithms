#include "sort.h"
/**
 * selection_sort -sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: array of integers
 * @size: size of the array
 **/
void selection_sort(int *array, size_t size)
{
	size_t index = 0;
	size_t index2 = 0;
	int tmp, min, flag;

	if (array == NULL || size < 1)
		return;
	while (index < size)
	{
		min = array[index];
		flag = 0;
		while (index2 < size)
		{
			if (array[index2] < min)
			{
				min = array[index2];
				flag = index2;
			}
			index2++;
		}
		if (flag)
		{
			tmp = array[index];
			array[index] = array[flag];
			array[flag] = tmp;
			print_array(array, size);
		}
		index++;
		index2 = index;
	}
}
