#pragma once

struct TreeElement;

struct Tree;

//Создать дерево.
Tree* create();

//Проверка на пустоту.
bool empty(Tree* tree);

//Добавить элемент.
void push(Tree* tree, int key, char* value);

// Получение значения элемента.
char* returnValue(TreeElement* element);

// Поиск элементa
TreeElement* searchElement(Tree* tree, int key, TreeElement** parent);

// Проверка наличия элемента.
bool elementAvailability(Tree* tree, int key, TreeElement** parent);

// Удаление элемента.
void deleteElement(Tree* tree, int key);

// Удалить дерево.
void deleteTree(Tree* tree);
