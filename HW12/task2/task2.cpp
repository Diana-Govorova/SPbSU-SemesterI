#include <stdio.h>
#include "algPrima.h"
#include "matrix.h"



bool compareOfArray(Pair array1[], Pair array2[], int length1, int length2)
{
	if (length1 != length2)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < length1; i++)
		{
			if (array1[i].source != array2[i].source || array1[i].target != array2[i].target)
			{
				return false;
			}
		}
		return true;
	}
}

bool test()
{
	int size = 5;
	int** matrix = createMatrix(size);
	FILE* file = fopen("matrixTest.txt", "r");
	readMatrixFromFile(matrix, size, file);
	fclose(file);
	Pair* array = new Pair[4];
	algoritmPrima(matrix, 5, array, 8);
	Pair givenArray[4]{ Pair{0, 1},Pair{ 1, 2}, Pair{1, 4}, Pair{2, 3} };
	const bool test1Result = compareOfArray(givenArray, array, 4, 4);
	deleteMatrix(matrix, size);
	delete[] array;

	return test1Result;
}


int main()
{
	if (!test())
	{
		printf("All is bad\n");
		return -1;
	}
	int size = 0;
	FILE* file = fopen("matrix.txt", "r");
	fscanf(file, "%d", &size);
	int** matrix = createMatrix(size);

	readMatrixFromFile(matrix, size, file);
	fclose(file);
	Pair* array = new Pair[1000] {};
	int lengthOfArray = size - 1;
	algoritmPrima(matrix, size, array, lengthOfArray);
	for (int i = 0; i < lengthOfArray; i++)
	{
		printf("%d, %d", array[i].source, array[i].target);
		printf("\n");

	}
	deleteMatrix(matrix, size);
	delete[] array;
	return 0;
}