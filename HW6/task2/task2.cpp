#include <stdio.h>
#include "stack.h"
#include <string.h>

char correspondingBracket(char bracket)
{
	if (bracket == '(')
	{
		return ')';
	}
	if (bracket == '{')
	{
		return '}';
	}
	if (bracket == '[')
	{
		return ']';
	}
}

bool checkBalance(char array[])
{
	StackElement* stack = nullptr;
	const int length = strlen(array);
	for (int i = 0; i < length; i++)
	{
		if (array[i] == '[' || array[i] == '(' || array[i] == '{')
		{
			push(array[i], &stack);
		}
		else
		{
			const char currentValue = pop(&stack);
			const char bracket = correspondingBracket(currentValue);
			if (array[i] != bracket)
			{
				return false;
			}
		}
	}
	bool isCorrect = true;
	if (!isEmpty(stack))
	{
		isCorrect = false;
		while (!isEmpty(stack))
		{
			pop(&stack);
		}
		return false;
	}
	return true;
}

bool test()
{
	char array1[5]{"(())"};
	const bool test1Result = checkBalance(array1);

	char array2[6]{"{{[}]"};
	const bool test2Result = !checkBalance(array2);

	char array3[5]{"(({}"};
	const bool test3Result = !checkBalance(array3);

	return test1Result && test2Result && test3Result;
}


int main()
{
	if (!test())
	{
		printf("All is bad\n");
		return -1;
	}
	printf("Please, enter string");
	char* array = new char[1000]{};
	scanf("%s", array);
	bool answer = checkBalance(array);
	if (!answer)
	{
		printf("Bracket balanse isnt correct");
	}
	else
	{
		printf("Bracket balanse is correct");
	}
	delete[] array;
	return 0;
}