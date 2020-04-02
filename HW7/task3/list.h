#pragma once

struct ListElement;

struct List;

// Создание списка.
List* createList();

// Проверка списка на пустоту.
bool isEmpty(List* list);

// Элемент в середине.
ListElement* middleElement(List* list);

// Возврат головы списка(имя)
char* returnHeadElementName(List* list);

// Возврат головы списка(номер)
char* returnHeadElementNumber(List* list);

// Возврат хвоста списка.
ListElement* returnTail(List* list);

// Длина списка.
int amountOfElements(List* list);

// Элемент в середине.
ListElement* middleElement(List* list);

// Перенос указателя на след элемент.
ListElement* pointerWrapping(ListElement* pointer);

// Возврат головы списка.
ListElement* returnHead(List* list);

// Проверка на 1 элемент.
bool isSingleElement(List* list);

// Добавить значение в сортированный список.
void addValue(List* list, char* name, char* number);

//удаление головы
bool deleteFromHead(List* list);

// Удалить значение из списка.
bool deleteValue(List* list, ListElement* current);

// Распечатать список.
void printList(List* list);

// Удаление списка.
void deleteList(List* list);