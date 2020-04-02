#include <stdio.h>
#include "matrix.h"

int** createMatrix(int sizeOfString, int sizeOfColumns)
{
	int** matrix = new int* [sizeOfString] {};
	for (int i = 0; i < sizeOfString; ++i)
	{
		matrix[i] = new int[sizeOfColumns] {};
	}
	return matrix;
}

void printMatrix(int** matrix, int sizeOfString, int sizeOfColumns)
{
	for (int i = 0; i < sizeOfString; ++i)
	{
		for (int j = 0; j < sizeOfColumns; ++j)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void deleteMatrix(int** matrix, int sizeOfString, char* header)
{
	for (int i = 0; i < sizeOfString; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] header;
}

void readMatrixFromFile(int** matrix, int sizeOfString, int sizeOfColumns, FILE* file, char* header)
{
	int i = 0;
	while (i < sizeOfColumns)
	{
		char tmp = ' ';
		fscanf(file, "%c", &tmp);
		if (tmp == ' ' || tmp == '\n')
		{
			continue;
		}
		header[i] = tmp;
		i++;
	}

	int j = 0;
	while (j < sizeOfString)
	{
		int tmp = 0;
		fscanf(file, "%d", &tmp);
		int k = 0;
		while (k < sizeOfColumns)
		{
			fscanf(file, "%d", &tmp);
			matrix[j][k] = tmp;
			k++;
		}
		j++;
	}
}

int index(char* array, int size, char symbol)
{
	for (int i = 0; i < size - 1; ++i)
	{
		if (array[i] == symbol)
		{
			return i;
		}
	}
	return size - 1;
}