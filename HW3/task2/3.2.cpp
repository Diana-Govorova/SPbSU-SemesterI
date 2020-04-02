#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

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
		} 
		while (left <= right);
		qSort(array, first, right);
		qSort(array, left, last);
	}
}

int search(int array[], int length, int a)
{
	int left = 0;
	int right = length - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (a < array[middle])
		{
			right = middle - 1;
		}
		else if (a > array[middle])
		{
			left = middle + 1;
		}
		else
		{
			return middle;
		}
	}
	return -1;
}

void output(int a[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


bool test()
{
	int array1[]{ 43, 43, 6 };
	qSort(array1, 0, 2);
	const bool test1result = search(array1, 3, 6) == 0;

	int array2[]{ 1, 2, 3, 4, 5 };
	qSort(array2, 0, 4);
	const bool test2result = search(array2, 5, 7) == -1;

	int array3[]{ 1 };
	qSort(array3, 0, 0);
	const bool test3result = search(array3, 1, 1) == 0;
	return test1result && test2result && test3result;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	if (!test())
	{
		printf("All is bad\n");
		return -1;
	}
	const int n = 5;
	const int k = 3;
	int* array = new int[n] {};
	srand((unsigned)time(nullptr));
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 10 + 1;
	}
	qSort(array, 0, 4);
	output(array, 5);

	for (int i = 0; i < k; i++)
	{
		int number = rand() % 10 + 1;
		printf("%d\n", number);
		int index = search(array, n, number);
		if (index == -1)
		{
			printf("the number in the array is not contained\n");
		}
		else
		{
			printf("%d ", index);
			printf("число в массиве содержится");
		}
	}
	delete[] array;
	return 0;
}