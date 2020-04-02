#include <stdio.h>
#include <climits>

void swap(int array[], int a, int b)

{
	const int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

void bubble(int a[], int length)
{
	bool wasntSwap = true;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				wasntSwap = false;
				swap(a, j, j + 1);
			}
		}
	}
}

bool isSorted(int a[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		if (a[i] > a[i + 1])
		{
			return false;
		}
	}
	return true;
}

void countingSort(int a[], int length)
{
	int max = INT_MIN;
	int min = INT_MAX;
	for (int i = 0; i < length; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int* auxiliaryArray = new int[max - min + 1]{};
	for (int i = 0; i < length; i++)
	{
		auxiliaryArray[a[i] - min]++;
	}
	int i = 0;
	for (int j = 0; j < max - min + 1; j++)
	{
		while (auxiliaryArray[j] != 0)
		{
			a[i] = j + min;
			auxiliaryArray[j]--;
			i++;
		}
	}
	delete[] auxiliaryArray;
}



bool test()
{
	int array1[]{ 43, 89, 5, 7, 45, 67, 234 };
	const bool test1Result = !isSorted(array1, 7);

	int array2[]{ 1, 2, 3, 4, 5 };
	const bool test2Result = isSorted(array2, 5);
	return test1Result && test2Result;
}

bool testBubble()
{
	int array1[]{ 43, 89, 5, 7, 45, 67, 234 };
	bubble(array1, 7);
	const bool testBubble1Result = isSorted(array1, 7);

	int array2[]{ 1, 2, 3, 4, 5 };
	bubble(array2, sizeof(array2) / sizeof(int));
	const bool testBubble2Result = isSorted(array2, sizeof(array2) / sizeof(int));

	int array3[]{ 1 };
	bubble(array3, 1);
	const bool testBubble3Result = isSorted(array3, sizeof(array3) / sizeof(int));
	return testBubble1Result && testBubble2Result && testBubble3Result;
}

bool testCountingSort()
{
	int array1[]{ 43, 89, 5, 7, 45, 67, 234 };
	countingSort(array1, 7);
	const bool testCountingSort1Result = isSorted(array1, 7);

	int array2[]{ 1, 2, 3, 4, 5 };
	countingSort(array2, sizeof(array2) / sizeof(int));
	const bool testCountingSort2Result = isSorted(array2, sizeof(array2) / sizeof(int));

	int array3[]{ 1 };
	countingSort(array3, 1);
	const bool testCountingSort3Result = isSorted(array3, sizeof(array3) / sizeof(int));
	return testCountingSort1Result && testCountingSort2Result && testCountingSort3Result;
}



void output(int a[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	if (!test() || !testBubble() || !testCountingSort())
	{
		printf("All is bad\n");
		return -1;
	}
	int length = 7;
	int* mas = new int[length] {3, 4, 1, 5, 68, 54, 888};
	int* mas1 = new int[length] {3, 4, 1, 5, 68, 54, 888};
	bubble(mas, length);
	countingSort(mas1, length);
	output(mas, length);
	output(mas1, length);
	delete[] mas;
	delete[] mas1;
	return 0;
}