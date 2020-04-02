#include <stdio.h>
#include <math.h>

bool isPrimeNumber(int x)
{
	bool isPrime = true;
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
		{
			isPrime = false;
		}
	}
	return isPrime;
}

int main()
{
	int fixed = 0;
	scanf("%i", &fixed);
	for (int i = 1; i <= fixed; i++)
	{
		bool answer = isPrimeNumber(i);
		if (answer)
		{
			printf("%i ", i);
		}
	}
}