#include <stdio.h>

int main()
{
	int length = 0;
	printf("Please, enter length\n");
	scanf("%d", &length);
	int* mas = new int[length] {};
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		scanf("%d", &mas[i]);
	}
	for (int i = 0; i < length; i++)
	{
		if (mas[i] == 0)
		{
			count++;
		}
	}
	delete[] mas;
	printf("%d", count);
	return 0;
}