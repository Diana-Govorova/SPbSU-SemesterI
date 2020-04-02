#pragma once

struct ListElement;

struct List;

// Создать список.
List* createList();

//Проверка на пустоту.
bool isEmpty(List* list);

//Возвращение элемента из головы.
int returnHeadElement(List* list);

//Возвращение хвоста.
ListElement* returnTail(List* list);

// Количество элементов.
int amountOfElements(List* list);

// Проверка на 1 эл-т.
bool isSingleElement(List* list);

// Добавить значение.
void addValue(List* list, int value);

// Удалить из головы.
bool deleteFromHead(List* list);

// Удалить значение
bool deleteValue(List* list, ListElement* current);

// Печать листа.
void printList(List* list);

// Удалить лист.
void deleteList(List* list);