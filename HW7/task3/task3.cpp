#include <stdio.h>
#include <string.h>
#include "list.h"

enum class SortOrder
{
	byName,
	byNumber
};

bool compareHeads(List* list1, List* list2, SortOrder sortOrder)
{
	return sortOrder == SortOrder::byName 
		? strcmp(returnHeadElementName(list1), returnHeadElementName(list2)) <= 0
		: strcmp(returnHeadElementNumber(list1), returnHeadElementNumber(list2)) <= 0;
}

List* merge(List* sortedListLeft, List* sortedListRight, SortOrder sortOrder)
{
	List* listFinally = createList();
	while (!isEmpty(sortedListLeft) && !isEmpty(sortedListRight))
	{
		if (compareHeads(sortedListLeft, sortedListRight, sortOrder))
		{
			addValue(listFinally, returnHeadElementName(sortedListLeft), returnHeadElementNumber(sortedListLeft));
			deleteFromHead(sortedListLeft);
		}
		else
		{
			addValue(listFinally, returnHeadElementName(sortedListRight), returnHeadElementNumber(sortedListRight));
			deleteFromHead(sortedListRight);
		}
	}
	while (!isEmpty(sortedListLeft))
	{
		addValue(listFinally, returnHeadElementName(sortedListLeft), returnHeadElementNumber(sortedListLeft));
		deleteFromHead(sortedListLeft);

	}
	while (!isEmpty(sortedListRight))
	{
		addValue(listFinally, returnHeadElementName(sortedListRight), returnHeadElementNumber(sortedListRight));
		deleteFromHead(sortedListRight);
	}
	deleteList(sortedListLeft);
	deleteList(sortedListRight);
	return listFinally;
}


List* mergeSort(List* list, SortOrder sortOrder)
{
	if (isEmpty(list))
	{
		return createList();
	}
	if (isSingleElement(list))
	{
		List* listAnswer = createList();
		addValue(listAnswer, returnHeadElementName(list), returnHeadElementNumber(list));
		return listAnswer;
	}
	ListElement* left = returnHead(list);
	ListElement* tail = returnTail(list);
	int i = 0;
	int j = 0;
	const int leftListSize = amountOfElements(list) / 2;
	const int rightListSize = amountOfElements(list) - leftListSize;

	List* listLeft = createList();
	List* listRight = createList();
	for (i = 0; i < leftListSize; i++)
	{
		addValue(listLeft, returnHeadElementName(list), returnHeadElementNumber(list));
		deleteFromHead(list);
	}
	for (j = 0; j < rightListSize; j++)
	{
		addValue(listRight, returnHeadElementName(list), returnHeadElementNumber(list));
		deleteFromHead(list);
	}
	List* sortedListLeft = mergeSort(listLeft, sortOrder);
	List* sortedListRight = mergeSort(listRight, sortOrder);
	List* listAnswer = merge(sortedListLeft, sortedListRight, sortOrder);
	deleteList(listLeft);
	deleteList(listRight);
	return listAnswer;
}

char* getDataFromHead(List* list, SortOrder sortOrder)
{
	return sortOrder == SortOrder::byName ? returnHeadElementName(list) : returnHeadElementNumber(list);
}

bool isSorted(List* list, SortOrder sortOrder)
{
	while (!isEmpty(list) && !isSingleElement(list))
	{
		char* help1 = getDataFromHead(list, sortOrder);
		deleteFromHead(list);
		char* help2 = getDataFromHead(list, sortOrder);
		if (strcmp(help1, help2) <= 0)
		{
			deleteFromHead(list);
		}
		else
		{
			return false;
		}
	}
	return true;
}


bool test()
{
	List* list = createList();
	bool flagNumber = false;
	char name1[] = "ajd";
	char name2[] = "dfbb";
	char number1[] = "98";
	char number2[] = "85";
	addValue(list, name1, number1);
	addValue(list, name2, number2);
	List* answerNumber = mergeSort(list, SortOrder::byNumber);
	const bool test1Result = isSorted(answerNumber, SortOrder::byNumber);
	bool flagName = true;
	List* answerName = mergeSort(answerNumber, SortOrder::byName);
	const bool test2Result = isSorted(answerName, SortOrder::byName);
	deleteList(answerNumber);
	deleteList(answerName);
	deleteList(list);
	return test1Result && test2Result;
}

int main()
{
	if (!test())
	{
		printf("All is bad\n");
		return -1;
	}
	List* list = createList();
	FILE* in = fopen("PhoneBook.txt", "r");
	while (!feof(in))
	{
		char name[100];
		char number[100];
		int read = fscanf(in, "%s %s", name, number);
		if (read > 0)
		{
			addValue(list, name, number);
		}
	}
	fclose(in);
	printf("Enter desired sorting(1 - name, 0 - number)\n");
	int flag = -1;
	scanf("%d", &flag);
	SortOrder sortOrder = flag == 1 ? SortOrder::byName : SortOrder::byNumber;

	List* answer = mergeSort(list, sortOrder);
	printList(answer);
	deleteList(list);
	deleteList(answer);
	return 0;
}