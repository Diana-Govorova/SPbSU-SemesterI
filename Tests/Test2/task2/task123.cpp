#include "stdio.h"
#include "string.h"
#include "list.h"

bool compareHeads(List* list1, List* list2)
{
	return returnHeadElement(list1) <= returnHeadElement(list2);
}

List* merge(List* sortedListLeft, List* sortedListRight)
{
	List* listFinally = createList();
	while (!isEmpty(sortedListLeft) && !isEmpty(sortedListRight))
	{
		if (compareHeads(sortedListLeft, sortedListRight))
		{
			addValue(listFinally, returnHeadElement(sortedListLeft));
			deleteFromHead(sortedListLeft);
		}
		else
		{
			addValue(listFinally, returnHeadElement(sortedListRight));
			deleteFromHead(sortedListRight);
		}
	}
	while (!isEmpty(sortedListLeft))
	{
		addValue(listFinally, returnHeadElement(sortedListLeft));
		deleteFromHead(sortedListLeft);

	}
	while (!isEmpty(sortedListRight))
	{
		addValue(listFinally, returnHeadElement(sortedListRight));
		deleteFromHead(sortedListRight);
	}
	deleteList(sortedListLeft);
	deleteList(sortedListRight);
	return listFinally;
}

bool isSorted(List* list)
{
	while (!isEmpty(list) && !isSingleElement(list))
	{
		int help1 = returnHeadElement(list);
		deleteFromHead(list);
		int help2 = returnHeadElement(list);
		if (help1 <= help2)
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
	List* list1 = createList();
	List* list2 = createList();

	addValue(list1, 3);
	addValue(list1, 1);
	addValue(list1, 1);
	addValue(list1, 45);
	addValue(list2, 2);
	addValue(list2, 3);
	addValue(list2, 17);

	List* answerList = merge(list1, list2);
	const bool test1Result = isSorted(answerList);
	deleteList(answerList);
	return test1Result;
}

int main()
{
	if (!test())
	{
		printf("All is bad\n");
		return -1;
	}

	List* list1 = createList();
	List* list2 = createList();

	FILE* in1 = fopen("1list.txt", "r");
	FILE* in2 = fopen("2list.txt", "r");
	int value1 = 0;
	int value2 = 0;
	while (!feof(in1))
	{
		fscanf(in1, "%d", &value1);
		addValue(list1, value1);
	}
	while (!feof(in2))
	{
		fscanf(in2, "%d", &value2);
		addValue(list2, value2);
	}
	fclose(in1);
	fclose(in2);
	deleteFromHead(list1);
	deleteFromHead(list2);

	List* answer = merge(list1, list2);
	//printList(answer);
	int value = 0;
	FILE* file = fopen("answerList.txt", "w");

	while (!isEmpty(answer))
	{
		fprintf(file, "%d ", returnHeadElement(answer));
		deleteFromHead(answer);
	}
	fclose(file);
	deleteList(answer);
	return 0;
}