#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

enum class SortOrder
{
	byName,
	byNumber
};

bool compareHeads(List* list1, List* list2, SortOrder sortOrder)
{
	if (sortOrder == SortOrder::byName)
	{
		return strcmp(returnHeadElementName(list1), returnHeadElementName(list2)) <= 0;
	}
	else
	{
		return atoi(returnHeadElementNumber(list1)) <= atoi(returnHeadElementNumber(list2));
	}
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

int main()
{
	List* list = createList();
	FILE* in = fopen("ListOfMembers.txt", "r");
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
	
	List* sortedListByNumber = mergeSort(list, SortOrder::byNumber);
	List* listOfExecutedMembers = createList();
	printf("Enter numbers of member to be shot: ");
	int n = 0;
	scanf("%d", &n);
	rewriteToNewList(sortedListByNumber, listOfExecutedMembers, n);
	List* sortedListByName = mergeSort(sortedListByNumber, SortOrder::byName);
	List* listOfSendedMembers = createList();

	printf("Enter numbers of member sent to Siberia: ");
	int m = 0;
	scanf("%d", &m);
	rewriteToNewList(sortedListByName, listOfSendedMembers, m);
	printf("List of executed members: \n");
	printList(listOfExecutedMembers);
	printf("List of sended members: \n");
	printList(listOfSendedMembers);
	printf("List of living members: \n");
	printList(sortedListByName);

	deleteList(list);
	deleteList(sortedListByNumber);
	deleteList(listOfExecutedMembers);
	deleteList(listOfSendedMembers);
	deleteList(sortedListByName);

	return 0;
}