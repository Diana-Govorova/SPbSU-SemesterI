#include <stdio.h>
#include "list.h"
#include <string.h>

struct ListElement
{
	int value;
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
	return list->head->value;
}

int returnHeadElement(List* list)
{
	return list->head->value;
}

List* createList()
{
	return new List;
}

bool isEmpty(List* list)
{
	return list->head == nullptr;
}

void addValue(List* list, int value)
{
	if (isEmpty(list))
	{
		list->head = new ListElement{ value, nullptr };
		list->tail = list->head;
		return;
	}
	list->tail->next = new ListElement{ value, nullptr };
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
		printf("%d ", current->value);
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
			delete list->head;
			list->head = help;
		}
	}
	delete list;
}
