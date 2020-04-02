#include <stdio.h>
#include "stringAnalyzer.h"

bool test()
{
	char string1[] = "345.67E+666";
	bool test1 = isNumber(string1);

	char string2[] = "134.+568";
	bool test2 = !isNumber(string2);

	char string3[] = "12E54";
	bool test3 = isNumber(string3);

	return test1 && test2 && test3;
}

int main()
{
	if (!test())
	{
		printf("All is bad\n");
		return -1;
	}

	printf("Please, enter string: ");
	char* array = new char[1000]{};
	scanf("%s", array);
	(isNumber(array)) ? printf("String is number\n") : printf("String isnt number\n");
	delete[] array;
	return 0;
}