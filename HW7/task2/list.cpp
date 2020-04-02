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

//�������� �� 1 �������
bool isSingleElement(List* list)
{
	return list->head == list->head->next;
}

//������� ������ ������
ListElement* returnHead(List* list)
{
	return list->head;
}

//������� ��������� �� ���� �������
ListElement* pointerWrapping(ListElement* pointer)
{
	return pointer->next;
}

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
		list->tail = list->head;
		list->head->next = list->head;
		return;
	}
	list->tail->next = new ListElement{ number, list->head };
	list->tail = list->tail->next;
}

//�������� �������� � ������ �� ����������
bool checkHead(List* list, int number)
{
	return list->head->value == number;
}

//�������� ����
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

//����� ��������� ������
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

//��������� �������� �� ����
int gettingValue(ListElement* current)
{
	return current->value;
}

//�������� ������
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