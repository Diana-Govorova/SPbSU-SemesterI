#pragma once

// ������� �������.
int** createMatrix(int size);

// ������ �������.
void printMatrix(int** matrix, int size);

// ������� �������.
void deleteMatrix(int** matrix, int size);

// ��������� ������� � �����.
void readMatrixFromFile(int** matrix, int size, FILE* file);