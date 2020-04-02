#include <stdio.h>
#include "list.h"

bool test()
{
	List* list = createList();
	const bool test1Result = isEmpty(list);

	addValue(list, 34);
	addValue(list, 23);
	const bool test2Result = !isEmpty(list);

	const bool test3Result = checkHead(list, 23);

	deleteValue(list, 23);
	
	const bool test4Result = checkHead(list, 34);

	deleteList(list);

	return test1Result && test2Result && test3Result && test4Result;
}

int main()
{
	if (!test())
	{
		printf("All is bad\n");
		return -1;
	}
	List* list = createList();
	while (true)
	{
		printf("Please, enter command");
		char command = '\0';
		scanf("%c", &command);
		scanf("%*c");
		switch (command)
		{
		case '0':
		{
			printf("exit");
			deleteList(list);
			return 0;
		}
		case '1':
		{
			printf("add value to sorted list\n");
			int input = 0;
			scanf("%d", &input);
			scanf("%*c");
			addValue(list, input);
			break;
		}
		case '2':
		{
			printf("remove value from list\n");
			int input = 0;
			scanf("%d", &input);
			scanf("%*c");
			deleteValue(list, input);
			break;
		}
		case '3':
		{
			printf("print list\n");
			printList(list);
			break;
		}
		}
	}
}