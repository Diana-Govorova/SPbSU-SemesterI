#pragma once

struct ListElement;

struct List;

// Проверка на 1 элемент.
bool isSingleElement(List* list);

// Вернуть хвост.
ListElement* returnTail(List* list);

// Количество элементов.
int amountOfElements(List* list);

// Серединный элемент.
ListElement* middleElement(List* list);

// Вернуть голову.
ListElement* returnHead(List* list);

// Вернуть имя из головы.
char* returnHeadElementName(List* list);

// Вернуть номер из головы.
char* returnHeadElementNumber(List* list);

// Перенос указателя.
ListElement* pointerWrapping(ListElement* pointer);

// Создать лист.
List* createList();

// Проверка на пустоту.
bool isEmpty(List* list);

// Добавить значение.
void addValue(List* list, char* name, char* number);

// /Удалить зачение.
bool deleteValue(List* list, ListElement* current);

// Печать лста.
void printList(List* list);

// Удалить из головы.
bool deleteFromHead(List* list);

// Удалить лист.
void deleteList(List* list);

// Переписать лист.
void rewriteToNewList(List* list, List* newList, int n);