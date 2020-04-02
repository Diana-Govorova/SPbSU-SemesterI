#include <stdio.h>

int fibRecursively(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return fibRecursively(n - 1) + fibRecursively(n - 2);
	}
}

int fibIteratively(int n)
{
	int fib1 = 0;
	int	fib2 = 1;
	switch (n)
	{
	case 0:
		return 0;
	case 1:
		return 1;
	default:
		while (n > 1)
		{
			const int tmp = fib2;
			fib2 = fib1 + fib2;
			fib1 = tmp;
			n--;
		}
		return fib2;
	}
}


bool test1()
{
	int n = 0;
	const bool test1result = fibRecursively(n) == 0;

	int k = 6;
	const bool test2result = fibRecursively(k) == 8;
	return test1result && test2result;
}

bool test2()
{
	int g = 0;
	const bool test1result = fibIteratively(g) == 0;

	int h = 6;
	const bool test2result = fibIteratively(h) == 8;
	return test1result && test2result;
}

int main()
{
	if (!test1() && !test2())
	{
		printf("All is bad\n");
		return -1;
	}

	int n = 0;
	scanf_s("%d", &n);
	if (n < 0)
	{
		printf("Error");
		return -1;
	}

	int answer1 = fibIteratively(n);
	printf("%d\n", answer1);
	int answer2 = fibRecursively(n);
	printf("%d", answer2);
	return 0;
}