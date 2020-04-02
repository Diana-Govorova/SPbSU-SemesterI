#pragma once

struct HashTable;

// Создание таблицы.
HashTable* createTable();

// Удаление таблицы.
void deleteTable(HashTable* table);

// Хеш-функция(подсчет значения).
int hashFunction(HashTable* table, char* string);

// Содержится ли в таблице.
bool containsInTable(HashTable* table, char* value);

// Добавить значение в таблицу.
void addToTable(HashTable* table, char* value);

// Удалить из таблицы.
void deleteFromTable(HashTable* table, char* value);

// Печать таблицы.
void printTable(HashTable* table);
