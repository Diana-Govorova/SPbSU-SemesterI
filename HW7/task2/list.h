#pragma once

struct ListElement;

struct List;

// �������� ������.
List* createList();

// �������� ������ �� �������.
bool isEmpty(List* list);

// �������� �������� � ������ �� ����������.
bool checkHead(List* list, int number);

// ������� ��������� �� ���� �������.
ListElement* pointerWrapping(ListElement* pointer);

// ��������� �������� �� ����.
int gettingValue(ListElement* current);

// ������� ������ ������.
ListElement* returnHead(List* list);

// �������� �� 1 �������.
bool isSingleElement(List* list);

// �������� �������� � ������������� ������.
void addValue(List* list, int number);

// ������� �������� �� ������.
bool deleteValue(List* list, ListElement* current);

// ����������� ������.
void printList(List* list);

// �������� ������.
void deleteList(List* list);