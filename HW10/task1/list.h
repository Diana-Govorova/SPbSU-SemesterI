#pragma once

struct ListElement;

struct List;

// �������� ������.
List* createList();

// �������� �� �������.
bool isEmpty(List* list);

// ���������� ��.
bool contains(List* list, char* value);

// ���������� �������� � ������
void addValue(List* list, char* value);

// �������� ��������.
void deleteValue(List* list, char* value);

// ������ ������.
void printList(List* list);

// �������� ������
void deleteList(List* list);

// ����� ������
int lengthList(List* list);

//
char* pop(List* list, int* quantity);