#pragma once

struct TreeElement;

struct Tree;

//������� ������.
Tree* create();

//�������� �� �������.
bool empty(Tree* tree);

//�������� �������.
void push(Tree* tree, int key, char* value);

// ��������� �������� ��������.
char* returnValue(TreeElement* element);

// ����� �������a
TreeElement* searchElement(Tree* tree, int key, TreeElement** parent);

// �������� ������� ��������.
bool elementAvailability(Tree* tree, int key, TreeElement** parent);

// �������� ��������.
void deleteElement(Tree* tree, int key);

// ������� ������.
void deleteTree(Tree* tree);
