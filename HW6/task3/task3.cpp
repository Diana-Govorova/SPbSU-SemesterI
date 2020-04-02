#include <stdio.h>
#include "stack.h"
#include <string.h>


char* expressionСonversion(const char* array, bool& isCorrect)
{
	StackElement* stack = nullptr;
	isCorrect = true;
	const int length = strlen(array);
	int count = 0;
	char* answer = new char[1000]{};
	for (int i = 0; i < length; i++)
	{
		if (array[i] >= '0' && array[i] <= '9')
		{
			answer[count] = array[i];
			count++;
		}
		if ((array[i] == '+') || (array[i] == '-'))
		{
			while (!isEmpty(stack) && top(stack) != '(')
			{
				answer[count] = pop(&stack);
				count++;
			}
			push(array[i], &stack);
		}
		if ((array[i] == '*') || (array[i] == '/'))
		{
			while (!isEmpty(stack) && ((top(stack) == '*') || (top(stack) == '/')))
			{
				answer[count] = pop(&stack);
				count++;
			}
			push(array[i], &stack);
		}
		if (array[i] == '(')
		{
			push(array[i], &stack);
		}
		if (array[i] == ')')
		{
			while (!isEmpty(stack) && (top(stack) != '('))
			{
				answer[count] = pop(&stack);
				count++;
			}
			if (!isEmpty(stack) && (top(stack) == '('))
			{
				pop(&stack);
			}
			else
			{
				isCorrect = false;
			}
		}
	}
	if (!isEmpty(stack))
	{
		if (top(stack) == '(')
		{
			isCorrect = false;
			while (!isEmpty(stack))
			{
				pop(&stack);
			}
			return answer;
		}
		answer[count] = pop(&stack);
		count++;
	}
	answer[count] = '\0';
	return answer;
}

bool test()
{
	bool isCorrect = true;
	const bool test1Result = strcmp("11+2*", expressionСonversion("(1+1)*2", isCorrect)) == 0;
	expressionСonversion(")", isCorrect);
	const bool test2Result = (!isCorrect);
	const bool test3Result = strcmp("12+34*5*+6+", expressionСonversion("1+2+3*4*5+6", isCorrect)) == 0;

	return test1Result && test2Result && test3Result;
}

int main()
{
	if (!test())
	{
		printf("All is bad\n");
		return -1;
	}
	bool isCorrect = true;
	printf("Please, enter string: ");
	char* array = new char[1000]{};
	scanf("%s", array);
	char* answer = expressionСonversion(array, isCorrect);
	if (isCorrect)
	{
		printf("%s", answer);
	}
	else
	{
		printf("String isnt correct");
	}
	delete[] answer;
	delete[] array;
	return 0;
}
