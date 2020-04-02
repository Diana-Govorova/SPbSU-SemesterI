#pragma once

struct TreeElement;

struct Tree;

//������� ������.
Tree* create();

//�������� �� �������.
bool empty(Tree* tree);

// ������� �������� �� ������.
TreeElement* returnElement(char* string, int* position);

// ���������� ������.
Tree* buildTree(char* string);

// ���������� �������� ��� ����� ������.
int valueExpression(Tree* tree);

// ������ ������.
void printTree(Tree* tree);

// ������� ������.
void deleteTree(Tree* tree);

// ������ �����.
int buildNumber(char* string, int* position);
