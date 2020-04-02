#include <stdio.h>
#include <math.h>

int main()
{
	int a = 0;
	int b = 0;
	printf("Please enter the numbers a and b");
	scanf("%d %d", &a, &b);
	int sig = 0;
	if (a * b > 0)
	{
		sig = 1;
	}
	a = abs(a);
	b = abs(b);
	if (b == 0)
	{
		if (a == 0)
		{
			printf("0");
		}
		else
		{
			printf("Error");
		}
		return 0;
	}
	int answer = 0;
	while (a > b)
	{
		answer++;
		a = a - b;
	}
	printf("Incomplete quotient=");
	if (sig == 1)
	{
		answer == answer + 1;
		printf("%d", answer);
	}
	else

	{
		answer = -answer - 1;
		printf("%d", answer);
	}
	return 0;
}