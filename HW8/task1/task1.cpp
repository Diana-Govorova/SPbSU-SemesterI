#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

void openMenu(int helpCommand)
{
	if (helpCommand == 5)
	{
		printf("Enter 0 to exit\n");
		printf("Enter 1 to add value to vocabulary\n");
		printf("Enter 2 to get value from vocabulary\n");
		printf("Enter 3 to check value in vocabulary\n");
		printf("Enter 4 to delete value from vocabulary\n");
	}
}

bool test()
{
	Tree* tree = create();
	char* value1 = new char[4]{ "abc" };
	char* value2 = new char[2]{ "c" };
	TreeElement* parent1 = nullptr;
	TreeElement* parent2 = nullptr;
	push(tree, 23, value1);
	push(tree, 44, value2);
	const bool test1Result = !empty(tree);
	const bool test2Result = elementAvailability(tree, 44, &parent1);
	const bool test3Result = strcmp("abc", returnValue(searchElement(tree, 23, &parent2))) == 0;
	deleteTree(tree);

	return test1Result && test2Result && test3Result;
}

int main()
{
	if (!test())
	{
		printf("All is bad\n");
		return -1;
	}
	Tree* tree = create();
	int helpCommand = -1;
	printf("Enter 5 to open menu\n");
	scanf("%d", &helpCommand);
	scanf("%*c");
	openMenu(helpCommand);
	while (true)
	{
		printf("Please, enter command\n");
		char command = '\0';
		scanf("%c", &command);
		scanf("%*c");
		if (!isdigit(command))
		{
			printf("Command is not found");
			continue;
		}
		switch (command)
		{
			case '0':
			{
				deleteTree(tree);
				return 0;
			}
			case '1':
			{
				printf("add value to vocabulary\n");
				int key = 0;
				char* value = new char[100];
				printf("add value to vocabulary key\n");
				scanf("%d", &key);
				printf("add value to vocabulary value\n");
				scanf("%s", value);
				scanf("%*c");
				push(tree, key, value);
				break;
			}
			case '2':
			{
				printf("get value from vocabulary\n");
				int key = 0;
				scanf("%d", &key);
				scanf("%*c");
				TreeElement* parent = nullptr;
				if (searchElement(tree, key, &parent) != nullptr)
				{
					char* answer = returnValue(searchElement(tree, key, &parent));
					printf("%s", answer);
				}
				else
				{
					printf("Element doesnt contains in vocabulary\n");
				}
				break;
			}
			case '3':
			{
				printf("check value in vocabulary\n");
				int key = 0;
				scanf("%d", &key);
				scanf("%*c");
				TreeElement* parent = nullptr;
				if (elementAvailability(tree, key, &parent))
				{
					printf("Element contains in vocabulary\n");
				}
				else
				{
					printf("Element doesnt contains in vocabulary\n");
				}
				break;
			}
			case '4':
			{
				printf("delete value from vocabulary\n");
				int key = 0;
				scanf("%d", &key);
				scanf("%*c");
				deleteElement(tree, key);
				break;
			}
		}
	}
}