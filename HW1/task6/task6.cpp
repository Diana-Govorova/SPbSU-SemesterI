#include <stdio.h>
#include <string.h>

int entries(const char* s, const char* s1)
{
	const int lengthOfS = strlen(s);
	const int lengthOfS1 = strlen(s1);

	int counter = 0;
	for (int i = 0; i < lengthOfS; ++i)
	{
		int j = 0;
		for (; j < lengthOfS1;)
		{
			if (s[i + j] == s1[j])
			{
				j++;
			}
			else
			{
				break;
			}
		}
		if (j == lengthOfS1)
		{
			++counter;
		}
	}
	return counter;
}

bool test()
{
	const bool test1Result = entries("abcde", "der") == 0;
	const bool test2Result = entries("ololol", "lo") == 2;
	const bool test3Result = entries("abcde", "de") == 1;
	return test1Result && test2Result && test3Result;
}

int main()
{
	if (!test())
	{
		printf("All is bad\n");
		return -1;
	}
	char s[100];
	fgets(s, 100, stdin);
	s[strlen(s) - 1] = '\0';

	char s1[100];
	fgets(s1, 100, stdin);
	s1[strlen(s1) - 1] = '\0';

	const int result = entries(s, s1);
	printf("%d", result);
}