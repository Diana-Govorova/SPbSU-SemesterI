#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

enum class State
{
	WaitLetter,
	WaitLetterOfNumberOrTrait
};

bool isLetter(char* set)
{
	State state = State::WaitLetter;
	int index = 0;
	while (true)
	{
		switch (state)
		{
		case State::WaitLetter:
		{
			if ((set[index] >= 'A' && set[index] <= 'Z') || (set[index] >= 'a' && set[index] <= 'z'))
			{
				state = State::WaitLetterOfNumberOrTrait;
				break;
			}
			return false;
		}
		case State::WaitLetterOfNumberOrTrait:
		{
			if ((set[index] >= 'A' && set[index] <= 'Z') || (set[index] >= 'a' && set[index] <= 'z') || (set[index] >= '0' && set[index] <= '9') || (set[index] == '_'))
			{
				state = State::WaitLetterOfNumberOrTrait;
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
