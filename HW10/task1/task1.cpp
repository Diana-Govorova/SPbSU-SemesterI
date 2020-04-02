#include <stdio.h>
#include <locale.h>
#include "hashTable.h"

bool test()
{
	HashTable* table = createTable();
	char* string1 = new char[4]{ "ret" };
	char* string2 = new char[4]{ "ret" };
	char* string3 = new char[3]{ "rt" };
	addToTable(table, string1);
	addToTable(table, string2);
	addToTable(table, string3);
	char* string4 = new char[3]{ "mn" };
	const bool test1Result = containsInTable(table, string1);
	const bool test2Result = containsInTable(table, string3);
	const bool test3Result = !containsInTable(table, string4);
	delete[] string1;
	delete[] string2;
	delete[] string3;
	delete[] string4;
	deleteTable(table);

	return test1Result && test2Result && test3Result;
}

int main()
{
	if (!test())
	{
		printf("All is bad\n");
		return -1;
	}
	setlocale(LC_ALL, "Russian");

	HashTable* table = createTable();
	char string[100];
	FILE* in = fopen("text.txt", "r");
	char* world = new char[100];
	while (!feof(in))
	{
		fscanf(in, "%s", world);
		addToTable(table, world);
	}
	delete[] world;
	fclose(in);
	printTable(table);
	deleteTable(table);
	return 0;
}