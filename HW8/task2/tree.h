#pragma once

struct TreeElement;

struct Tree;

//Создать дерево.
Tree* create();

//Проверка на пустоту.
bool empty(Tree* tree);

// Возврат элемента из строки.
TreeElement* returnElement(char* string, int* position);

// Построение дерева.
Tree* buildTree(char* string);

// Нахождение значения для всего дерева.
int valueExpression(Tree* tree);

// Печать дерева.
void printTree(Tree* tree);

// Удалить дерево.
void deleteTree(Tree* tree);

// Строим число.
int buildNumber(char* string, int* position);
