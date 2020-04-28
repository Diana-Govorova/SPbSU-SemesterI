#pragma once

struct ListElement;

struct List;

// �������� �� 1 �������.
bool isSingleElement(List* list);

// ������� �����.
ListElement* returnTail(List* list);

// ���������� ���������.
int amountOfElements(List* list);

// ���������� �������.
ListElement* middleElement(List* list);

// ������� ������.
ListElement* returnHead(List* list);

// ������� ��� �� ������.
char* returnHeadElementName(List* list);

// ������� ����� �� ������.
char* returnHeadElementNumber(List* list);

// ������� ���������.
ListElement* pointerWrapping(ListElement* pointer);

// ������� ����.
List* createList();

// �������� �� �������.
bool isEmpty(List* list);

// �������� ��������.
void addValue(List* list, char* name, char* number);

// /������� �������.
bool deleteValue(List* list, ListElement* current);

// ������ ����.
void printList(List* list);

// ������� �� ������.
bool deleteFromHead(List* list);

// ������� ����.
void deleteList(List* list);

// ���������� ����.
void rewriteToNewList(List* list, List* newList, int n);