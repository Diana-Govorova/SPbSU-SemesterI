#include <stdio.h>
#include <string.h>
int main()
{
	int count = 0;
	char mas[1000];
	scanf("%s", mas);
	for (int i = 0; i < strlen(mas); i++)
	{
		if (mas[i] == '(')
		{
			count++;
		}
		if (mas[i] == ')')
		{
			count--;
		}
		if (count < 0)
		{
			break;
		}
	}
	if (count == 0)
	{
		printf("The balance is not broken\n");
	}
	else
	{
		printf("The balance is broken\n");
	}
	return 0;
}