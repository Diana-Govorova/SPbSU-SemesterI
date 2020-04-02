#include <stdio.h>
#include <string.h>
#include <math.h>
#include "List.h"
#include "HashTable.h"

struct HashTable
{
	int hashSize;
	int elements;
	List** hashArray = nullptr;
};

HashTable* createTable()
{
	HashTable* newTable = new HashTable{ 20 };
	newTable->hashArray = new List*[20];
	newTable->elements = 0;
	for (int i = 0; i < newTable->hashSize; ++i)
	{
		newTable->hashArray[i] = createList();
	}
	return newTable;
}

void deleteTableWithoutTable(HashTable* table)
{
	for (int i = 0; i < table->hashSize; ++i)
	{
		deleteList(table->hashArray[i]);
	}
	delete table->hashArray;
}

void deleteTable(HashTable* table)
{
	deleteTableWithoutTable(table);
	delete table;
}
int hashFunction(HashTable* table, char* string)
{
	int result = 0;
	for (int i = 0; i < strlen(string); ++i)
	{
		result = (result + string[i]) % table->hashSize;
	}
	return abs(result);
}

bool containsInTable(HashTable* table, char* value)
{
	return contains(table->hashArray[hashFunction(table, value)], value);
}

void resize(HashTable* table)
{
	List* newList = createList();
	for (int i = 0; i < table->hashSize; i++)
	{
		List* currentList = table->hashArray[i];
		while (!isEmpty(currentList))
		{
			int quantity = 0;
			char* value = pop(currentList, &quantity);
			for (int j = 0; j < quantity; j++)
			{
				addValue(newList, value);
			}
			delete[] value;
		}
	}
	deleteTableWithoutTable(table);
	table->hashSize = table->hashSize * 2;
	table->hashArray = new List * [table->hashSize];
	for (int i = 0; i < table->hashSize; ++i)
	{
		table->hashArray[i] = createList();
	}
	while (!isEmpty(newList))
	{
		int quantity = 0;
		char* value = pop(newList, &quantity);
		for (int j = 0; j < quantity; j++)
		{
			addToTable(table, value);
		}
		delete[] value;
	}
	deleteList(newList);
}

void addToTable(HashTable* table, char* value)
{
	float loadFactor = (float)table->elements / (float)table->hashSize;
	if (loadFactor > 1.2)
	{
		resize(table);
	}
	int hashValue = hashFunction(table, value);
	addValue(table->hashArray[hashValue], value);
	table->elements++;
}

void deleteFromTable(HashTable* table, char* value)
{
	if (!containsInTable(table, value))
	{
		return;
	}
	deleteValue(table->hashArray[hashFunction(table, value)], value);
}

void printTable(HashTable* table)
{
	for (int i = 0; i < table->hashSize; ++i)
	{
		printList(table->hashArray[i]);
	}
	int maxAmount = 0;
	int sumAmount = 0;
	for (int i = 0; i < table->hashSize; i++)
	{
		int amount = lengthList(table->hashArray[i]); 
		sumAmount += amount;
		if (amount > maxAmount)
		{
			maxAmount = amount;
		}
	} 
	printf("Максимальная длина списка: ");
	printf("%d\n", maxAmount);
	printf("Средняя длина списка: ");
	printf("%f\n", (float)sumAmount / (float)table->hashSize);
	printf("Коэффициент заполнения: ");
	printf("%f ", (float)table->elements / (float)table->hashSize);
}