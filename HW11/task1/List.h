#pragma once

struct ListElement;

struct List;

List* createList();

bool isEmpty(List* list);

bool checkHead(List* list, int number);

void addValue(List* list, int number);

bool deleteValue(List* list, int number);

void printList(List* list);

void deleteList(List* list);

bool compareListAndArray(List* list, int country[], int size);