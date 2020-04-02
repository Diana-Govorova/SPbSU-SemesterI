#pragma once

struct ListElement;

struct List;

// Создание списка.
List* createList();

// Проверка на пустоту.
bool isEmpty(List* list);

// Содержится ли.
bool contains(List* list, char* value);

// Добавление значения в список
void addValue(List* list, char* value);

// Удаление значения.
void deleteValue(List* list, char* value);

// Печать списка.
void printList(List* list);

// Удаление списка
void deleteList(List* list);

// Длина списка
int lengthList(List* list);

//
char* pop(List* list, int* quantity);