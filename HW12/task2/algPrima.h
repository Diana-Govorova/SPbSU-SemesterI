#pragma once

struct Pair
{
	int source;
	int target;
};

// �������� �����.
void algoritmPrima(int** matrix, int size, Pair answerArray[], int lengthArr);
