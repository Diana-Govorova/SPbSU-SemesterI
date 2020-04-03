#include <stdio.h>
#include "Algoritm.h"
#include "List.h"

void addValue(int graph[size][size], int firstVertex, int secondVertex, int length)
{
	graph[firstVertex][secondVertex] = length;
	graph[secondVertex][firstVertex] = length;
}

void readFromFile(FILE* file, int testGraph[size][size], int arrayOfCapitalsTest[], int& n, int& k)
{
	int m = 0;
	fscanf(file, "%d", &n);
	fscanf(file, "%d", &m);
	for (int l = 0; l < m; l++)
	{
		int i = 0;
		int j = 0;
		int len = 0;
		fscanf(file, "%d", &i);
		fscanf(file, "%d", &j);
		fscanf(file, "%d", &len);
		addValue(testGraph, i, j, len);
	}
	fscanf(file, "%d", &k);
	int number = 0;
	for (int i = 0; i < k; i++)
	{
		fscanf(file, "%d", &arrayOfCapitalsTest[i]);
	}
}

const bool test()
{
	int testGraph[size][size]{};
	int* arrayOfCapitalsTest = new int[size] {};
	List* countriesTest[size];
	int n = 0;
	int k = 0;
	int country0[3]{ 0, 1, 3 };
	int country2[1]{ 2 };

	FILE* fileTest = fopen("inputDataTest.txt", "r");
	readFromFile(fileTest, testGraph, arrayOfCapitalsTest, n, k);
	bool test1 = true;
	bool test2 = true;
	fclose(fileTest);
	captureOfCities(testGraph, arrayOfCapitalsTest, k, n, countriesTest);
	if (!compareListAndArray(countriesTest[0], country0,  3))
	{
		test1 = false;
	}
	if (!compareListAndArray(countriesTest[2], country2, 1))
	{
		test2 = false;
	}
	delete[] arrayOfCapitalsTest;
	deleteList(countriesTest[0]);
	deleteList(countriesTest[2]);

	return test1 && test2;
}

int main()
{

	if (!test())
	{
		printf("All is bad\n");
		return -1;
	}
	int graph[size][size]{};
	int* arrayOfCapitals = new int[size];
	int n = 0;
	int k = 0;
	FILE* file = fopen("inputData.txt", "r");
	readFromFile(file, graph, arrayOfCapitals, n , k);

	int number = 0;
	List* countries[size];

	fclose(file);
	captureOfCities(graph, arrayOfCapitals, k, n, countries);

	for (int i = 0; i < k; i++)
	{
		printf("State: ");
		printf("%d : ", arrayOfCapitals[i]);
		printList(countries[arrayOfCapitals[i]]);
		deleteList(countries[arrayOfCapitals[i]]);
		printf("\n");
	}
	delete[] arrayOfCapitals;
	return 0;
}