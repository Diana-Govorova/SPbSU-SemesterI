#include <stdio.h>
#include "matrix.h"

int** createMatrix(int size)
{
	int** matrix = new int* [size] {};
	for (int i = 0; i < size; ++i)
	{
		matrix[i] = new int[size] {};
	}
	return matrix;
}

void printMatrix(int** matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void deleteMatrix(int** matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		delete[] matrix[i];
	}
	delete matrix;
}

void readMatrixFromFile(int** matrix, int size, FILE* file)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			fscanf(file, "%d", &matrix[i][j]);
		}
	}
}