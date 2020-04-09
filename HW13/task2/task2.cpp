#include <stdio.h>
#include <string.h>
#include "matrix.h"

char* getComments(FILE* file, int** tableOfState, char* header, int sizeOfHeader)
{
	char* commentString = new char[1000]{};
	int i = 0;
	int currentState = 0;
	while (!feof(file))
	{
		char symbol = fgetc(file);
		int indexOfSymbol = index(header, sizeOfHeader, symbol);
		if (symbol == '\n')
		{
			commentString[i] = '\n';
			i++;
			currentState = 0;
			continue;
		}
		if (currentState == 3 && tableOfState[currentState][indexOfSymbol] == 0)
		{
			commentString[i] = '/';
			i++;
		}
		if (currentState == 1 && tableOfState[currentState][indexOfSymbol] == 2)
		{
			commentString[i] = '/';
			i++;
		}
		currentState = tableOfState[currentState][indexOfSymbol];
		if (currentState == 2 || currentState == 3)
		{
			commentString[i] = symbol;
			i++;
		}
	}
	return commentString;
}

bool test(int** tableOfState, char* header, int sizeOfColumns)
{
	FILE* testFile1 = fopen("TestInputFile1.txt", "r");
	char* commentString1 = getComments(testFile1, tableOfState, header, sizeOfColumns);
	fclose(testFile1);
	const bool test1Result = strcmp(commentString1, "/*gfv*h8*/") == 0;
	delete[] commentString1;

	FILE* testFile2 = fopen("TestInputFile2.txt", "r");
	char* commentString2 = getComments(testFile2, tableOfState, header, sizeOfColumns);
	fclose(testFile2);
	const bool test2Result = strcmp(commentString2, "/***fg*/") == 0;
	delete[] commentString2;

	return test1Result && test2Result;
}


int main()
{
	FILE* fileWithTableOfState = fopen("TableOfState.txt", "r");
	
	int sizeOfStrings = 0;
	int sizeOfColumns = 0;
	fscanf(fileWithTableOfState, "%d", &sizeOfStrings);
	fscanf(fileWithTableOfState, "%d", &sizeOfColumns);

	char* header = new char[sizeOfColumns] {};
	int** tableOfState = createMatrix(sizeOfStrings, sizeOfColumns);
	readMatrixFromFile(tableOfState, sizeOfStrings, sizeOfColumns, fileWithTableOfState, header);

	fclose(fileWithTableOfState);

	if (!test(tableOfState, header, sizeOfColumns))
	{
			printf("All is bad\n");
			return -1;
	}

	FILE* file = fopen("InputFile.txt", "r");
	char* commentString = getComments(file, tableOfState, header, sizeOfColumns);
	fclose(file);
	deleteMatrix(tableOfState, sizeOfColumns, header);
	printf("%s", commentString);
	delete[] commentString;
	return 0;
}
