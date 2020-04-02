#include <stdio.h>
#include "stack.h"
#include <string.h>

int calculateExpressionValue(const char* array, bool &isCorrect)
{
	StackElement* stack = nullptr;
	const int length = strlen(array);
	for (int i = 0; i < length; i++)
	{
		if (array[i] >= '0' && array[i] <= '9')
		{
			push(array[i] - '0', &stack);
		}
		else
		{
			int symbol1 = 0;
			int symbol2 = 0;

			if (isEmpty(stack))
			{
				isCorrect = false;
				return -1;
			}
			else
			{
				symbol1 = pop(&stack);
			}

			if (isEmpty(stack))
			{
				isCorrect = false;
				return -1;
			}
			else
			{
				symbol2 = pop(&stack);
			}

			if (array[i] == '+')
			{
				push(symbol2 + symbol1, &stack);
			}
			if (array[i] == '-')
			{
				push(symbol2 - symbol1, &stack);
			}
			if (array[i] == '*')
			{
				push(symbol2 * symbol1, &stack);
			}
			if (array[i] == '/')
			{
				push(symbol2 / symbol1, &stack);
			}
		}
	}
	int answer = pop(&stack);
	isCorrect = true;
	if (!isEmpty(stack))
	{
		isCorrect = false;
		while (!isEmpty(stack))
		{
			pop(&stack);
		}
		return -1;
	}
	return answer;
}

bool test()
{
	bool isCorrect = true;
	const bool test1Result = calculateExpressionValue("11+", isCorrect) == 2;
	bool test2Result = calculateExpressionValue("1+98-*", isCorrect) == -1;
	test2Result = test2Result && !isCorrect;

	return test1Result && test2Result;
}

int main()
{
	if (!test())
	{
		printf("All is bad\n");
		return -1;
	}
	char* array = new char[1000]{};
	scanf("%s", array);
	bool isCorrect = true;
	int answer = calculateExpressionValue(array, isCorrect);
	if (isCorrect)
	{
		printf("%d", answer);
	}
	else
	{
		printf("String isnt correct");
	}
	delete[] array;

	return 0;
}