#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int array[], int a, int b)

{
	const int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

void output(int a[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


void arrayReordering(int array[], int length)
{
	int i = 1;
	int j = length - 1;
	while (i < j)
	{
		while (array[j] >= array[0] && i < j)
		{
			j--;
		}
		while (array[i] < array[0] && i < j)
		{
			i++;
		}
		swap(array, i, j);
	}
}

bool isCorrectlyReordered(int array[], int length)
{
	const int pivot = array[0];
	int i = 1;
	while (array[i] < pivot)
	{
		i++;
	}
	for (; i < length; i++)
	{
		if (array[i] < pivot)
		{
			return false;
		}
	}
	return true;
}

bool test()
{
	int array1[]{ 43, 89, 5, 7, 45, 67, 234 };
	arrayReordering(array1, 7);
	const bool test1result = isCorrectlyReordered(array1, 7);

	int array2[]{ 1, 2, 3, 4, 5 };
	arrayReordering(array2, 5);
	const bool test2result = isCorrectlyReordered(array2, 5);
	return test1result && test2result;
}

int main()
{
	if (!test())
	{
		printf("All is bad\n");
		return -1;
	}
	int length = 5;
	int* array = new int[length] {};
	srand((unsigned)time(nullptr));
	for (int i = 0; i < length; i++)
	{
		array[i] = rand() % 10 + 1;
	}
	output(array, length);
	printf("\n");
	arrayReordering(array, length);
	output(array, length);
	delete[] array;
	return 0;
}