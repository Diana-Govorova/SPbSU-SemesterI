#include <stdio.h>
#include "matrix.h"
#include "algPrima.h"


void algoritmPrima(int** matrix, int size, Pair answerArray[], int lengthArr)
{
	const int infinity = 2000000000; // значение "бесконечность"
	bool* used = new bool[size] {};
	int* minWeightEdge = new int[size] {};
	int* endOfMinEdge = new int[size] {};
	// алгоритм
	for (int i = 0; i < size; i++)
	{
		used[i] = false;
		minWeightEdge[i] = infinity;
		endOfMinEdge[i] = -1;
	}
	minWeightEdge[0] = 0;
	int k = 0;
	for (int i = 0; i < size; ++i)
	{
		int v = -1;
		for (int j = 0; j < size; ++j)
		{
			if (!used[j] && (v == -1 || minWeightEdge[j] < minWeightEdge[v]))
			{
				v = j;
			}
		}
		if (minWeightEdge[v] == infinity)
		{
			printf("error");
			return;
		}

		used[v] = true;
		if (endOfMinEdge[v] != -1)
		{
			answerArray[k] = Pair{endOfMinEdge[v] , v};
			k++;
		}
		for (int to = 0; to < size; ++to)
		{
			if ((matrix[v][to] > 0) && (matrix[v][to] < minWeightEdge[to]))
			{
				minWeightEdge[to] = matrix[v][to];
				endOfMinEdge[to] = v;
			}
		}
	}
}