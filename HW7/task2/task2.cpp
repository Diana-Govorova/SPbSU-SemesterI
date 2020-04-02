#include <stdio.h>
#include "list.h"
#include <locale.h>

int kill(int n, int m)
{
	List* list = createList();
	for (int i = 0; i < n; i++)
	{
		int number = i + 1;
		addValue(list, number);
	}
	ListElement* help = returnHead(list);
	while (!isSingleElement(list))
	{
		for (int i = 0; i < m - 2; i++)
		{
			help = pointerWrapping(help);
		}
		deleteValue(list, help);
		help = pointerWrapping(help);
	}
	int tmp = gettingValue(help);
	deleteList(list);
	return tmp;
}

bool test()
{
	const bool test1Result = kill(5, 2) == 3;

	const bool test2Result = kill(6, 3) == 1;

	return test1Result && test2Result;

}
int main()
{
	if (!test())
	{
		printf("All is bad\n");
		return -1;
	}
	setlocale(LC_ALL, "Russian");
	printf("Введите количество воинов\n");
	int n = 0;
	scanf("%d", &n);
	printf("Введите число через сколько убивают\n");
	int m = 0;
	scanf("%d", &m);
	printf("Останется последним воин под номером:\n");
	printf("%d", kill(n, m));
	return 0;
}