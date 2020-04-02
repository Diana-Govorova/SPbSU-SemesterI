#include <stdio.h>
#include <string.h>
#include "list.h"

struct ListElement
{
	char value[100]{};
	int quantity = 0;
	ListElement* next = nullptr;
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


void addValue(List* list, char* value)
{
	if (isEmpty(list))
	{
		list->head = new ListElement;
		list->head->quantity = 1;
		strcpy(list->head->value, value);
		return;
	}
	ListElement* currentElement = list->head;
	if (strcmp(currentElement->value, value) == 0)
	{
		currentElement->quantity++;
		return;
	}
	while (currentElement->next != nullptr && strcmp(currentElement->next->value, value) != 0)
	{
		currentElement = currentElement->next;
	}
	if (strcmp(currentElement->value, value) == 0)
	{
		currentElement->quantity++;
		return;
	}
	if ((currentElement->next == nullptr) && strcmp(currentElement->value, value) != 0)
	{
		currentElement->next = new ListElement;
		currentElement->next->quantity = 1;
		strcpy(currentElement->next->value, value);
		return;
	}
}

bool contains(List* list, char* value)
{
	ListElement* currentElement = list->head;
	while (true)
	{
		if (currentElement == nullptr)
		{
			return false;
		}
		if (strcmp(currentElement->value, value) == 0)
		{
			return true;
		}
		currentElement = currentElement->next;
	}
}

void deleteValue(List* list, char* value)
{
	if (isEmpty(list))
	{
		return;
	}
	if (strcmp(list->head->value, value) == 0)
	{
		if (list->head->quantity > 1)
		{
			list->head->quantity--;
			return;
		}
		delete list->head;
		list->head = nullptr;
		return;
	}
	ListElement* currentElement = list->head;
	while (currentElement->next != nullptr && strcmp(currentElement->next->value, value) != 0)
	{
		currentElement = currentElement->next;
	}
	if (currentElement->next != nullptr)
	{
		if (currentElement->next->quantity > 1)
		{
			currentElement->next->quantity--;
			return;
		}
		ListElement* tmp = currentElement->next;
		currentElement->next = currentElement->next->next;
		delete tmp;
		return;
	}
}

void printList(List* list)
{
	if (isEmpty(list))
	{
		return;
	}
	ListElement* current = list->head;
	while (current != nullptr)
	{
		printf("%s - %d\n", current->value, current->quantity);
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

int lengthList(List* list)
{
	if (isEmpty(list))
	{
		return 0;
	}
	int result = 0;
	ListElement* current = list->head;
	while (current != nullptr)
	{
		result++;
		current = current->next;
	}
	return result;
}

char* pop(List* list, int *quantity)
{
	char* currentValue = new char[100];
	strcpy(currentValue, list->head->value);
	*quantity = list->head->quantity;
	auto temp = list->head;
	list->head = list->head->next;
	delete temp;
	return currentValue;
}