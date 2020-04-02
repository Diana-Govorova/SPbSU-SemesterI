#include <stdio.h>
#include "list.h"
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

//проверка на 1 элемент
bool isSingleElement(List* list)
{
	if (isEmpty(list))
	{
		return false;
	}
	return list->head->next == nullptr;
}

// Возврат хвоста списка
ListElement* returnTail(List* list)
{
	return list->tail;
}

//длина списка
int amountOfElements(List* list)
{
	int amount = 0;
	for (ListElement* current = list->head; current != nullptr; current = current->next)
	{
		amount++;
	}
	return amount;
}

//элемент в середине
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

//возврат указателя на голову списка
ListElement* returnHead(List* list)
{
	return list->head;
}

//возврат головы списка
char* returnHeadElementName(List* list)
{
	return list->head->name;
}

char* returnHeadElementNumber(List* list)
{
	return list->head->number;
}

//перенос указателя на след элемент
ListElement* pointerWrapping(ListElement* pointer)
{
	return pointer->next;
}

//создание списка
List* createList()
{
	return new List;
}

//проверка списка на пустоту
bool isEmpty(List* list)
{
	return list->head == nullptr;
}

//добавление узла
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

//удаление узла
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

//вывод элементов списка
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
		printf("%s ", current->number);
		printf("\n");
	}
}

//удаление головы
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

//удаление списка
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