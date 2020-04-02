#include <stdio.h>
#include "list.h"

typedef struct ListElement
{
	int value;
	struct ListElement* next;
};

struct List
{
	ListElement* head = nullptr;
	ListElement* tail = nullptr;
};

//проверка на 1 элемент
bool isSingleElement(List* list)
{
	return list->head == list->head->next;
}

//возврат головы списка
ListElement* returnHead(List* list)
{
	return list->head;
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
void addValue(List* list, int number)
{
	if (isEmpty(list))
	{
		list->head = new ListElement{ number, nullptr };
		list->tail = list->head;
		list->head->next = list->head;
		return;
	}
	list->tail->next = new ListElement{ number, list->head };
	list->tail = list->tail->next;
}

//проверка элемента в голове на совпадение
bool checkHead(List* list, int number)
{
	return list->head->value == number;
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
	delete current->next;
	current->next = help;
}

//вывод элементов списка
void printList(List* list)
{
	ListElement* current = list->head;
	if (isEmpty(list))
	{
		printf("List is empty");
		return;
	}
	printf("%d ", current->value);
	for (ListElement* current = list->head->next; current != list->head; current = current->next)
	{
		printf("%d ", current->value);
	}
}

//получение значение из узла
int gettingValue(ListElement* current)
{
	return current->value;
}

//удаление списка
void deleteList(List* list)
{
	if (!isEmpty(list))
	{
		while (list->head != list->head->next)
		{
			ListElement* help = list->head->next;
			delete list->head;
			list->head = help;
		}
		delete list->head;
	}
	delete list;
}