#include <stdio.h>
#include "List.h"

struct ListElement
{
	int value;
	ListElement* next;
};

struct List
{
	ListElement* head = nullptr;
};

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
		return;
	}
	ListElement* tmp1 = nullptr;
	ListElement* tmp2 = list->head;
	while (tmp2 != nullptr)
	{
		tmp1 = tmp2;
		tmp2 = tmp2->next;
	}
	tmp1->next = new ListElement{ value, tmp2 };
}

bool checkHead(List* list, int number)
{
	return list->head->value == number;
}

bool deleteValue(List* list, int value)
{
	if (isEmpty(list))
	{
		return true;
	}

	if (checkHead(list, value))
	{
		ListElement* help = list->head->next;
		delete list->head;
		list->head = help;
		return false;
	}
	ListElement* nxt = list->head;
	ListElement* tmp = list->head;
	while (tmp != nullptr)
	{
		if (value == tmp->value)
		{
			ListElement* help = tmp->next;
			delete tmp;
			nxt->next = help;
			break;
		}
		nxt = tmp;
		tmp = tmp->next;
	}
}
		
void printList(List* list)
{
	ListElement* current = list->head;
	if (isEmpty(list))
	{
		printf("List is empty");
	}
	while (current != nullptr)
	{
		printf("%d ", current->value );
		current = current->next;
	}
}

void deleteList(List* list)
{
	while (!isEmpty(list))
	{
		ListElement* help = list->head->next;
		delete list->head;
		list->head = help;
	}
	delete list;
}

bool compareListAndArray(List* list, int country[], int size)
{
	if (isEmpty(list))
	{
		return false;
	}
	ListElement* helpElement = list->head;
	for (int i = 0; i < size; i++)
	{
		if (helpElement->value != country[i])
		{
			return false;
		}
		helpElement = helpElement->next;
		if (helpElement == nullptr && i != size - 1)
		{
			return false;
		}
	}
	return true;
}