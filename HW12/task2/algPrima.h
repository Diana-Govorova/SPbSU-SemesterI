#pragma once

struct Pair
{
	int source;
	int target;
};

// Алгоритм Прима.
void algoritmPrima(int** matrix, int size, Pair answerArray[], int lengthArr);
