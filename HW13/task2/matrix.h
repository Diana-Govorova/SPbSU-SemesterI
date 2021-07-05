#pragma once

// �������� �������.
int** createMatrix(int sizeOfString, int sizeOfColumns);

// ������ �������.
void printMatrix(int** matrix, int sizeOfString, int sizeOfColumns);

// �������� �������.
void deleteMatrix(int** matrix, int sizeOfString, char* header);

// ������ ������� �� �����.
void readMatrixFromFile(int** matrix, int sizeOfString, int sizeOfColumns, FILE* file, char* header);

// �������� ������ ���������� �� ������� ����������.
int index(char* array, int size, char symbol);
