#include <stdio.h>
#include "qSort.h"

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
	int array1[]{ 43, 6, 43 };
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
	FILE* in = fopen("mostFrequent.txt", "r");
	int count = 0;
	int s = 0;
	while (!feof(in))
	{
		fscanf(in, "%d", &s);
		count++;
	}
	fclose(in);
	in = fopen("mostFrequent.txt", "r");
	int* array = new int[count];
	for (int i = 0; i < count; i++)
	{
		fscanf(in, "%d", &array[i]);
	}
	fclose(in);
	qSort(array, 0, count - 1);
	int answer = mostFrequent(array, count);
	printf("%d", answer);
	delete[] array;
	return 0;
}