#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int array[], int a, int b)

{
	const int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}


void insertionSort(int array[], int first, int last)
{
	int i, key, j;
	for (i = first + 1; i <= last; i++)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}

void qSort_insert(int* array, int first, int last)
{
	if (first < last)
		if (last - first > 10)
		{
			int left = first, right = last, middle = array[(left + right) / 2];
			do
			{
				while (array[left] < middle)
					left++;
				while (array[right] > middle)
					right--;
				if (left <= right)
				{
					int tmp = array[left];
					array[left] = array[right];
					array[right] = tmp;
					left++;
					right--;
				}
			} while (left <= right);
			qSort_insert(array, first, right);
			qSort_insert(array, left, last);
		}
		else insertionSort(array, first, last);
}

int main() {
	int length = 13;
	int* array = new int[length] {};
	srand((unsigned)time(nullptr));
	for (int i = 0; i < length; i++)
	{
		array[i] = rand() % 10 + 1;
	}
	for (int i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	qSort_insert(array, 0, length - 1);
	printf("\n");
	for (int i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}
