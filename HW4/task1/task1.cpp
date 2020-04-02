#include <stdio.h>
#include <locale.h>

void numberToArray(int x, int array[], int length)
{
	int power = 1;
	for (int i = length - 1; i >= 0; i--)
	{
		array[i] = (x & power) != 0 ? 1 : 0;
		power = power * 2;
	}
}

void revers(int array[], int size)
{
	for (int i = 0; i < size / 2; ++i)
	{
		int tmp = array[i];
		array[i] = array[size - i - 1];
		array[size - i - 1] = tmp;
	}
}

int min(int a, int b)
{
	return (a > b ? b : a);
}

int max(int a, int b)
{
	return (a > b ? a : b);
}

int* maxArray(int array1[], int a, int array2[], int b)
{
	return (a > b ? array1 : array2);
}

int additionNumbers(int array1[], int length1,  int array2[], int length2, int array3[])
{
	int remainderOfTheDivision = 0;
	revers(array1, length1);
	revers(array2, length2);
	int length = min(length2, length1);
	int length3 = max(length1, length2);
	for (int i = 0; i < length; ++i)
	{
		remainderOfTheDivision = remainderOfTheDivision + array1[i] + array2[i];
		array3[i] = remainderOfTheDivision % 2;
		remainderOfTheDivision /= 2;
	}
	int* array = maxArray(array1, length1, array2, length2);
	for (int i = length; i < length3; i++)
	{
		remainderOfTheDivision = remainderOfTheDivision + array[i];
		array3[i] = remainderOfTheDivision % 2;
		remainderOfTheDivision /= 2;
	}
	revers(array3, length3);
	return length3;
}

void output(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d", array[i]);
	}
}

int arrayToNumber(int array[], int length)
{
	int x = 0;
	int power = 1;
	for (int i = length - 1; i >= 0; i--)
	{
		x = x | (array[i] == 0 ? 0 : power);
		power = power * 2;
	}
	return x;
}

bool testNumberToArray()
{
	int array1[3]{};
	numberToArray(3, array1, 3);
	const bool test1Result = (array1[0] == 0) && (array1[1] == 1) && (array1[2] == 1);

	int array2[8]{};
	numberToArray(-3, array2, 8);
	const bool test2Result = (array2[0] == 1) && (array2[1] == 1) && (array1[2] == 1) && (array2[3] == 1) && (array2[4] == 1)
		&& (array2[5] == 1) && (array2[6] == 0) && (array2[7] == 1);
	
	return  test1Result && test2Result;
}

bool testAdditionNumbers()
{
	int array1[8]{0, 0, 0, 0, 0, 0, 1, 1};
	int array2[8]{1, 1, 1, 1, 1, 1, 0, 0};
	int array3[10]{};
	const bool test1Result = additionNumbers(array1, 3, array2, 8, array3) == 8;
	for (int i = 0; i < 8; i++)
	{
		if (array3[i] != 1)
		{
			return false;
		}
	}
	return test1Result;
}

bool testArrayToNumber()
{
	int array1[3]{ 0, 1, 1 };
	const bool test1Result = arrayToNumber(array1, 3) == 3;

	int array2[8]{ 1, 1, 1, 1, 1, 1, 0, 1 };
	const bool test2Result = arrayToNumber(array2, 8) == -3;

	return  test1Result && test2Result;
}

int main()
{
	if (!testAdditionNumbers() && !testNumberToArray() && !testArrayToNumber())
	{
		printf("All is bad\n");
		return -1;
	}
	setlocale(LC_ALL, "Rus");
	int number1 = 0;
	int number2 = 0;
	printf("Пожалуйста введите число1:");
	scanf("%d", &number1);
	printf("Пожалуйста введите число2:");
	scanf("%d", &number2);
	int* array1 = new int[sizeof(int) * 8]{};
	int* array2 = new int[sizeof(int) * 8]{};
	int* array3 = new int[sizeof(int) * 8]{};
	printf("1 число в 2 сс: ");
	numberToArray(number1, array1, sizeof(int) * 8);
	output(array1, sizeof(int) * 8);
	printf("\n");
	printf("2 число в 2 сс: ");
	numberToArray(number2, array2, sizeof(int) * 8);
	output(array2, sizeof(int) * 8);
	printf("\n");
	printf("Сумма чисел в 2 сс: ");
	int length3 = additionNumbers(array1, sizeof(int) * 8, array2, sizeof(int) * 8, array3);
	output(array3, length3);
	printf("\n");
	int answer = arrayToNumber(array3, length3);
	printf("Сумма чисел в 10 сс: ");
	printf("%d", answer);
	delete[] array1;
	delete[] array2;
	delete[] array3;
	return 0;
}