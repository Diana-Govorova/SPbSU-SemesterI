#pragma once

struct ListElement;

struct List;

// �������� ������.
List* createList();

// �������� ������ �� �������.
bool isEmpty(List* list);

// ������� � ��������.
ListElement* middleElement(List* list);

// ������� ������ ������(���)
char* returnHeadElementName(List* list);

// ������� ������ ������(�����)
char* returnHeadElementNumber(List* list);

// ������� ������ ������.
ListElement* returnTail(List* list);

// ����� ������.
int amountOfElements(List* list);

// ������� � ��������.
ListElement* middleElement(List* list);

// ������� ��������� �� ���� �������.
ListElement* pointerWrapping(ListElement* pointer);

// ������� ������ ������.
ListElement* returnHead(List* list);

// �������� �� 1 �������.
bool isSingleElement(List* list);

// �������� �������� � ������������� ������.
void addValue(List* list, char* name, char* number);

//�������� ������
bool deleteFromHead(List* list);

// ������� �������� �� ������.
bool deleteValue(List* list, ListElement* current);

// ����������� ������.
void printList(List* list);

// �������� ������.
void deleteList(List* list);