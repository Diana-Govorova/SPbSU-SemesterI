#pragma once

struct HashTable;

// �������� �������.
HashTable* createTable();

// �������� �������.
void deleteTable(HashTable* table);

// ���-�������(������� ��������).
int hashFunction(HashTable* table, char* string);

// ���������� �� � �������.
bool containsInTable(HashTable* table, char* value);

// �������� �������� � �������.
void addToTable(HashTable* table, char* value);

// ������� �� �������.
void deleteFromTable(HashTable* table, char* value);

// ������ �������.
void printTable(HashTable* table);
