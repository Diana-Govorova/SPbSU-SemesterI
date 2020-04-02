#include <stdio.h>
#include <string.h>

int algoritmKMP(char* string, char* sample, char* delimiter)
{
	int lengthOfSample = strlen(sample);
	int lengthOfString = strlen(string);
	int lengthOfDelimiter = strlen(delimiter);
	const int commonLength = lengthOfDelimiter + lengthOfSample + lengthOfString +1;
	char* commonSrting = new char[commonLength] {};
	int arrayOfPrefix[2003]{};
	strcat(commonSrting, sample);
	strcat(commonSrting, delimiter);
	strcat(commonSrting, string);

	arrayOfPrefix[0] = 0;
	for (int i = 1; i < commonLength; i++)
	{
		int j = arrayOfPrefix[i - 1];
		while ((j > 0) && (commonSrting[i] != commonSrting[j]))
		{
			j = arrayOfPrefix[j - 1];
		}
		if (commonSrting[i] == commonSrting[j])
		{
			j++;
		}
		arrayOfPrefix[i] = j;
	}
	int answer = 0;
	delete[] commonSrting;
	for (int i = 0; i < commonLength; i++)
	{
		if (arrayOfPrefix[i] == lengthOfSample)
		{
			answer = i - 2 * lengthOfSample + 1;
			return answer;
		}
	}
	return -1;
}
