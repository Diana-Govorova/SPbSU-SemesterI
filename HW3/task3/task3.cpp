#include <stdio.h>

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

int mostFrequent(int array[], int length)
{
	int max = 1;
	int answer = array[0];
	int tmp = array[0];
	int counter = 1;
	for (int i = 1; i < length; i++)
	{
		if (array[i] == tmp)
		{
			counter++;
		}
		else
		{
			if (counter > max)
			{
				max = counter;
				answer = array[i - 1];
			}
			counter = 1;
			tmp = array[i];
		}
	}
	if (counter > max)
	{
		max = counter;
		answer = array[length - 1];
	}
	return answer;
}

bool test()
{
	int array1[]{ 43, 43, 6 };
	qSort(array1, 0, 2);
	const bool test1result = mostFrequent(array1, 3) == 43;

	int array2[]{ 1, 2, 3, 4, 5 };
	qSort(array2, 0, 4);
	const bool test2result = mostFrequent(array2, 5) == 1;

	return test1result && test2result;
}

int main()
{
	if (!test())
	{
		printf("All is bad\n");
		return -1;
	}
	const int length = 1;
	int* array = new int[length]{1};

	qSort(array, 0, length - 1);
	int answer = mostFrequent(array, length);
	printf("%d", answer);
	delete[] array;
	return 0;
}