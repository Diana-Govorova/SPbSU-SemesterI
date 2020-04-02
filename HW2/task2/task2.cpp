#include <stdio.h>

int powerInForehead(int x, int y)
{
	int answer = 1;
	for (int i = 0; i < y; ++i)
	{
		answer = answer * x;
	}
	return answer;
}

int binPower(int number, int power)
{
	if (power == 0)
	{
		return 1;
	}
	if (power % 2 == 1)
	{
		return binPower(number, power - 1) * number;
	}
	else
	{
		const int b = binPower(number, power / 2);
		return b * b;
	}
}

bool test1()
{
	const bool test1result = powerInForehead(2, 3) == 8;

	const bool test2result = powerInForehead(0, 5) == 0;

	const bool test3Result = powerInForehead(6, 0) == 1;
	return test1result && test2result && test3Result;
}

bool test2()
{
	const bool test1Result = binPower(2, 3) == 8;

	const bool test2Result = binPower(0, 5) == 0;

	const bool test3Result = binPower(6, 0) == 1;
	return test1Result && test2Result && test3Result;
}

int main()
{
	if (!test1() && !test2())
	{
		printf("All is bad\n");
		return -1;
	}

	int number = 0;
	int power = 0;
	scanf_s("%d", &number);
	scanf_s("%d", &power);

	const int answer1 = powerInForehead(number, power);
	printf("%d\n", answer1);
	const int answer2 = binPower(number, power);
	printf("%d\n", answer2);
	return 0;
}