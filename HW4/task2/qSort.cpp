#include "qSort.h"

void qSort(int* array, int first, int last)
{
	if (first < last)
	{
		int left = first;
		int right = last;
		int middle = array[(left + right) / 2];
		do
		{
			while (array[left] < middle)
			{
				left++;
			}
			while (array[right] > middle)
			{
				right--;
			}
			if (left <= right)
			{
				const int tmp = array[left];
				array[left] = array[right];
				array[right] = tmp;
				left++;
				right--;
			}
		} while (left <= right);
		qSort(array, first, right);
		qSort(array, left, last);
	}
}