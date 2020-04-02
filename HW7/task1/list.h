#pragma once

struct ListElement;

struct List;

//создание списка
List* createList();

//проверка списка на пустоту
bool isEmpty(List* list);

//проверка элемента в голове на совпадение
bool checkHead(List* list, int number);

//добавить значение в сортированный список
void addValue(List* list, int number);

// удалить значение из списка
bool deleteValue(List* list, int number);

//распечатать список
void printList(List* list);

//удаление списка
void deleteList(List* list);