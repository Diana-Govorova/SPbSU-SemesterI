#include <stdio.h>
#include "List.h"
#include "Algoritm.h"

void algoritmDijkstra(int graph[size][size], int distance[size][size], bool used[], List* countries[], int sizeOfGraph, int currentVertex)
{
	int minDistance = maxDistance;
	int minDistanceNumber = -1;
	for (int j = 0; j < sizeOfGraph; j++)
	{
		if (minDistance > distance[currentVertex][j] && !used[j])
		{
			minDistance = distance[currentVertex][j];
			minDistanceNumber = j;
		}
	}
	if (minDistanceNumber == -1)
	{
		return;
	}
	used[minDistanceNumber] = true;
	addValue(countries[currentVertex], minDistanceNumber);
	for (int i = 0; i < sizeOfGraph; i++)
	{
		if (distance[currentVertex][i] > distance[currentVertex][minDistanceNumber] + graph[minDistanceNumber][i] && graph[minDistanceNumber][i] != 0)
		{
			distance[currentVertex][i] = distance[currentVertex][minDistanceNumber] + graph[minDistanceNumber][i];
		}
	}
}

void captureOfCities(int graph[size][size], int capitals[], int amountOfCapitals, int sizeOfGraph, List* countries[])
{
	int distance[size][size]{};
	bool used[size]{};
	for (int i = 0; i < amountOfCapitals; i++)
	{
		countries[capitals[i]] = createList();
		for (int j = 0; j < sizeOfGraph; j++)
		{
			distance[capitals[i]][j] = maxDistance;
			if (capitals[i] == j)
			{
				distance[capitals[i]][j] = 0;
			}
		}
	}
	for (int j = 0; j < sizeOfGraph; j++)
	{
		for (int i = 0; i < amountOfCapitals; i++)
		{
			algoritmDijkstra(graph, distance, used, countries, sizeOfGraph, capitals[i]);
		}
	}
}