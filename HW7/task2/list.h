#pragma once

struct ListElement;

struct List;

// Создание списка.
List* createList();

// Проверка списка на пустоту.
bool isEmpty(List* list);

// Проверка элемента в голове на совпадение.
bool checkHead(List* list, int number);

// Перенос указателя на след элемент.
ListElement* pointerWrapping(ListElement* pointer);

// Получение значение из узла.
int gettingValue(ListElement* current);

// Возврат головы списка.
ListElement* returnHead(List* list);

// Проверка на 1 элемент.
bool isSingleElement(List* list);

// Добавить значение в сортированный список.
void addValue(List* list, int number);

// Удалить значение из списка.
bool deleteValue(List* list, ListElement* current);

// Распечатать список.
void printList(List* list);

// Удаление списка.
void deleteList(List* list);