#include <stdio.h>
#include "linkedList.h"
#include <string.h>

struct ListElement
{
	char* name;
	char* number;
	ListElement* next;
};

struct List
{
	ListElement* head = nullptr;
	ListElement* tail = nullptr;
};

bool isSingleElement(List* list)
{
	if (isEmpty(list))
	{
		return false;
	}
	return list->head->next == nullptr;
}

ListElement* returnTail(List* list)
{
	return list->tail;
}

int amountOfElements(List* list)
{
	int amount = 0;
	for (ListElement* current = list->head; current != nullptr; current = current->next)
	{
		amount++;
	}
	return amount;
}

ListElement* middleElement(List* list)
{
	const int length = amountOfElements(list) / 2;
	ListElement* current = list->head;
	for (int i = 0; i < length; i++)
	{
		current = current->next;
	}
	return current;
}

ListElement* returnHead(List* list)
{
	return list->head;
}

char* returnHeadElementName(List* list)
{
	return list->head->name;
}

char* returnHeadElementNumber(List* list)
{
	return list->head->number;
}

ListElement* pointerWrapping(ListElement* pointer)
{
	return pointer->next;
}

List* createList()
{
	return new List;
}

bool isEmpty(List* list)
{
	return list->head == nullptr;
}

void addValue(List* list, char* name, char* number)
{
	char* copyName = new char[100];
	strcpy(copyName, name);
	char* copyNumber = new char[100];
	strcpy(copyNumber, number);
	if (isEmpty(list))
	{
		list->head = new ListElement{ copyName, copyNumber, nullptr };
		list->tail = list->head;
		return;
	}
	list->tail->next = new ListElement{ copyName, copyNumber, nullptr };
	list->tail = list->tail->next;
}

bool deleteValue(List* list, ListElement* current)
{
	if (isEmpty(list))
	{
		return true;
	}
	if (current->next == list->head)
	{
		list->head = list->head->next;
	}
	ListElement* help = current->next->next;
	delete current->next->name;
	delete current->next->number;
	delete current->next;
	current->next = help;
}

void printList(List* list)
{
	if (isEmpty(list))
	{
		printf("List is empty");
		return;
	}
	for (ListElement* current = list->head; current != nullptr; current = current->next)
	{
		printf("%s ", current->name);
		//printf("%s ", current->number);
		printf("\n");
	}
}

bool deleteFromHead(List* list)
{
	if (isEmpty(list))
	{
		return true;
	}
	ListElement* help = list->head->next;
	delete list->head->name;
	delete list->head->number;
	delete list->head;
	list->head = help;
}

void deleteList(List* list)
{
	if (!isEmpty(list))
	{
		while (list->head != nullptr)
		{
			ListElement* help = list->head->next;
			delete list->head->name;
			delete list->head->number;
			delete list->head;
			list->head = help;
		}
	}
	delete list;
}

void rewriteToNewList(List* list, List* newList, int n)
{
	for (int i = 0; i < n; i++)
	{
		ListElement* tmp = list->head;
		addValue(newList, tmp->name, tmp->number);
		deleteFromHead(list);
	}
}