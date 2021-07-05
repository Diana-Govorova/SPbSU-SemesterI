#pragma once

struct ListElement;

struct List;

// Создание списка.
List* createList();

// Проверка на пустоту.
bool isEmpty(List* list);

//
bool isValueInHeadEqualsTo(List* list, int number);

// Добавление значения.
void addValue(List* list, int number);

// Удаление значения.
bool deleteValue(List* list, int number);

// Печать списка.
void printList(List* list);

// Удаление списка.
void deleteList(List* list);

// Сравнение массива и списка.
bool compareListAndArray(List* list, int country[], int size);