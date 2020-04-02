#include <stdio.h>

int main()
{
	int length = 28;
	int* tickets = new int[length] {};
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				sum = i + j + k;
				tickets[sum]++;
			}
		}
	}
	int quantity = 0;
	for (int i = 0; i < 28; i++)
	{
		quantity = quantity + (tickets[i] * tickets[i]);
	}
	delete[] tickets;
	printf("%d", quantity);
	return 0;
}