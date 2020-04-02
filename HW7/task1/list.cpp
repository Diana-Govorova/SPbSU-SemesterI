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
};
//�������� ������
List* createList()
{
	return new List;
}

//�������� ������ �� �������
bool isEmpty(List* list)
{
	return list->head == nullptr;
}

//���������� ����
void addValue(List* list, int number)
{
	if (isEmpty(list))
	{
		list->head = new ListElement{ number, nullptr };
		return;
	}
	ListElement* tmp = list->head;
	ListElement* last = nullptr;
	while (tmp != nullptr && number > tmp->value)
	{
		last = tmp;
		tmp = tmp->next;
	}
	if (last == nullptr)
	{
		list->head = new ListElement{ number, tmp };
	}
	else
	{
		last->next = new ListElement{ number, tmp };
	}
}

//�������� �������� � ������ �� ����������
bool checkHead(List* list, int number)
{
	return list->head->value == number;
}

//�������� ����

bool deleteValue(List* list, int number)
{
	if (isEmpty(list))
	{
		return true;
	}

	if (checkHead(list, number))
	{
		ListElement* help = list->head->next;
		delete list->head;
		list->head = help;
		return false;
	}
	ListElement* previous = nullptr;
	ListElement* tmp = list->head;
	while (tmp != nullptr && tmp->value != number) // ������������� ������ ������� � �����
	{ // ���� �� ������ ����, �������������� number
		previous = tmp;
		tmp = tmp->next;
	}
	ListElement* help = tmp->next; // ������������ ���������
	delete tmp;
	previous->next = help;
	return false;
}

//����� ��������� ������

void printList(List* list)
{
	ListElement* current = list->head;
	if (isEmpty(list))
	{
		printf("List is empty");
	}
	while (current != nullptr)
	{
		printf("%d ", current->value);
		current = current->next;
	}
}

//�������� ������
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