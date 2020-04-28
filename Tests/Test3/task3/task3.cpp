#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isLetter(char* set)
{
	int index = 0;
	int state = 0;
	while (true)
	{
		switch (state)
		{
		case 0:
		{
			if (set[index] >= 'A' && set[index] <= 'Z')
			{
				state = 1;
				break;
			}
			return false;
		}
		case 1:
		{
			if ((set[index] >= 'A' && set[index] <= 'Z') || (set[index] >= 'a' && set[index] <= 'z') || (set[index] >= '0' && set[index] <= '9') || (set[index] >= '_'))
			{
				state = 1;
				break;
			}
			if (set[index] == '\0')
			{
				return true;
			}
			return false;
		}
		}
		++index;
	}
}

int main()
{
	printf("Please, enter string: ");
	char* array = new char[1000]{};
	scanf("%s", array);
	(isLetter(array)) ? printf("String is letter\n") : printf("String isnt letter\n");
	delete[] array;
	return 0;
}
