#include <stdio.h>
#include <string.h>
#include "KMP.h"

bool compareOfArray(int array1[], int array2[], int length1, int length2)
{
	if (length1 != length2)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < length1; i++)
		{
			if (array1[i] != array2[i])
			{
				return false;
			}
		}
		return true;
	}
}

bool test()
{
	char* string = new char[5]{ "rtyu" };
	char* sample = new char[3]{ "ty" };
	char* delimiter = new char[2]{ "@" };

	int answer = algoritmKMP(string, sample, delimiter);
	delete[] sample;
	delete[] string;
	delete[] delimiter;
	const bool test1Result = (answer == 2);

	return test1Result;
}

int main()
{
	if (!test())
	{
		printf("All is bad\n");
		return -1;
	}
	char* string = new char[100]{};
	printf("enter string: ");
	scanf("%s", string);
	char* sample = new char[300]{};
	printf("enter sample: ");
	scanf("%s", sample);
	char* delimiter = new char[2]{ };
	printf("enter delimiter: ");
	scanf("%s", delimiter);
	printf("\n");
	int answer = algoritmKMP(string, sample, delimiter);
	delete[] sample;
	delete[] string;
	delete[] delimiter;
	if (answer != -1)
	{
		printf("First entry: ");
		printf("%d", answer);
	}
	else
	{
		printf("error, sample doesnt found! ");

	}
	return 0;
}